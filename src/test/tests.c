#include "tests.h"
#include "../io/logger/logger.h"
#include "../util/util.h"
#include "../world/material/material.h"

bool_t test_materials() {

    uint16_t protocolID = 0;
    uint16_t protocolJump;
    // test to make sure the number
    // of states is equal to state map
    for (uint16_t i = 0; i < 898; ++i, protocolID += protocolJump) {

        mat_block_id_t id = mat_getIdByProtocol(protocolID);
        const mat_block_t* block = mat_getBlockById(id);

        protocolJump = 1;

        for (uint16_t j = 0; j < block->modifiers_count; ++j) {

            protocolJump *= mat_getStateModifierByType(block->modifiers[j])->count;

            if (mat_getIdByProtocol(protocolID + protocolJump - 1) != id) {
                log_error("Failed at block ID %d", id);
                log_error("\tProtocol jump: %d", protocolJump);
                return false;
            }

        }
        
        if (mat_getIdByProtocol(protocolID + protocolJump) == id) {
            log_error("Failed at block ID %d", id);
            log_error("\tState missing!");
            return false;
        }

    }

    return true;

}

bool_t test_runAll() {

    log_info("Running materials test...");
    if (test_materials()) {
        log_info("Material test passed.");
    } else {
        return false;
    }

    return false;

}