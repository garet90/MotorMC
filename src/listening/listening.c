#include "listening.h"
#include "../motor.h"
#include "../jobs/board.h"
#include "../jobs/jobs.h"
#include "../jobs/scheduler/scheduler.h"
#include "../util/util.h"
#include "../io/logger/logger.h"
#include "../io/io.h"
#include "../io/chat/chat.h"
#include "../io/chat/translation.h"

// packet handlers
#include "phd/handshake.h"
#include "phd/status.h"
#include "phd/login.h"
#include "phd/play.h"

void ltg_init() {

	log_info("Starting listener...");

	// generate RSA keypair
	cry_rsa_gen_key_pair(&sky_main.listener.keypair);

	// start listening thread
	pthread_create(&sky_main.listener.thread, NULL, t_ltg_run, NULL);

}

void* t_ltg_run(void* input) {

	// init sockets
	if (sck_init() != SCK_OK) {
		return NULL;
	}

	// create socket
	sky_main.listener.address.socket = sck_create();

	// set address
	sky_main.listener.address.addr.sin_family = AF_INET;
	sky_main.listener.address.addr.sin_addr.s_addr = INADDR_ANY;
	sky_main.listener.address.addr.sin_port = io_htons(sky_main.listener.address.port);

	// bind socket
	if (sck_bind(sky_main.listener.address.socket, (struct sockaddr*) &sky_main.listener.address.addr, sizeof(struct sockaddr)) != SCK_OK) {
		return NULL;
	}

	// listen
	if (sck_listen(sky_main.listener.address.socket) != SCK_OK) {
		return NULL;
	}
	log_info("Listening on port %u", sky_main.listener.address.port);

	for (;;) {

		// forever

		int32_t socket;
		struct sockaddr_in address;
		int address_size = sizeof(struct sockaddr_in);
		socket = sck_accept(sky_main.listener.address.socket, (struct sockaddr*) &address, &address_size);

		if (socket == SCK_FAILED) {

			// something failed when connecting a client
			break;

		} else {

			// allocate new client and set address and socket
			ltg_client_t* client = calloc(1, sizeof(ltg_client_t));
			client->socket = socket;
			client->address.addr = address;
			client->address.size = address_size;
			client->state = ltg_handshake;
			client->keep_alive = -1;

			// accept the client
			ltg_accept(client);

		}
	}

	return input;

}

void ltg_accept(ltg_client_t* client) {

	// lock clients
	pthread_mutex_lock(&sky_main.listener.clients.lock);

	client->id = utl_id_vector_add(&sky_main.listener.clients.vector, &client);
	
	pthread_mutex_unlock(&sky_main.listener.clients.lock);

	// create client listening thread
	pthread_create(&client->thread, NULL, t_ltg_client, client);

}

void* t_ltg_client(void* args) {

	ltg_client_t* client = args;

	// create receive packet (on stack)
	PCK_INLINE(recvd, LTG_MAX_RECIEVE, io_big_endian);

	for (;;) {

		// receive packet
		recvd->length = sck_recv(client->socket, (char*) recvd->bytes, LTG_MAX_RECIEVE);

		if ((int32_t) recvd->length <= 0) {
			// client disconnected
			break;
		} else {
			// handle packet
			recvd->cursor = 0;

			if (client->encryption.enabled) {
				cfb8_decrypt(recvd->bytes, recvd->bytes, recvd->length, &client->encryption.decrypt);
			}

			if (!ltg_handle_packet(client, recvd)) {
				break;
			}

		}
	}

	ltg_disconnect(client);

	return NULL;
}

ltg_client_t* ltg_get_client_by_id(uint32_t id) {

	pthread_mutex_lock(&sky_main.listener.clients.lock);

	ltg_client_t* client = UTL_ID_VECTOR_GET_AS(ltg_client_t*, &sky_main.listener.clients.vector, id);

	pthread_mutex_unlock(&sky_main.listener.clients.lock);

	return client;

}

/*
 * Handle packets
 * If return is false, disconnect the client
 */
