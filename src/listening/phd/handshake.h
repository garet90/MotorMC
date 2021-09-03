#pragma once
#include "../../main.h"
#include "../../io/packet/packet.h"
#include "../listening.h"

extern bool phd_handshake(ltg_client_t*, pck_packet_t*);

//inboud
extern bool phd_handle_handshake(ltg_client_t*, pck_packet_t*);
extern bool phd_handle_legacy_slp(ltg_client_t*, pck_packet_t*);

//outboud
extern void phd_send_legacy_slp(ltg_client_t*);