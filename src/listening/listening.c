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

void ltg_init(ltg_listener_t* listener) {

	log_info("Starting listener...");

	// generate RSA keypair
	cry_rsa_gen_key_pair(&listener->keypair);

	// start listening thread
	pthread_create(&listener->thread, NULL, t_ltg_run, listener);

}

void* t_ltg_run(void* args) {

	ltg_listener_t* listener = args;

	// init sockets
	if (sck_init() != SCK_OK) {
		return NULL;
	}

	// create socket
	listener->address.socket = sck_create();

	// set address
	listener->address.addr.sin_family = AF_INET;
	listener->address.addr.sin_addr.s_addr = INADDR_ANY;
	listener->address.addr.sin_port = io_htons(listener->address.port);

	// bind socket
	if (sck_bind(listener->address.socket, (struct sockaddr*) &listener->address.addr, sizeof(struct sockaddr)) != SCK_OK) {
		return NULL;
	}

	// listen
	if (sck_listen(listener->address.socket) != SCK_OK) {
		return NULL;
	}
	log_info("Listening on port %u", listener->address.port);

	for (;;) {

		// forever

		int32_t socket;
		struct sockaddr_in address;
		int address_size = sizeof(struct sockaddr_in);
		socket = sck_accept(listener->address.socket, (struct sockaddr*) &address, &address_size);

		if (socket == SCK_FAILED) {

			// something failed when connecting a client
			break;

		} else {

			// allocate new client and set address and socket
			ltg_client_t* client = calloc(1, sizeof(ltg_client_t));
			client->listener = listener;
			client->socket = socket;
			pthread_mutex_init(&client->lock, NULL);
			client->address.addr = address;
			client->address.size = address_size;
			client->state = ltg_handshake;

			// accept the client
			ltg_accept(client);

		}
	}

	return (void*) 1;

}

void ltg_accept(ltg_client_t* client) {

	// lock clients
	with_lock (&client->listener->clients.lock) {
		client->id = utl_id_vector_push(&client->listener->clients.vector, &client);
	}

	// create client listening thread
	pthread_create(&client->thread, NULL, t_ltg_client, client);

}

void* t_ltg_client(void* args) {

	ltg_client_t* client = args;

	// create receive packet (on stack)
	PCK_INLINE(recvd, LTG_MAX_RECEIVE, io_big_endian);

	for (;;) {

		// receive packet
		recvd->length = sck_recv(client->socket, (char*) recvd->bytes, LTG_MAX_RECEIVE);

		if ((int32_t) recvd->length <= 0) {
			// client disconnected
			break;
		} else {
			// handle packet
			recvd->cursor = 0;

			if (client->encryption.enabled) {
				PCK_INLINE(decrypted, recvd->length, io_big_endian);
				if (cfb8_decrypt(client->encryption.decrypt, recvd->bytes, recvd->length, decrypted->bytes) != 1) {
					log_error("Decryption failed");
					break;
				}
				decrypted->length = recvd->length;

				if (!ltg_handle_packet(client, decrypted)) {
					break;
				}
			} else {
				if (!ltg_handle_packet(client, recvd)) {
					break;
				}
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
				if (client->compression.decompressor == NULL) {
					client->compression.decompressor = libdeflate_alloc_decompressor();
				}

				size_t actual_length = 0;
				if (libdeflate_zlib_decompress(client->compression.decompressor, pck_cursor(packet), packet_length - (packet->cursor - length_ptr), pck_cursor(decompressed), data_length, &actual_length) != LIBDEFLATE_SUCCESS) {
					log_error("Client sent a corrupt packet! (0)");
					return false;
				}

				if (actual_length != (unsigned) data_length) {
					log_error("Client sent a corrupt packet! (1)");
					return false;
				}

				decompressed->sub_length = decompressed->length =  actual_length;

				switch (client->state) {
					case ltg_handshake: {
						if (!phd_handshake(client, decompressed)) {
							return false;
						}
					} break;
					case ltg_status: {
						if (!phd_status(client, decompressed)) {
							return false;
						}
					} break;
					case ltg_login: {
						if (!phd_login(client, decompressed)) {
							return false;
						}
					} break;
					case ltg_play: {
						if (!phd_play(client, decompressed)) {
							return false;
						}
					} break;
					default: {
						log_warn("Client is in an unknown state! (%d)", client->state);
						return false;
					}
				}

				continue;

			}
		} else {
			packet->sub_length = pck_read_var_int(packet);
			next_packet = packet->cursor + packet->sub_length;
		}

		switch (client->state) {
			case ltg_handshake: {
				if (!phd_handshake(client, packet)) {
					return false;
				}
			} break;
			case ltg_status: {
				if (!phd_status(client, packet)) {
					return false;
				}
			} break;
			case ltg_login: {
				if (!phd_login(client, packet)) {
					return false;
				}
			} break;
			case ltg_play: {
				if (!phd_play(client, packet)) {
					return false;
				}
			} break;
			default: {
				log_warn("Client is in an unknown state! (%d)", client->state);
				return false;
			}
		}
	} while (next_packet < packet->length);

	return true;

}

