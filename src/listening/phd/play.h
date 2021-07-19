#pragma once
#include "../../main.h"
#include "../../io/packet/packet.h"
#include "../listening.h"

extern bool_t phd_play(ltg_client_t*, pck_packet_t*);

extern bool_t phd_handleTeleportConfirm(ltg_client_t*, pck_packet_t*);
extern bool_t phd_handleClientStatus(ltg_client_t*, pck_packet_t*);
extern bool_t phd_handleClientSettings(ltg_client_t*, pck_packet_t*);
extern bool_t phd_handlePlayerPositionAndLook(ltg_client_t*, pck_packet_t*);

extern void phd_sendJoinGame(ltg_client_t*);
extern void phd_sendHeldItemChange(ltg_client_t*);
extern void phd_sendDeclareRecipes(ltg_client_t*);
extern void phd_sendTags(ltg_client_t*);
extern void phd_sendEntityStatus(ltg_client_t*);
extern void phd_sendDeclareCommands(ltg_client_t*);
extern void phd_sendUnlockRecipes(ltg_client_t*);
extern void phd_sendPlayerPositionAndLook(ltg_client_t*);
extern void phd_sendPlayerInfo(ltg_client_t*);
extern void phd_sendUpdateViewPosition(ltg_client_t*);
extern void phd_sendUpdateLight(ltg_client_t*);
extern void phd_sendChunkData(ltg_client_t*);
extern void phd_sendWorldBorder(ltg_client_t*);
extern void phd_sendSpawnPosition(ltg_client_t*);