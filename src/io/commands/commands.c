#include "commands.h"
#include "../../motor.h"
#include "../../util/tree.h"
#include "../../util/vector.h"
#include "../../listening/phd/play.h"
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

pck_packet_t* cmd_graph = NULL;

void cmd_add_defaults() {

	for (size_t i = 0; i < cmd_list.size; ++i) {

		cmd_command_t* command = UTL_VECTOR_GET_AS(cmd_command_t*, &cmd_list, i);

		if (utl_tree_get(&cmd_handlers, cmd_hash(command->label)) == NULL) {
			utl_tree_put(&cmd_handlers, cmd_hash(command->label), command);
		} else {
			log_warn("Command already exists and was not added: /%s", command->label);
			continue;
		}

		for (size_t j = 0; j < command->alias_count; ++j) {
			if (utl_tree_get(&cmd_handlers, cmd_hash(command->aliases[j])) == NULL) {
				utl_tree_put(&cmd_handlers, cmd_hash(command->aliases[j]), command);
			}
		}

	}

}

void cmd_add_command(const cmd_command_t* command) {

	if (cmd_graph != NULL) {
		free(cmd_graph);
		cmd_graph = NULL;
	}

	if (cmd_list.size != 0 && cmd_handlers.object == NULL) {
		cmd_add_defaults();
	}

	if (utl_tree_get(&cmd_handlers, cmd_hash(command->label)) == NULL) {
		utl_tree_put(&cmd_handlers, cmd_hash(command->label), (cmd_command_t*) command);
		utl_vector_push(&cmd_list, &command);
	} else {
		log_warn("Command already exists and was not added: /%s", command->label);
		return;
	}

	for (uint32_t i = 0; i < command->alias_count; ++i) {
		if (utl_tree_get(&cmd_handlers, cmd_hash(command->aliases[i])) == NULL) {
			utl_tree_put(&cmd_handlers, cmd_hash(command->aliases[i]), (cmd_command_t*) command);
		}
	}

}

void cmd_handle(char* cmd, const cmd_sender_t sender) {

	if (cmd_list.size != 0 && cmd_handlers.object == NULL) {
		cmd_add_defaults();
	}

	uint32_t hash;
	cmd = cmd_hash_arg(cmd, &hash);

	const cmd_command_t* command = utl_tree_get(&cmd_handlers, hash);

	if (command != NULL) {
		if (cmd_has_permission(command, sender)) {
			if (!command->handler(cmd, sender)) {
				if (command->usage != NULL) {

					// its faster technically to create a component when the strings are constant
					cht_component_t component = cht_new;
					component.text = (char*) command->usage;

					cmd_message(sender, &component);

				} else {

					cht_component_t component = cht_new;
					component.text = "Usage: /";

					cht_component_t label = cht_new;
					label.text = (char*) command->label;

					cht_add_extra(&component, &label);

					cmd_message(sender, &component);

					cht_free(&component);

				}
			}
		} else {
			if (command->permission_message != NULL) {

				cht_component_t component = cht_new;
				component.text = (char*) command->permission_message;

				cmd_message(sender, &component);

			} else {

				cmd_message(sender, &cmd_no_permission);

			}
		}
	} else {

		cmd_message(sender, &cmd_not_found);

	}

}