// send encryption step (used in compressed and uncompressed)
static inline void ltg_send_e(ltg_client_t* client, byte_t* bytes, size_t length) {
	
	if (client->encryption.enabled) {

		// encrypt packet
		byte_t encrypted[length];

		cfb8_encrypt(client->encryption.encrypt, bytes, length, encrypted);

		sck_send(client->socket, (char*) encrypted, length);

	} else {
		sck_send(client->socket, (char*) bytes, length);
	}

}

// sends the packet to the client specified
void ltg_send(ltg_client_t* client, pck_packet_t* packet) {

	with_lock (&client->lock) {

		size_t length = packet->cursor;
		byte_t* bytes = NULL;

		if (client->compression_enabled) {

			if (length >= sky_get_network_compression_threshold()) { // compress the packet
			
				byte_t compressed[length + 10];
				size_t compressed_length = 0;

				bytes = compressed + 10;
				
				// it's zlib compression time
				if (client->compression.compressor == NULL) {
					client->compression.compressor = libdeflate_alloc_compressor(6);
				}

				compressed_length = libdeflate_zlib_compress(client->compression.compressor, packet->bytes, length, bytes, length);

				if (compressed_length != 0) {

					const size_t data_length_length = io_var_int_length(length);
					const size_t packet_length_length = io_var_int_length(compressed_length + data_length_length);
					
					bytes = bytes - data_length_length - packet_length_length;
					io_write_var_int(bytes, compressed_length + data_length_length, 5);
					io_write_var_int(bytes + packet_length_length, length, 5);
					length = compressed_length + data_length_length + packet_length_length;

					ltg_send_e(client, bytes, length);

					pthread_mutex_unlock(&client->lock);
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

		ltg_send_e(client, bytes, length);

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
			with_lock (&client->listener->online.lock) {
				utl_id_vector_remove(&client->listener->online.vector, client->online_node);
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
			ent_free_player(client->entity);
		} break;
		default: {
			// do nothing extra
		} break;
	}

	pthread_mutex_lock(&client->lock);
	pthread_mutex_destroy(&client->lock);
	sck_close(client->socket);

	// remove from client list
	with_lock (&client->listener->clients.lock) {
		utl_id_vector_remove(&client->listener->clients.vector, client->id);
	}

	// free compressors
	libdeflate_free_compressor(client->compression.compressor);
	libdeflate_free_decompressor(client->compression.decompressor);

	// free username
	UTL_FREESTR(client->username);

	// free skin
	UTL_FREESTR(client->textures.value);
	UTL_FREESTR(client->textures.signature);

	// free encryption key
	if (client->encryption.enabled) {
		cfb8_done(client->encryption.encrypt, client->encryption.decrypt);
	}

	free(client);

}

void ltg_term(ltg_listener_t* listener) {

	// cancel main thread
	sck_close(listener->address.socket);
	pthread_cancel(listener->thread);

	// disconnect message
	cht_translation_t disconnect_message = cht_translation_new;
	disconnect_message.translate = cht_translation_multiplayer_disconnect_server_shutdown;

	char message[128];
	size_t message_length = cht_write_translation(&disconnect_message, message);

	// disconnect all clients
	with_lock (&listener->clients.lock) {
		for (uint32_t i = 0; i < listener->clients.vector.array.size; ++i) {
			ltg_client_t* client = UTL_ID_VECTOR_GET_AS(ltg_client_t*, &listener->clients.vector, i);
			if (client != NULL) {
				pthread_mutex_unlock(&listener->clients.lock);
				phd_send_disconnect(client, message, message_length);
				ltg_disconnect(client);
				if (pthread_self() != client->thread) {
					pthread_join(client->thread, NULL);
				}
				pthread_mutex_lock(&listener->clients.lock);
			}
		}
	}

	sck_term();

}