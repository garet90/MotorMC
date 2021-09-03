#include "tests.h"
#include <stdlib.h>
#include "../io/logger/logger.h"
#include "../util/util.h"
#include "../world/material/material.h"

bool test_materials() {

	// test that protocol map is correct
	uint16_t protocolID = 0;
	uint16_t protocolJump;
	// test to make sure the number
	// of states is equal to state map
	for (uint16_t i = 0; i < mat_block_count; ++i, protocolID += protocolJump) {

		mat_block_type_t id = mat_get_block_id_by_protocol_id(protocolID);
		const mat_block_t* block = mat_get_block_by_id(id);

		protocolJump = 1;

		for (uint16_t j = 0; j < block->modifiers_count; ++j) {

			protocolJump *= mat_get_state_modifier_by_type(block->modifiers[j])->count;

			if (mat_get_block_id_by_protocol_id(protocolID + protocolJump - 1) != id) {
				log_error("Failed at block ID %d", id);
				log_error("\tProtocol jump: %d", protocolJump);
				return false;
			}

		}
		
		if (mat_get_block_id_by_protocol_id(protocolID + protocolJump) == id) {
			log_error("Failed at block ID %d", id);
			log_error("\tState missing!");
			return false;
		}

	}

	// test that base protocol is correct
	for (uint16_t i = 0; i < mat_block_count; ++i) {

		uint16_t protocol = mat_get_block_base_protocol_id_by_id(i);

		if (mat_get_block_id_by_protocol_id(protocol) != i) {
			log_error("Base protocol is incorrect!");
			log_error("\tBlock ID %d", i);
			log_error("\tProtocol ID %d", protocol);
			return false;
		}

		if (protocol > 0) {
			if (mat_get_block_id_by_protocol_id(protocol - 1) == i) {
				log_error("Base protocol is incorrect!");
				log_error("\tBase protocol offset incorrect!");
				log_error("\tBlock ID %d", i);
				return false;
			}
		}

	}

	// test material
	mat_block_type_t block_id = mat_block_chest;
	mat_block_protocol_id_t protocol_id = mat_get_block_base_protocol_id_by_id(block_id);
	
	protocol_id = mat_set_block_state_value(protocol_id, mat_state_modifier_waterlogged, 1);
	protocol_id = mat_set_block_state_value(protocol_id, mat_state_modifier_chest_type, 2);

	if (mat_get_block_state_value(protocol_id, mat_state_modifier_chest_type) != 2 || mat_get_block_state_value(protocol_id, mat_state_modifier_waterlogged) != 1) {
		log_error("Setting or getting states failed!");
		return false;
	}

	return true;

}

int test_run_all() {

	log_info("Running materials test...");
	if (test_materials()) {
		log_info("Material test passed.");
	} else {
		return 1;
	}

	log_info("All tests passed.");

	return 0;

}