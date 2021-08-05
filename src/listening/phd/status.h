#pragma once
#include "../../main.h"
#include "../../io/packet/packet.h"
#include "../listening.h"

extern bool_t phd_status(ltg_client_t*, pck_packet_t*);

//inbound
extern bool_t phd_handle_request(ltg_client_t*, pck_packet_t*);
extern bool_t phd_handle_ping(ltg_client_t*, pck_packet_t*);

//outbound
extern void phd_send_response(ltg_client_t*);
extern void phd_send_pong(ltg_client_t*, int64_t);
