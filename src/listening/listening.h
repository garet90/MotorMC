#pragma once
#include <pthread.h>
#include "../main.h"
#include "../util/id_vector.h"
#include "../util/doubly_linked_list.h"
#include "../util/util.h"
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

typedef enum {

	ltg_chat_enabled = 0,
	ltg_chat_commands_only = 1,
	ltg_chat_hidden = 2

} ltg_chat_mode_t;

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
		string_t value;
		string_t signature;
	} textures;

	string_t username;

	// TODO replace locale for enum
	struct {
		size_t length : 3;
		char value[16];
	} locale;

	ltg_uuid_t uuid;

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

	uint16_t protocol : 10;
	uint8_t render_distance : 6;
	ltg_chat_mode_t chat_mode : 2;

	ltg_state_t state : 2;

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
		size_t max : 16;
	} online;

	uint16_t network_compression_threshold;
	bool_t online_mode : 1;
	bool_t prevent_proxy_connections : 1;

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

static inline void ltg_uuid_to_string(ltg_uuid_t uuid, char* out) {
	
	out[0] = utl_hexmap[uuid[0] >> 4];
	out[1] = utl_hexmap[uuid[0] & 0xF];
	out[2] = utl_hexmap[uuid[1] >> 4];
	out[3] = utl_hexmap[uuid[1] & 0xF];
	out[4] = utl_hexmap[uuid[2] >> 4];
	out[5] = utl_hexmap[uuid[2] & 0xF];
	out[6] = utl_hexmap[uuid[3] >> 4];
	out[7] = utl_hexmap[uuid[3] & 0xF];
	out[8] = '-';
	out[9] = utl_hexmap[uuid[4] >> 4];
	out[10] = utl_hexmap[uuid[4] & 0xF];
	out[11] = utl_hexmap[uuid[5] >> 4];
	out[12] = utl_hexmap[uuid[5] & 0xF];
	out[13] = '-';
	out[14] = utl_hexmap[uuid[6] >> 4];
	out[15] = utl_hexmap[uuid[6] & 0xF];
	out[16] = utl_hexmap[uuid[7] >> 4];
	out[17] = utl_hexmap[uuid[7] & 0xF];
	out[18] = '-';
	out[19] = utl_hexmap[uuid[8] >> 4];
	out[20] = utl_hexmap[uuid[8] & 0xF];
	out[21] = utl_hexmap[uuid[9] >> 4];
	out[22] = utl_hexmap[uuid[9] & 0xF];
	out[23] = '-';
	out[24] = utl_hexmap[uuid[10] >> 4];
	out[25] = utl_hexmap[uuid[10] & 0xF];
	out[26] = utl_hexmap[uuid[11] >> 4];
	out[27] = utl_hexmap[uuid[11] & 0xF];
	out[28] = utl_hexmap[uuid[12] >> 4];
	out[29] = utl_hexmap[uuid[12] & 0xF];
	out[30] = utl_hexmap[uuid[13] >> 4];
	out[31] = utl_hexmap[uuid[13] & 0xF];
	out[32] = utl_hexmap[uuid[14] >> 4];
	out[33] = utl_hexmap[uuid[14] & 0xF];
	out[34] = utl_hexmap[uuid[15] >> 4];
	out[35] = utl_hexmap[uuid[15] & 0xF];
	out[36] = 0;

}