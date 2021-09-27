#include <libdeflate.h>
#include "listening.h"
#include "../motor.h"
#include "../jobs/board.h"
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

			// accept the client
			ltg_accept(client);

		}
	}

	return input;

}

void ltg_accept(ltg_client_t* client) {

	// lock clients
	with_lock (&sky_main.listener.clients.lock) {
		client->id = utl_id_vector_push(&sky_main.listener.clients.vector, &client);
	}

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

	ltg_client_t* client = NULL;

	with_lock (&sky_main.listener.clients.lock) {
		client = UTL_ID_VECTOR_GET_AS(ltg_client_t*, &sky_main.listener.clients.vector, id);
	}

	return client;

}

/*
 * Handle packets
 * If return is false, disconnect the client
 */
bool ltg_handle_packet(ltg_client_t* client, pck_packet_t* packet) {

	size_t next_packet = 0;

	do {
		packet->cursor = next_packet;

		if (client->compression_enabled) {
			const int32_t packet_length = pck_read_var_int(packet);
			const size_t length_ptr = packet->cursor;
			const int32_t data_length = pck_read_var_int(packet);

			if (data_length == 0) { // uncompressed
				packet->sub_length = packet_length - 1;
				next_packet = packet->cursor + packet->sub_length;
			} else {
				packet->sub_length = data_length;
				next_packet = length_ptr + packet_length;

				PCK_INLINE(decompressed, data_length, io_big_endian);
				
				// it's zlib compression time
				struct libdeflate_decompressor* decompressor = libdeflate_alloc_decompressor();

				size_t actual_length = 0;
				if (libdeflate_zlib_decompress(decompressor, pck_cursor(packet), packet_length - (packet->cursor - length_ptr), pck_cursor(decompressed), data_length, &actual_length) != LIBDEFLATE_SUCCESS) {
					libdeflate_free_decompressor(decompressor);
					return false;
				}

				libdeflate_free_decompressor(decompressor);

				if (actual_length != (unsigned) data_length) {
					return false;
				}

				decompressed->sub_length = decompressed->length =  actual_length;

				switch (client->state) {
				case ltg_handshake:
					if (!phd_handshake(client, decompressed)) {
						return false;
					}
					break;
				case ltg_status:
					if (!phd_status(client, decompressed)) {
						return false;
					}
					break;
				case ltg_login:
					if (!phd_login(client, decompressed)) {
						return false;
					}
					break;
				case ltg_play:
					if (!phd_play(client, decompressed)) {
						return false;
					}
					break;
				default:
					log_warn("Client is in an unknown state! (%d)", client->state);
					return false;
				}

				continue;

			}
		} else {
			packet->sub_length = pck_read_var_int(packet);
			next_packet = packet->cursor + packet->sub_length;
		}

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
	} while (next_packet < packet->length);

	return true;

}

// sends the packet to the client specified
void ltg_send(ltg_client_t* client, pck_packet_t* packet) {

	size_t length = packet->cursor;
	byte_t* bytes = NULL;

	if (client->compression_enabled) {

		if (length >= sky_main.listener.network_compression_threshold) { // compress the packet
		
			byte_t compressed[length + 10];
			size_t compressed_length = 0;

			bytes = compressed + 10;
			
			// it's zlib compression time
			struct libdeflate_compressor* compressor = libdeflate_alloc_compressor(6);

			compressed_length = libdeflate_zlib_compress(compressor, packet->bytes, length, bytes, length);
			libdeflate_free_compressor(compressor);

			if (compressed_length != 0) {

				const size_t data_length_length = io_var_int_length(length);
				const size_t packet_length_length = io_var_int_length(compressed_length + data_length_length);
				
				bytes = bytes - data_length_length - packet_length_length;
				io_write_var_int(bytes, compressed_length + data_length_length, 5);
				io_write_var_int(bytes + packet_length_length, length, 5);
				length = compressed_length + data_length_length + packet_length_length;

				if (client->encryption.enabled) {

					// encrypt packet
					byte_t encrypted[length];

					cfb8_encrypt(bytes, encrypted, length, &client->encryption.encrypt);

					sck_send(client->socket, (char*) encrypted, length);

				} else {
					sck_send(client->socket, (char*) bytes, length);
				}

				return;

			}

		}
		
		// do not compress the packet
		const size_t length_length = io_var_int_length(length + 1);
		bytes = packet->bytes - length_length - 1;
		io_write_var_int(bytes, length + 1, 5);
		bytes[length_length] = 0;
		length += length_length + 1;

	} else {

		const size_t length_length = io_var_int_length(length);
		bytes = packet->bytes - length_length;
		io_write_var_int(bytes, length, 5);
		length += length_length;

	}

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

	switch (client->state) {
		case ltg_play: {
			// cancel keep alive
			sch_cancel(client->keep_alive);

			// remove from online player list
			with_lock (&sky_main.listener.online.lock) {
				utl_dll_remove(&sky_main.listener.online.list, client->online_node);
			}

			// create player leave job
			job_payload_t payload = {
				.player_leave = {
					.username_length = client->username.length
				}
			};
			payload.player_leave.username[payload.player_leave.username_length] = 0;
			memcpy(payload.player_leave.username, client->username.value, client->username.length);
			memcpy(payload.player_leave.uuid, client->uuid, sizeof(ltg_uuid_t));
			uint32_t work = job_new(job_player_leave, payload);
			
			job_add(work);
			
			phd_update_sent_chunks_leave(client);
			ent_free_entity((ent_entity_t*) client->entity);
		} break;
		default: {
			// do nothing extra
		} break;
	}

	sck_close(client->socket);

	// remove from client list
	with_lock (&sky_main.listener.clients.lock) {
		utl_id_vector_remove(&sky_main.listener.clients.vector, client->id);
	}

	// free username
	UTL_FREESTR(client->username);

	// free skin
	UTL_FREESTR(client->textures.value);
	UTL_FREESTR(client->textures.signature);

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

	// disconnect message
	cht_translation_t disconnect_message = cht_translation_new;
	disconnect_message.translate = cht_translation_multiplayer_disconnect_server_shutdown;

	char message[128];
	size_t message_length = cht_write_translation(&disconnect_message, message);

	// disconnect all clients
	with_lock (&sky_main.listener.clients.lock) {
		for (uint32_t i = 0; i < sky_main.listener.clients.vector.array.size; ++i) {
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
	}

	sck_term();

}

string_t ltg_get_username(const ltg_client_t* client) {
	return client->username;
}

const byte_t* ltg_get_uuid(const ltg_client_t* client) {
	return client->uuid;
}

uint16_t ltg_get_protocol(const ltg_client_t* client) {
	return client->protocol;
}

uint8_t ltg_get_render_distance(const ltg_client_t* client) {
	return client->render_distance;
}

int64_t ltg_get_ping(const ltg_client_t* client) {
	return client->ping;
}

string_t ltg_get_textures(const ltg_client_t* client) {
	return client->textures.value;
}

ltg_locale_t ltg_get_locale(const ltg_client_t* client) {
	return client->locale;
}

ent_player_t* ltg_get_entity(const ltg_client_t* client) {
	return client->entity;
}