#include "tests.h"
#include <stdlib.h>
#include <inttypes.h>
#include "../io/logger/logger.h"
#include "../io/packet/packet.h"
#include "../util/util.h"
#include "../util/str_util.h"
#include "../world/material/material.h"
#include "../world/world.h"

bool test_materials() {

	// test that protocol map is correct
	uint16_t protocolID = 0;
	uint16_t protocolJump;
	// test to make sure the number
	// of states is equal to state map
	for (uint16_t i = 0; i < mat_block_count; ++i, protocolID += protocolJump) {

		mat_block_type_t id = mat_get_block_type_by_protocol_id(protocolID);
		const mat_block_t* block = mat_get_block_by_type(id);

		protocolJump = 1;

		for (uint16_t j = 0; j < block->modifiers_count; ++j) {

			protocolJump *= mat_get_state_modifier_by_type(block->modifiers[j])->count;

			if (mat_get_block_type_by_protocol_id(protocolID + protocolJump - 1) != id) {
				log_error("Failed at block ID %d", id);
				log_error("\tProtocol jump: %d", protocolJump);
				return false;
			}

		}
		
		if (mat_get_block_type_by_protocol_id(protocolID + protocolJump) == id) {
			log_error("Failed at block ID %d", id);
			log_error("\tState missing!");
			return false;
		}

	}

	// test that base protocol is correct
	for (uint16_t i = 0; i < mat_block_count; ++i) {

		uint16_t protocol = mat_get_block_base_protocol_id_by_type(i);

		if (mat_get_block_type_by_protocol_id(protocol) != i) {
			log_error("Base protocol is incorrect!");
			log_error("\tBlock ID %d", i);
			log_error("\tProtocol ID %d", protocol);
			return false;
		}

		if (protocol > 0) {
			if (mat_get_block_type_by_protocol_id(protocol - 1) == i) {
				log_error("Base protocol is incorrect!");
				log_error("\tBase protocol offset incorrect!");
				log_error("\tBlock ID %d", i);
				return false;
			}
		}

	}

	// test material
	mat_block_type_t block_id = mat_block_chest;
	mat_block_protocol_id_t protocol_id = mat_get_block_base_protocol_id_by_type(block_id);
	
	protocol_id = mat_set_block_state_value(protocol_id, mat_state_modifier_waterlogged, 1);
	protocol_id = mat_set_block_state_value(protocol_id, mat_state_modifier_chest_type, 2);

	if (mat_get_block_state_value(protocol_id, mat_state_modifier_chest_type) != 2 || mat_get_block_state_value(protocol_id, mat_state_modifier_waterlogged) != 1) {
		log_error("Setting or getting states failed!");
		return false;
	}

	return true;

}

bool test_packets() {

	PCK_INLINE(packet, 1024, io_big_endian);

	pck_write_int8(packet, 0x11);
	pck_write_int16(packet, 0x2233);
	pck_write_int32(packet, 0x44556677);
	pck_write_int64(packet, 0x8899AABBCCDDEEL);
	pck_write_float32(packet, 0.1234);
	pck_write_float64(packet, 5.6789);
	pck_write_var_int(packet, 0x1a2b);
	pck_write_var_int(packet, -1);
	pck_write_var_long(packet, 0x3c4d5e6f1234L);
	pck_write_position(packet, (pck_position_t) { .x = 1, .y = 2, .z = 3});
	pck_write_string(packet, UTL_CSTRTOARG("test string"));

	packet->cursor = 0;

	if (pck_read_int8(packet) != 0x11) {
		log_error("FAIL ON INT8");
		return false;
	}

	if (pck_read_int16(packet) != 0x2233) {
		log_error("FAIL ON INT16");
		return false;
	}

	if (pck_read_int32(packet) != 0x44556677) {
		log_error("FAIL ON INT32");
		return false;
	}

	if (pck_read_int64(packet) != 0x8899AABBCCDDEEL) {
		log_error("FAIL ON INT64");
		return false;
	}

	if (utl_fabs(pck_read_float32(packet) - 0.1234) > 0.0001) {
		log_error("FAIL ON FLOAT32");
		return false;
	}

	if (utl_dabs(pck_read_float64(packet) - 5.6789) > 0.0001) {
		log_error("FAIL ON FLOAT64");
		return false;
	}

	if (pck_read_var_int(packet) != 0x1a2b) {
		log_error("FAIL ON VAR INT");
		return false;
	}

	if (pck_read_var_int(packet) != -1) {
		log_error("FAIL ON NEGATIVE VAR INT");
		return false;
	}

	const int64_t var_long = pck_read_var_long(packet);
	if (var_long != 0x3c4d5e6f1234L) {
		pck_log(packet);
		log_error("FAIL ON VAR LONG (0x%" PRIx64 " vs 0x3c4d5e6f1234)", var_long);
		return false;
	}

	pck_position_t position = pck_read_position(packet);

	if (position.x != 1 || position.y != 2 || position.z != 3) {
		log_error("FAIL ON POSITION");
		return false;
	}

	PCK_READ_STRING(string, packet);

	if (strcmp(string, "test string") != 0) {
		log_error("FAIL ON STRING");
		return false;
	}
	
	return true;

}

bool test_worlds() {

	for (uint32_t i = 0; i < 10; ++i) {
		wld_new(UTL_CSTRTOSTR("world"), i, mat_dimension_overworld);
		wld_unload_all();
	}

	return true;

}

typedef struct {
	bool (*func)();
	string_t label;
} test_t;

int test_run_all() {

	const test_t tests[] = {
		(test_t) {
			.func = test_materials,
			.label = UTL_CSTRTOSTR("materials")
		},
		(test_t) {
			.func = test_packets,
			.label = UTL_CSTRTOSTR("packets")
		},
		(test_t) {
			.func = test_worlds,
			.label = UTL_CSTRTOSTR("worlds")
		}
	};

	const size_t test_count = sizeof(tests) / sizeof(tests[0]);

	log_info("Running %zu tests", test_count);

	for (size_t i = 0; i < test_count; ++i) {
		log_info("Running test \"%s\"...", UTL_STRTOCSTR(tests[i].label));
		if (tests[i].func()) {
			log_info("Test passed");
		} else {
			return EXIT_FAILURE;
		}
	}

	log_info("All tests passed.");

	return EXIT_SUCCESS;

}