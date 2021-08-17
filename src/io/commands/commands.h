#pragma once
#include "../../main.h"
#include "../../listening/listening.h"
#include "../chat/chat.h"

typedef enum {

	cmd_not_op = 0,
	cmd_op_1 = 1,
	cmd_op_2 = 2,
	cmd_op_3 = 3,
	cmd_op_4 = 4

} cmd_op_level_t;

typedef enum {

	cmd_console,
	cmd_player,
	cmd_command_block

} cmd_sender_type_t;

typedef struct {

	cmd_sender_type_t type;
	cmd_op_level_t op;

	union {
		ltg_client_t* player;
	};

} cmd_sender_t;

typedef struct {

	const char* label;
	const char* description;
	const char* usage;
	const char* permission;
	const char* permission_message;
	bool_t (*const handler) (char*, const cmd_sender_t);
	const size_t alias_count;
	const char* aliases[];

} cmd_command_t;

extern utl_vector_t cmd_list;

extern void cmd_add_defaults();

extern void cmd_add_command(const cmd_command_t*);
extern void cmd_handle(char*, const cmd_sender_t);

extern bool_t cmd_has_permission(const cmd_command_t*, const cmd_sender_t);

extern uint32_t cmd_hash(const char*);
extern char* cmd_hash_arg(char*, uint32_t*);

extern void cmd_message(cmd_sender_t, const cht_component_t*);

/* COMMANDS */
extern bool_t cmd_stop(char*, cmd_sender_t);
extern bool_t cmd_help(char*, cmd_sender_t);
extern bool_t cmd_plugins(char*, cmd_sender_t);

static const cmd_command_t cmd_stop_h = {
	.label = "stop",
	.description = "Stops the server",
	.permission = "server.stop",
	.handler = cmd_stop
};

static const cmd_command_t cmd_help_h = {
	.label = "help",
	.alias_count = 1,
	.aliases = { "?" },
	.description = "Show a list of commands",
	.handler = cmd_help
};

static const cmd_command_t cmd_plugins_h = {
	.label = "plugins",
	.alias_count = 1,
	.aliases = { "pl" },
	.description = "List active plugins",
	.handler = cmd_plugins
};

/* CONSTANT MESSAGES */
static const cht_component_t cmd_no_permission = {
	.text = "You don't have permission to use this command!",
	.color = cht_red
};

static const cht_component_t cmd_not_found = {
	.text = "Unknown command. Type 'help' for a list of commands.",
	.color = cht_no_color
};

static const cht_component_t cmd_stopping_server = {
	.text = "Stopping the server...",
	.color = cht_no_color
};