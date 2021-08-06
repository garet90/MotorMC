#include "listening.h"
#include "../motor.h"
#include "../jobs/board.h"
#include "../util/util.h"
#include "../io/logger/logger.h"
#include "../io/io.h"

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
		int addressSize = sizeof(struct sockaddr_in);
		socket = sck_accept(sky_main.listener.address.socket, (struct sockaddr*) &address, &addressSize);

		if (socket == SCK_FAILED) {

			// something failed when connecting a client
			break;

		} else {

			// allocate new client and set address and socket
			ltg_client_t* client = calloc(1, sizeof(ltg_client_t));
			client->socket = socket;
			client->address.addr = address;
			client->address.size = addressSize;
			client->state = ltg_handshake;

			// accept the client
			ltg_accept(client);

		}
	}

	return input;

}

void ltg_accept(ltg_client_t* client) {

	// lock clients
	pthread_mutex_lock(&sky_main.listener.clients.lock);

	if (sky_main.listener.clients.next_id.size > 0) {

		// allocate to next client id

		client->id = UTL_VECTOR_GET_AS(uint32_t, &sky_main.listener.clients.next_id, 0);

		// replace first with last and decrement size
		if (sky_main.listener.clients.next_id.size > 1) {
			uint32_t lastCLID = UTL_VECTOR_GET_AS(uint32_t, &sky_main.listener.clients.next_id, sky_main.listener.clients.next_id.size - 1);
			utl_vector_set(&sky_main.listener.clients.next_id, 0, &lastCLID);
		}

		sky_main.listener.clients.next_id.size -= 1;

		// set the client to the id
		utl_vector_set(&sky_main.listener.clients.vector, client->id, &client);

	} else {

		// allocate at end of array

		client->id = sky_main.listener.clients.vector.size;

		utl_vector_push(&sky_main.listener.clients.vector, &client);

	}

	pthread_mutex_unlock(&sky_main.listener.clients.lock);

	// create client listening thread
	pthread_create(&client->thread, NULL, t_ltg_client, client);

}

void* t_ltg_client(void* args) {

	ltg_client_t* client = args;

	// create receive packet (on stack)
	PCK_INLINE(recvd, LTG_MAX_RECIEVE, IO_BIG_ENDIAN);
	int32_t recvl = 0;

	for (;;) {

		// receive packet
		recvl = sck_recv(client->socket, (char*) recvd->bytes, LTG_MAX_RECIEVE);

		if (recvl <= 0) {
			// client disconnected
			break;
		} else {
			// handle packet
			recvd->length = recvl;
			recvd->cursor = 0;

			if (client->encryption.enabled) {
				cfb8_decrypt(recvd->bytes, recvd->bytes, recvl, &client->encryption.key);
			}

			if (!ltg_handle_packet(client, recvd)) {
				break;
			}

		}
	}

	ltg_disconnect(client);

	return NULL;
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
	size_t length_length = io_var_int_length(length);
	byte_t* bytes = packet->bytes - length_length;
	io_write_var_int(bytes, length);
	length += length_length;

	if (client->encryption.enabled) {

		// encrypt packet
		byte_t encrypted[length];

		cfb8_encrypt(bytes, encrypted, length, &client->encryption.key);

		sck_send(client->socket, (char*) encrypted, length);

	} else {
		sck_send(client->socket, (char*) bytes, length);
	}

}

void ltg_disconnect(ltg_client_t* client) {

	sck_close(client->socket);

	// lock clients
	pthread_mutex_lock(&sky_main.listener.clients.lock);

	void* null = NULL;

	// push id to next id stack and set last client to NULL
	utl_vector_push(&sky_main.listener.clients.next_id, &client->id);
	utl_vector_set(&sky_main.listener.clients.vector, client->id, &null);

	pthread_mutex_unlock(&sky_main.listener.clients.lock);

	// free the username
	if (client->username.value != NULL) {
		free(client->username.value);
	}
	
	// free skin
	if (client->textures.value != NULL) {
		free(client->textures.value);
	}
	if (client->textures.signature != NULL) {
		free(client->textures.signature);
	}

	free(client);

}

void ltg_term() {

	// cancel main thread
	sck_close(sky_main.listener.address.socket);
	pthread_cancel(sky_main.listener.thread);

	pthread_mutex_lock(&sky_main.listener.clients.lock);

	// disconnect all clients
	for (uint32_t i = 0; i < sky_main.listener.clients.vector.size; ++i) {
		ltg_client_t* client = UTL_VECTOR_GET_AS(ltg_client_t*, &sky_main.listener.clients.vector, i);
		if (client != NULL) {
			sck_close(client->socket);
			pthread_cancel(client->thread);
		}
	}

	sck_term();

}
