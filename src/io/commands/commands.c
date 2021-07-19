#include "commands.h"
#include "../../motor.h"
#include "../../util/tree.h"
#include "../../util/vector.h"
#include "../logger/logger.h"

utl_tree_t cmd_handlers = {
		.object = NULL
};

const cmd_command_t* cmd_defaults[] = {
	&cmd_stop_h,
	&cmd_help_h,
	&cmd_plugins_h
};
utl_vector_t cmd_list = {
		.bytes_per_element = sizeof(cmd_command_t*),
		.array = (byte_t*) cmd_defaults,
		.size = sizeof(cmd_defaults) / sizeof(cmd_defaults[0])
};

void cmd_addDefaults() {

	for (size_t i = 0; i < cmd_list.size; ++i) {

		cmd_command_t* command = utl_vectorGetAs(cmd_command_t*, &cmd_list, i);

		if (utl_treeGet(&cmd_handlers, cmd_hash(command->label)) == NULL) {
			utl_treePut(&cmd_handlers, cmd_hash(command->label), command);
		} else {
			log_warn("Command already exists and was not added: /%s", command->label);
			continue;
		}

		for (size_t j = 0; j < command->alias_count; ++j) {
			if (utl_treeGet(&cmd_handlers, cmd_hash(command->aliases[j])) == NULL) {
				utl_treePut(&cmd_handlers, cmd_hash(command->aliases[j]), command);
			}
		}

	}

}

void cmd_addCommand(const cmd_command_t* command) {

	if (cmd_list.size != 0 && cmd_handlers.object == NULL) {
		cmd_addDefaults();
	}

	if (utl_treeGet(&cmd_handlers, cmd_hash(command->label)) == NULL) {
		utl_treePut(&cmd_handlers, cmd_hash(command->label), (cmd_command_t*) command);
		utl_vectorPush(&cmd_list, &command);
	} else {
		log_warn("Command already exists and was not added: /%s", command->label);
		return;
	}

	for (uint32_t i = 0; i < command->alias_count; ++i) {
		if (utl_treeGet(&cmd_handlers, cmd_hash(command->aliases[i])) == NULL) {
			utl_treePut(&cmd_handlers, cmd_hash(command->aliases[i]), (cmd_command_t*) command);
		}
	}

}

void cmd_handle(char* cmd, cmd_sender_t* sender) {

	if (cmd_list.size != 0 && cmd_handlers.object == NULL) {
		cmd_addDefaults();
	}

	uint32_t hash;
	cmd = cmd_hashArg(cmd, &hash);

	const cmd_command_t* command = utl_treeGet(&cmd_handlers, hash);

	if (command != NULL) {
		if (cmd_hasPermission(command, sender)) {
			if (!command->handler(cmd, sender)) {
				if (command->usage != NULL) {

					// its faster technically to create a component when the strings are constant
					cht_component_t component = cht_new;
					component.text = (char*) command->usage;

					cmd_message(sender, &component);

				} else {

					cht_component_t component = cht_new;
					component.text = "Usage: /";

					cht_component_t usage = cht_new;
					usage.text = (char*) command->usage;

					cht_addExtra(&component, &usage);

					cmd_message(sender, &component);

					cht_free(&component);

				}
			}
		} else {
			if (command->permissionMessage != NULL) {

				cht_component_t component = cht_new;
				component.text = (char*) command->permissionMessage;

				cmd_message(sender, &component);

			} else {

				cmd_message(sender, &cmd_no_permission);

			}
		}
	} else {

		cmd_message(sender, &cmd_not_found);

	}

}

bool_t cmd_hasPermission(const cmd_command_t* command, const cmd_sender_t* sender) {

	if (sender->op) return true;
	if (command->permission == NULL) return true;

	for (uint32_t i = 0; i < sender->permissions.size; ++i) {
		if (strcmp(utl_vectorGetAs(char*, &sender->permissions, 1), command->permission)) {
			return true;
		}
	}

	return false;

}

uint32_t cmd_hash(const char* string) {

	uint32_t hash = 5381;

	for (;;) {
		switch (*string) {
		case '\0':
		case '\n':
		case ' ':
		case '\r':
		case '\t':
		case '\v':
		case '\f':
			goto done;
		default:
			hash = ((hash << 5) + hash) + *string;
			++string;
		}
	}

	done:
	return hash;

}

char* cmd_hashArg(char* string, uint32_t* hash) {

	*hash = 5381;

	for (;;) {
		switch (*string) {
		case '\0':
		case '\n':
		case '\r':
		case '\t':
		case '\v':
		case '\f':
			goto final;
		case ' ':
			goto done;
		default:
			*hash = ((*hash << 5) + *hash) + *string;
			++string;
		}
	}

	done:
	return ++string;
	final:
	return NULL;

}

void cmd_message(cmd_sender_t* sender, const cht_component_t* component) {

	log_command(sender, component);

}

bool_t cmd_stop(char* args, cmd_sender_t* sender) {

	if (args != NULL) {
		return false;
	}

	cmd_message(sender, &cmd_stopping_server);

	sky_term();

	return true;

}

bool_t cmd_help(char* args, cmd_sender_t* sender) {

	if (args != NULL) {
		return false;
	}

	cmd_message(sender, &cmd_help_header);

	char line[256];
	cht_component_t msg = cht_new;
	msg.text = line;

	for (uint32_t i = 0; i < cmd_list.size; ++i) {
		cmd_command_t* command = utl_vectorGetAs(cmd_command_t*, &cmd_list, i);
		sprintf(line, "- %s: %s", command->label, command->description);
		cmd_message(sender, &msg);
	}

	return true;

}

bool_t cmd_plugins(char* args, cmd_sender_t* sender) {

	if (args != NULL) {
		return false;
	}

	// TODO
	cmd_message(sender, &cht_new);

	return true;

}