bool_t cmd_has_permission(const cmd_command_t* command, const cmd_sender_t sender) {

	if (sender.op) return true;
	if (command->permission == NULL) return true;

	/*
	for (uint32_t i = 0; i < sender->permissions.size; ++i) {
		if (strcmp(UTL_VECTOR_GET_AS(char*, &sender->permissions, 1), command->permission)) {
			return true;
		}
	}
	*/

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

char* cmd_hash_arg(char* string, uint32_t* hash) {

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

void cmd_message(const cmd_sender_t sender, const cht_component_t* component) {

	switch (sender.type) {
		case cmd_console:
			log_command(component);
			break;
		case cmd_player: {
			char message[4096];
			size_t message_length = cht_write(component, message);
			phd_send_system_chat_message(sender.player, message, message_length);
		} break;
		case cmd_command_block:
			break;
	}

}

typedef enum {
	
	cmd_node_root,
	cmd_node_literal,
	cmd_node_argument

} cmd_node_type_t;

typedef struct cmd_node cmd_node_t;

struct cmd_node {

	int32_t idx;
	cmd_node_type_t type;
	byte_t flags[1];
	utl_vector_t children;
	cmd_node_t* redirect_node;

	union {

		struct {

			struct {
				const char* value;
				int32_t length;
			} name;

		} literal;

		struct {

			struct {
				const char* value;
				int32_t length;
			} name;

			struct {
				const char* value;
				int32_t length;
			} parser;

			struct {
				const char* value;
				int32_t length;
			} properties;

		} argument;

	};

	struct {
		char* value;
		int32_t length;
	} suggestions_type;

};

int32_t cmd_assign_node_idx(cmd_node_t* node, int32_t idx) {
	
	for (size_t i = 0; i < node->children.size; ++i) {
		cmd_node_t* child = utl_vector_get(&node->children, i);
		child->idx = idx++;
		idx = cmd_assign_node_idx(child, idx);
	}

	return idx;

}

void cmd_write_node(pck_packet_t* packet, cmd_node_t* node) {

	pck_write_int8(packet, node->flags[0]);
	
	pck_write_var_int(packet, node->children.size);
	for (size_t i = 0; i < node->children.size; ++i) {
		cmd_node_t* child = utl_vector_get(&node->children, i);
		pck_write_var_int(packet, child->idx);
	}

	if (node->flags[0] & 0x08) {
		pck_write_var_int(packet, node->redirect_node->idx);
	}

	switch (node->type) {
		case cmd_node_root:
			break;
		case cmd_node_literal:
			pck_write_string(packet, node->literal.name.value, node->literal.name.length);
			break;
		case cmd_node_argument:
			pck_write_string(packet, node->argument.name.value, node->argument.name.length);
			pck_write_string(packet, node->argument.parser.value, node->argument.parser.length);
			break;
	}

	if (node->flags[0] & 0x10) {
		pck_write_string(packet, node->suggestions_type.value, node->suggestions_type.length);
	}

	for (size_t i = 0; i < node->children.size; ++i) {
		cmd_node_t* child = utl_vector_get(&node->children, i);
		cmd_write_node(packet, child);
	}

}

pck_packet_t* cmd_get_graph() {

	if (cmd_graph == NULL) {

		cmd_node_t root = {
			.idx = 0,
			.type = cmd_node_root,
			.children = {
				.bytes_per_element = sizeof(cmd_node_t)
			}
		};

		for (size_t i = 0; i < cmd_list.size; ++i) {
			cmd_command_t* command = UTL_VECTOR_GET_AS(cmd_command_t*, &cmd_list, i);
			cmd_node_t command_node = {
				.type = cmd_node_literal,
				.flags = {
					0x01
				},
				.children = {
					.bytes_per_element = sizeof(cmd_node_t)
				},
				.literal = {
					.name = {
						.value = command->label,
						.length = strlen(command->label)
					}
				}
			};
			cmd_node_t* command_ptr = utl_vector_push(&root.children, &command_node);

			// aliases
			for (size_t j = 0; j < command->alias_count; ++j) {
				cmd_node_t command_alias = {
					.type = cmd_node_literal,
					.flags = {
						0x01 | 0x08
					},
					.children = {
						.bytes_per_element = sizeof(cmd_node_t)
					},
					.redirect_node = command_ptr,
					.literal = {
						.name = {
							.value = command->aliases[j],
							.length = strlen(command->aliases[j])
						}
					}
				};
				utl_vector_push(&root.children, &command_alias);
			}
		}

		// assign indexes
		int32_t node_count = cmd_assign_node_idx(&root, 1);

		cmd_graph = pck_create(11 + (node_count * 128), io_big_endian);
		pck_write_var_int(cmd_graph, 0x12);
		pck_write_var_int(cmd_graph, node_count);
		cmd_write_node(cmd_graph, &root);
		pck_write_var_int(cmd_graph, 0);

	}

	return cmd_graph;

}

bool_t cmd_stop(char* args, const cmd_sender_t sender) {

	if (args != NULL) {
		return false;
	}

	if (sender.type != cmd_console)
		cmd_message(sender, &cmd_stopping_server);

	sky_term();

	return true;

}

bool_t cmd_help(char* args, const cmd_sender_t sender) {

	if (args != NULL) {
		return false;
	}

	cht_component_t help = cht_new;
	help.color = cht_yellow;
	help.text = "---------- ";

	cht_component_t help_0 = cht_new;
	help_0.color = cht_white;
	help_0.text = "Help: Commands ";

	cht_component_t help_1 = cht_new;
	help_1.color = cht_yellow;
	help_1.text = "----------";

	cht_add_extra(&help, &help_0);
	cht_add_extra(&help, &help_1);

	cmd_message(sender, &help);

	cht_free(&help);

	cht_component_t help_help = cht_new;
	help_help.text = "Use /help [n] to get page n of help";
	help_help.color = cht_gray;

	cmd_message(sender, &help_help);

	for (uint32_t i = 0; i < cmd_list.size; ++i) {
		cmd_command_t* command = UTL_VECTOR_GET_AS(cmd_command_t*, &cmd_list, i);
		cht_component_t command_label = cht_new;
		command_label.text = (char*) command->label;
		command_label.color = cht_gold;
		cht_component_t command_semicolon = cht_new;
		command_semicolon.text = ": ";
		cht_component_t command_description = cht_new;
		command_description.text = (char*) command->description;
		command_description.color = cht_white;
		cht_add_extra(&command_label, &command_semicolon);
		cht_add_extra(&command_label, &command_description);
		cmd_message(sender, &command_label);
		cht_free(&command_label);
	}

	return true;

}

bool_t cmd_plugins(char* args, const cmd_sender_t sender) {

	if (args != NULL) {
		return false;
	}

	cht_component_t plugins = cht_new;
	plugins.text = "Plugins: ";
	plugins.color = cht_yellow;

	cmd_message(sender, &plugins);

	return true;

}