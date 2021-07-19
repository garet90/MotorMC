#pragma once
#include "../../main.h"
#include "../../io/packet/packet.h"
#include "../listening.h"

extern bool_t phd_handshake(ltg_client_t*, pck_packet_t*);

//inboud
extern bool_t phd_handleHandshake(ltg_client_t*, pck_packet_t*);
extern bool_t phd_handleLegacySLP(ltg_client_t*, pck_packet_t*);

//outboud
extern void phd_sendLegacySLP(ltg_client_t*);