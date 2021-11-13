#pragma once

typedef enum {

	cmd_console = 0,
	cmd_player = 1,
	cmd_command_block = 2

} cmd_sender_type_t;

typedef struct cmd_sender cmd_sender_t;

typedef struct cmd_command cmd_command_t;