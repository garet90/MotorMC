#pragma once

#include "commands.d.h"
#include "../../listening/listening.d.h"

#include "../../main.h"
#include "../chat/chat.h"
#include "../../util/str_util.h"

struct cmd_sender {

	cmd_sender_type_t type : 2;
	uint8_t op : 3;

	union {
		ltg_client_t* player;
	};

};

struct cmd_command {

	const string_t label;
	const string_t description;
	const string_t usage;
	const string_t permission;
	const string_t permission_message;
	bool (*const handler) (char*, const cmd_sender_t*);
	const size_t alias_count;
	const string_t aliases[];

};

extern utl_vector_t cmd_list;

extern void cmd_add_defaults();

extern void cmd_add_command(const cmd_command_t*);
extern void cmd_handle(char*, const cmd_sender_t*);

extern bool cmd_has_permission(const cmd_command_t*, const cmd_sender_t*);

static inline uint32_t cmd_hash(const char* string) {

	uint32_t hash = 5381;

	for (;;) {
		switch (*string) {
			case '\0':
			case '\n':
			case ' ':
			case '\r':
			case '\t':
			case '\v':
			case '\f': {
				goto done;
			}
			default: {
				hash = ((hash << 5) + hash) + *string;
				++string;
			}
		}
	}

	done:
	return hash;

}

static inline char* cmd_hash_arg(char* string, uint32_t* hash) {

	*hash = 5381;

	for (;;) {
		switch (*string) {
			case '\0':
			case '\n':
			case '\r':
			case '\t':
			case '\v':
			case '\f': {
				goto final;
			}
			case ' ': {
				goto done;
			}
			default: {
				*hash = ((*hash << 5) + *hash) + *string;
				++string;
			}
		}
	}

	done:
	return ++string;
	final:
	return NULL;

}

extern void cmd_message(const cmd_sender_t*, const cht_component_t*);

// API

static inline uint8_t cmd_get_op_level(const cmd_sender_t* sender) {
	return sender->op;
}

static inline cmd_sender_type_t cmd_get_sender_type(const cmd_sender_t* sender) {
	return sender->type;
}

static inline ltg_client_t* cmd_get_player(const cmd_sender_t* sender) {
	
	if (sender->type == cmd_player) {
		return sender->player;
	}

	return NULL;

}

/* COMMANDS */
extern bool cmd_stop(char*, const cmd_sender_t*);
extern bool cmd_help(char*, const cmd_sender_t*);
extern bool cmd_plugins(char*, const cmd_sender_t*);
extern bool cmd_jb(char*, const cmd_sender_t*);

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