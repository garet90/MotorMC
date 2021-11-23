#pragma once

typedef struct job_board job_board_t;

typedef enum {

	job_keep_alive,
	job_global_chat_message,
	job_player_join,
	job_player_leave,
	job_send_update_pings,
	job_tick_region,
	job_unload_region,
	job_dig_block,
	job_entity_move,
	job_entity_teleport,
	job_living_entity_look,
	job_living_entity_move_look,
	job_living_entity_teleport_look,
	job_living_entity_damage,
	job_tick_world,

	job_count

} job_type_t;

typedef union job_payload job_payload_t;

typedef struct job_work job_work_t;