bool_t ltg_handle_packet(ltg_client_t* client, pck_packet_t* packet) {

	do {
		switch (client->state) {
		case ltg_handshake:
			if (!phd_handshake(client, packet)) {
				return false;
			}
			break;
		case ltg_status:
			if (!phd_status(client, packet)) {
				return false;
			}
			break;
		case ltg_login:
			if (!phd_login(client, packet)) {
				return false;
			}
			break;
		case ltg_play:
			if (!phd_play(client, packet)) {
				return false;
			}
			break;
		default:
			log_warn("Client is in an unknown state! (%d)", client->state);
			return false;
		}
	} while (packet->cursor != packet->length);

	return true;

}

// sends the packet to the client specified
void ltg_send(ltg_client_t* client, pck_packet_t* packet) {

	size_t length = packet->cursor;
	const size_t length_length = io_var_int_length(length);
	byte_t* bytes = packet->bytes - length_length;
	io_write_var_int(bytes, length);
	length += length_length;

	if (client->encryption.enabled) {

		// encrypt packet
		byte_t encrypted[length];

		cfb8_encrypt(bytes, encrypted, length, &client->encryption.encrypt);

		sck_send(client->socket, (char*) encrypted, length);

	} else {
		sck_send(client->socket, (char*) bytes, length);
	}

}

void ltg_disconnect(ltg_client_t* client) {

	if (pthread_self() != client->thread) {
		sck_shutdown(client->socket);
		return;
	}
		
	sck_shutdown(client->socket);

	// cancel keep alive
	sch_cancel(client->keep_alive);

	// if we're on the online players list, remove it
	if (client->online_node != NULL) {

		pthread_mutex_lock(&sky_main.listener.online.lock);

		utl_list_doubly_remove_by_reference(&sky_main.listener.online.list, client->online_node);

		pthread_mutex_unlock(&sky_main.listener.online.lock);

		JOB_CREATE_WORK(work, job_player_leave);
		memcpy(work->uuid, client->uuid, sizeof(ltg_uuid_t));
		
		work->username = client->username;

		job_add(&work->header);

	}

	// free entity
	if (client->entity != NULL) {
		ent_free_entity((ent_entity_t*) client->entity);
	}

	sck_close(client->socket);

	// lock clients
	pthread_mutex_lock(&sky_main.listener.clients.lock);

	utl_id_vector_remove(&sky_main.listener.clients.vector, client->id);
	
	pthread_mutex_unlock(&sky_main.listener.clients.lock);
	
	// free skin
	if (client->textures.value.value != NULL) {
		free(client->textures.value.value);
	}
	if (client->textures.signature.value != NULL) {
		free(client->textures.signature.value);
	}

	// free encryption key
	if (client->encryption.enabled) {
		cfb8_done(&client->encryption.encrypt);
		cfb8_done(&client->encryption.decrypt);
	}

	free(client);

}

void ltg_term() {

	// cancel main thread
	sck_close(sky_main.listener.address.socket);
	pthread_cancel(sky_main.listener.thread);

	pthread_mutex_lock(&sky_main.listener.clients.lock);

	// disconnect message
	cht_translation_t disconnect_message = cht_translation_new;
	disconnect_message.translate = cht_translation_multiplayer_disconnect_server_shutdown;

	char message[128];
	size_t message_length = cht_write_translation(&disconnect_message, message);

	// disconnect all clients
	for (uint32_t i = 0; i < sky_main.listener.clients.vector.size; ++i) {
		ltg_client_t* client = UTL_ID_VECTOR_GET_AS(ltg_client_t*, &sky_main.listener.clients.vector, i);
		if (client != NULL) {
			pthread_mutex_unlock(&sky_main.listener.clients.lock);
			phd_send_disconnect(client, message, message_length);
			ltg_disconnect(client);
			if (pthread_self() != client->thread) {
				pthread_join(client->thread, NULL);
			}
			pthread_mutex_lock(&sky_main.listener.clients.lock);
		}
	}

	sck_term();

}