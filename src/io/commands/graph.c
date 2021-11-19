#include "graph.h"

pck_packet_t* cmd_graph = NULL;

pck_packet_t* cmd_get_graph() {

	if (cmd_graph == NULL) {

		utl_vector_t nodes = UTL_VECTOR_INITIALIZER(cmd_node_t*);

		cmd_node_t* root = malloc(sizeof(cmd_node_t));
		cmd_node_t root_init = {
			.type = cmd_node_root,
			.idx = nodes.size,
			.children = UTL_VECTOR_INITIALIZER(int32_t),
			.redirect_node = 0 // throws a warning if i don't put this, i have no idea why
		};
		memcpy(root, &root_init, sizeof(cmd_node_t));

		utl_vector_push(&nodes, &root);

		for (size_t i = 0; i < cmd_list.size; ++i) {
			cmd_command_t* command = UTL_VECTOR_GET_AS(cmd_command_t*, &cmd_list, i);
			
			cmd_node_t* command_node = malloc(sizeof(cmd_node_t));
			cmd_node_t command_node_init = {
				.type = cmd_node_literal,
				.children = UTL_VECTOR_INITIALIZER(int32_t),
				.literal = {
					.name = command->label
				},
				.idx = nodes.size
			};
			memcpy(command_node, &command_node_init, sizeof(cmd_node_t));

			utl_vector_push(&nodes, &command_node);
			utl_vector_push(&root->children, &command_node->idx);

			// aliases
			for (size_t j = 0; j < command->alias_count; ++j) {

				cmd_node_t* command_alias = malloc(sizeof(cmd_node_t));
				cmd_node_t command_alias_init = {
					.type = cmd_node_literal,
					.children = UTL_VECTOR_INITIALIZER(int32_t),
					.redirect_node = command_node->idx,
					.has_redirect_node = true,
					.literal = {
						.name = command->aliases[j]
					},
					.idx = nodes.size
				};
				memcpy(command_alias, &command_alias_init, sizeof(cmd_node_t));

				utl_vector_push(&nodes, &command_alias);
				utl_vector_push(&root->children, &command_alias->idx);
			}
		}

		cmd_graph = pck_create(11 + (nodes.size * 256), io_big_endian);
		pck_write_var_int(cmd_graph, 0x12);
		pck_write_var_int(cmd_graph, nodes.size);
		for (size_t i = 0; i < nodes.size; ++i) {

			cmd_node_t* node = UTL_VECTOR_GET_AS(cmd_node_t*, &nodes, i);
			
			pck_write_int8(cmd_graph, 
				node->type | (node->is_executable << 2) | (node->has_redirect_node << 3) | ((UTL_STRTOCSTR(node->suggestions_type) != NULL ? 1 : 0) << 4)
			);
			
			pck_write_var_int(cmd_graph, node->children.size);
			for (size_t j = 0; j < node->children.size; ++j) {
				int32_t child = UTL_VECTOR_GET_AS(int32_t, &node->children, j);
				pck_write_var_int(cmd_graph, child);
			}
			utl_term_vector(&node->children);

			if (node->has_redirect_node) {
				pck_write_var_int(cmd_graph, node->redirect_node);
			}

			switch (node->type) {
				case cmd_node_root: {
					// Do nothing
				} break;
				case cmd_node_literal: {
					pck_write_string(cmd_graph, UTL_STRTOARG(node->literal.name));
				} break;
				case cmd_node_argument: {
					pck_write_string(cmd_graph, UTL_STRTOARG(node->argument.name));
					pck_write_string(cmd_graph, UTL_STRTOARG(node->argument.parser));
				} break;
			}

			if (UTL_STRTOCSTR(node->suggestions_type) != NULL) {
				pck_write_string(cmd_graph, UTL_STRTOARG(node->suggestions_type));
			}

			free(node);

		}

		utl_term_vector(&nodes);

		pck_write_var_int(cmd_graph, 0);

	}

	return cmd_graph;

}

void cmd_reset_graph() {

	if (cmd_graph != NULL)
		free(cmd_graph);

}