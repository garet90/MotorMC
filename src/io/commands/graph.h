#pragma once

#include "graph.d.h"

#include "../../main.h"
#include "../../util/vector.h"
#include "../packet/packet.h"
#include "commands.h"

struct cmd_node {

	int32_t idx;
	enum {
		
		cmd_node_root = 0,
		cmd_node_literal = 1,
		cmd_node_argument = 2

	} type : 2;
	bool is_executable : 1;
	bool has_redirect_node : 1;
	utl_vector_t children;
	int32_t redirect_node;

	union {

		struct {

			string_t name;

		} literal;

		struct {

			string_t name;
			string_t parser;
			string_t properties;

		} argument;

	};

	string_t suggestions_type;

};

extern pck_packet_t* cmd_get_graph();
extern void cmd_reset_graph();
