#pragma once
#include <pthread.h>
#include "../main.h"
#include "../util/vector.h"
#include "../io/packet/packet.h"
#include "../crypt/rsa.h"
#include "../crypt/cfb8.h"
#include "socket/socket.h"

#define LTG_MAX_RECIEVE 32767

typedef enum {
	ltg_handshake = 0,
	ltg_status = 1,
	ltg_login = 2,
	ltg_play = 3
} ltg_state_t;

#define LTG_AES_KEY_LENGTH 16

typedef byte_t ltg_UUID_t[16];

typedef struct {

	pthread_t thread;

	uint32_t id;

	// address
	int32_t socket;

	struct {
		char* value;
		char* signature;
	} textures;

	struct {
		size_t length;
		char* value;
	} username;

	ltg_UUID_t uuid;

	uint32_t protocol;
	uint32_t verify;

	struct {
		symmetric_CFB8 key;
		bool_t enabled;
	} encryption;

	struct {
		struct sockaddr_in addr;
		int size;
	} address;

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
		utl_vector_t vector;
		utl_vector_t nextID;
	} clients;

	struct {
		uint16_t count;
		uint16_t max;
	} online;

	uint16_t network_compression_threshold;
	bool_t online_mode;
	bool_t prevent_proxy_connections;

	cry_RSAkeypair_t keypair;

} ltg_main_t;

extern void ltg_init();
extern void* t_ltg_run(void*);
extern void ltg_accept(ltg_client_t*);
extern void* t_ltg_client(void*);

extern bool_t ltg_handlePacket(ltg_client_t* client, pck_packet_t* packet);

extern void ltg_send(ltg_client_t*, pck_packet_t*);

extern void ltg_disconnect(ltg_client_t*);

extern void ltg_term();
