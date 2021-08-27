#pragma once
#include "../../main.h"
#include "../../listening/listening.h"
#include "../../util/str_util.h"
#include "../chat/chat.h"

typedef enum {

	cmd_not_op = 0,
	cmd_op_1 = 1,
	cmd_op_2 = 2,
	cmd_op_3 = 3,
	cmd_op_4 = 4

} cmd_op_level_t;

typedef enum {

	cmd_console = 0,
	cmd_player = 1,
	cmd_command_block = 2

} cmd_sender_type_t;

typedef struct {

	cmd_sender_type_t type;
	cmd_op_level_t op;

	union {
		ltg_client_t* player;
	};

} cmd_sender_t;

typedef struct {

	const string_t label;
	const string_t description;
	const string_t usage;
	const string_t permission;
	const string_t permission_message;
	bool_t (*const handler) (char*, const cmd_sender_t*);
	const size_t alias_count;
	const string_t aliases[];

} cmd_command_t;

extern utl_vector_t cmd_list;

extern void cmd_add_defaults();

extern void cmd_add_command(const cmd_command_t*);
extern void cmd_handle(char*, const cmd_sender_t*);

extern bool_t cmd_has_permission(const cmd_command_t*, const cmd_sender_t*);

extern uint32_t cmd_hash(const char*);
extern char* cmd_hash_arg(char*, uint32_t*);

extern void cmd_message(const cmd_sender_t*, const cht_component_t*);

// API

extern cmd_op_level_t cmd_get_op_level(const cmd_sender_t*);
extern cmd_sender_type_t cmd_get_sender_type(const cmd_sender_t*);
extern ltg_client_t* cmd_get_player(const cmd_sender_t*);

/* COMMANDS */
extern bool_t cmd_stop(char*, const cmd_sender_t*);
extern bool_t cmd_help(char*, const cmd_sender_t*);
extern bool_t cmd_plugins(char*, const cmd_sender_t*);
extern bool_t cmd_jb(char*, const cmd_sender_t*);

static const cmd_command_t cmd_stop_h = {
	.label = UTL_CSTRTOSTR("stop"),
	.description = UTL_CSTRTOSTR("Stops the server"),
	.permission = UTL_CSTRTOSTR("server.stop"),
	.handler = cmd_stop
};

static const cmd_command_t cmd_help_h = {
	.label = UTL_CSTRTOSTR("help"),
	.alias_count = 1,
	.aliases = { UTL_CSTRTOSTR("?") },
	.description = UTL_CSTRTOSTR("Show a list of commands"),
	.handler = cmd_help
};

static const cmd_command_t cmd_plugins_h = {
	.label = UTL_CSTRTOSTR("plugins"),
	.alias_count = 1,
	.aliases = { UTL_CSTRTOSTR("pl") },
	.description = UTL_CSTRTOSTR("List active plugins"),
	.handler = cmd_plugins
};

static const cmd_command_t cmd_jb_h = {
	.label = UTL_CSTRTOSTR("jb"),
	.description = UTL_CSTRTOSTR("Get current status of the server's job board"),
	.handler = cmd_jb
};

/* CONSTANT MESSAGES */
static const cht_component_t cmd_no_permission = {
	.text = UTL_CSTRTOSTR("You don't have permission to use this command!"),
	.color = cht_red
};

static const cht_component_t cmd_not_found = {
	.text = UTL_CSTRTOSTR("Unknown command. Type 'help' for a list of commands."),
	.color = cht_no_color
};

static const cht_component_t cmd_stopping_server = {
	.text = UTL_CSTRTOSTR("Stopping the server..."),
	.color = cht_no_color
};