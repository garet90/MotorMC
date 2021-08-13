#pragma once
#include <pthread.h>
#include "../main.h"
#include "../util/id_vector.h"
#include "../util/doubly_linked_list.h"
#include "../io/packet/packet.h"
#include "../crypt/rsa.h"
#include "../crypt/cfb8.h"
#include "../world/entity/entity.h"
#include "socket/socket.h"

#define LTG_MAX_RECIEVE 32767

typedef enum {
	ltg_handshake = 0,
	ltg_status = 1,
	ltg_login = 2,
	ltg_play = 3
} ltg_state_t;

#define LTG_AES_KEY_LENGTH 16

typedef byte_t ltg_uuid_t[16];

typedef struct {

	pthread_t thread;
	
	utl_doubly_linked_node_t* online_node;
	ent_player_t* entity;

	uint32_t id;

	// address
	int32_t socket;

	struct {
		struct {
			char* value;
			size_t length;
		} value;
		struct {
			char* value;
			size_t length;
		} signature;
	} textures;

	struct {
		size_t length;
		char value[16];
	} username;

	struct {
		size_t length;
		char value[16];
	} locale;

	ltg_uuid_t uuid;

	uint32_t protocol;
	uint32_t verify;

	int64_t last_recv;
	int64_t ping;

	struct {
		symmetric_CFB8 encrypt;
		symmetric_CFB8 decrypt;
		bool_t enabled;
	} encryption;

	struct {
		struct sockaddr_in addr;
		int size;
	} address;

	int32_t keep_alive;

	uint8_t render_distance;
	uint8_t chat_mode;

	ltg_state_t state;

} ltg_client_t;

typedef struct {

	pthread_t thread;

	// address
	struct {
		int32_t socket;
		struct sockaddr_in addr;
		uint16_t port;
	} address;

	struct {
		pthread_mutex_t lock;
		utl_id_vector_t vector;
	} clients;

	struct {
		pthread_mutex_t lock;
		utl_doubly_linked_list_t list;
		size_t max;
	} online;

	uint16_t network_compression_threshold;
	bool_t online_mode;
	bool_t prevent_proxy_connections;

	cry_rsa_keypair_t keypair;

} ltg_main_t;

extern void ltg_init();
extern void* t_ltg_run(void*);
extern void ltg_accept(ltg_client_t*);
extern void* t_ltg_client(void*);

extern bool_t ltg_handle_packet(ltg_client_t* client, pck_packet_t* packet);

extern void ltg_send(ltg_client_t*, pck_packet_t*);

extern void ltg_disconnect(ltg_client_t*);

extern void ltg_term();

extern void ltg_uuid_to_string(ltg_uuid_t uuid, char* out);