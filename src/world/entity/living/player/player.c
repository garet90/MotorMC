#include "player.h"
#include "../../../../jobs/scheduler/scheduler.h"

uint16_t ent_player_get_break_speed(ent_player_t* player, mat_block_type_t block) {

	float32_t speed_multiplier = 1;

	const mat_block_t* block_data = mat_get_block_by_type(block);

	itm_item_t* held = &player->hotbar[player->held_item];
	const mat_item_t* held_data = mat_get_item_by_type(held->type);

	const bool is_best_tool = ent_player_is_best_tool(block_data, held_data);
	const bool can_harvest = ent_player_can_harvest(block_data, held_data);
	
	if (is_best_tool) {
		// TODO speed_multiplier = tool_power;
		if (!can_harvest) {
			speed_multiplier = 1;
		}
		// TODO efficiency
	}

	float32_t damage = speed_multiplier / block_data->hardness;

	if (can_harvest) {
		damage /= 30;
	} else {
		damage /= 100;
	}

	// instant break
	if (damage > 1) {
		return 0;
	}

	return utl_int_ceil(1 / damage);

}

void ent_free_player(ent_player_t* entity) {

	if (entity->digging_block) {
		sch_cancel(entity->digging);
	}

	ent_free_entity((ent_entity_t*) entity);

}