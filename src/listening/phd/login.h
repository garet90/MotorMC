#pragma once
#include "../../main.h"
#include "../../io/packet/packet.h"
#include "../../io/chat/chat.h"
#include "../listening.h"

extern bool_t phd_login(ltg_client_t*, pck_packet_t*);

typedef struct {

    char* ptr;
    size_t len;

} phd_authResponse_t;

extern size_t phd_authResponseWrite(void*, size_t, size_t, phd_authResponse_t*);

//inbound
extern bool_t phd_handleLoginStart(ltg_client_t*, pck_packet_t*);
extern bool_t phd_handleEncryptionResponse(ltg_client_t*, pck_packet_t*);
extern bool_t phd_handleLoginPluginResponse(ltg_client_t*, pck_packet_t*);

//outbound
extern void phd_sendDisconnectLogin(ltg_client_t*, cht_component_t);
extern void phd_sendEncryptionRequest(ltg_client_t*);
extern void phd_sendLoginSuccess(ltg_client_t*);
extern void phd_sendSetCompression(ltg_client_t*);
extern void phd_sendLoginPluginRequest(ltg_client_t*, const char* identifier, size_t identifier_length, const byte_t* data, size_t data_length);
