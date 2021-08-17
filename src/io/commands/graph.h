#pragma once
#include "../../main.h"
#include "../../util/vector.h"
#include "../packet/packet.h"
#include "commands.h"

typedef enum {
	
	cmd_node_root = 0,
	cmd_node_literal = 1,
	cmd_node_argument = 2

} cmd_node_type_t;

typedef struct cmd_node cmd_node_t;

struct cmd_node {

	int32_t idx;
	cmd_node_type_t type : 2;
	bool_t is_executable : 1;
	bool_t has_redirect_node : 1;
	utl_vector_t children;
	int32_t redirect_node;

	union {

		struct {

			const char* name;

		} literal;

		struct {

			const char* name;
			const char* parser;
			const char* properties;

		} argument;

	};

	const char* suggestions_type;

};

extern pck_packet_t* cmd_get_graph();
extern void cmd_reset_graph();
