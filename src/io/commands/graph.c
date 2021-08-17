#include "graph.h"

pck_packet_t* cmd_graph = NULL;

pck_packet_t* cmd_get_graph() {

	if (cmd_graph == NULL) {

		utl_vector_t nodes = {
			.bytes_per_element = sizeof(cmd_node_t*)
		};

		cmd_node_t* root = calloc(1, sizeof(cmd_node_t));
		root->type = cmd_node_root;
		root->idx = nodes.size;
		root->children.bytes_per_element = sizeof(int32_t);

		utl_vector_push(&nodes, &root);

		for (size_t i = 0; i < cmd_list.size; ++i) {
			cmd_command_t* command = UTL_VECTOR_GET_AS(cmd_command_t*, &cmd_list, i);
			
			cmd_node_t* command_node = calloc(1, sizeof(cmd_node_t));
			command_node->type = cmd_node_literal;
			command_node->children.bytes_per_element = sizeof(int32_t);
			command_node->literal.name = command->label;
			command_node->idx = nodes.size;

			utl_vector_push(&nodes, &command_node);
			utl_vector_push(&root->children, &command_node->idx);

			// aliases
			for (size_t j = 0; j < command->alias_count; ++j) {

				cmd_node_t* command_alias = calloc(1, sizeof(cmd_node_t));
				command_alias->type = cmd_node_literal;
				command_alias->children.bytes_per_element = sizeof(int32_t);
				command_alias->redirect_node = command_node->idx;
				command_alias->has_redirect_node = true;
				command_alias->literal.name = command->aliases[j];
				command_alias->idx = nodes.size;

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
				node->type | (node->is_executable << 2) | (node->has_redirect_node << 3) | ((node->suggestions_type != NULL ? 1 : 0) << 4)
			);
			
			pck_write_var_int(cmd_graph, node->children.size);
			for (size_t i = 0; i < node->children.size; ++i) {
				int32_t child = UTL_VECTOR_GET_AS(int32_t, &node->children, i);
				pck_write_var_int(cmd_graph, child);
			}
			utl_vector_term(&node->children);

			if (node->has_redirect_node) {
				pck_write_var_int(cmd_graph, node->redirect_node);
			}

			switch (node->type) {
				case cmd_node_root:
					break;
				case cmd_node_literal:
					pck_write_string(cmd_graph, node->literal.name, strlen(node->literal.name));
					break;
				case cmd_node_argument:
					pck_write_string(cmd_graph, node->argument.name, strlen(node->argument.name));
					pck_write_string(cmd_graph, node->argument.parser, strlen(node->argument.parser));
					break;
			}

			if (node->suggestions_type != NULL) {
				pck_write_string(cmd_graph, node->suggestions_type, strlen(node->suggestions_type));
			}

			free(node);

		}

		utl_vector_term(&nodes);

		pck_write_var_int(cmd_graph, 0);

	}

	return cmd_graph;

}

void cmd_reset_graph() {

	if (cmd_graph != NULL)
		free(cmd_graph);

}