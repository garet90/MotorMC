#pragma once
#include "../../main.h"
#include "../../io/packet/packet.h"
#include "../listening.h"

extern bool_t phd_play(ltg_client_t*, pck_packet_t*);

extern bool_t phd_handle_teleport_confirm(ltg_client_t*, pck_packet_t*);
extern bool_t phd_handle_client_status(ltg_client_t*, pck_packet_t*);
extern bool_t phd_handle_client_settings(ltg_client_t*, pck_packet_t*);
extern bool_t phd_handle_plugin_message(ltg_client_t*, pck_packet_t*, int32_t);
extern bool_t phd_handle_player_position(ltg_client_t*, pck_packet_t*);
extern bool_t phd_handle_player_position_and_look(ltg_client_t*, pck_packet_t*);

extern void phd_send_join_game(ltg_client_t*);
extern void phd_send_held_item_change(ltg_client_t*);
extern void phd_send_declare_recipes(ltg_client_t*);
extern void phd_send_tags(ltg_client_t*);
extern void phd_send_entity_status(ltg_client_t*);
extern void phd_send_declare_commands(ltg_client_t*);
extern void phd_send_unlock_recipes(ltg_client_t*);
extern void phd_send_player_position_and_look(ltg_client_t*);
extern void phd_send_player_info(ltg_client_t*);
extern void phd_send_update_view_position(ltg_client_t*);
extern void phd_send_update_light(ltg_client_t*);
extern void phd_send_chunk_data(ltg_client_t*);
extern void phd_send_world_border(ltg_client_t*);
extern void phd_send_spawn_position(ltg_client_t*);