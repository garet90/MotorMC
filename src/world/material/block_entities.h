#pragma once

/*
	BLOCK ENTITIES
	Block entities are used to store extra information that couldn't be stored in states
*/

typedef enum {

	mat_block_entity_none = 0,
	mat_block_entity_bees, // store bees in a block
	mat_block_entity_sign, // store sign text
	mat_block_entity_banner, // store patterns

	mat_block_entity_container, // store inventory slots
		mat_block_entity_furnace, // store time until current item is smelted and time until fuel is exhausted
		mat_block_entity_brewing, // store brewing time
		mat_block_entity_hopper, // store time until next transfer
		mat_block_entity_locational_container, // store location for opening and closing
		mat_block_entity_lectern, // store current page

	mat_block_entity_beacon, // store pyramid leve, active effects, contents, and beacon beam position
	mat_block_entity_spawner, // store spawner information
	mat_block_entity_piston_extension, // store the blocks they are moving
	mat_block_entity_jukebox, // store music disks
	mat_block_entity_enchanting_table, // to store the floating book
	mat_block_entity_end_particles, // to store particles for end chests and portalls
	mat_block_entity_head, // store the head type
	mat_block_entity_command, // store command text
	mat_block_entity_gateway, // store teleport location
	mat_block_entity_structure, // to store structure info
	mat_block_entity_jigsaw, // to store structure pool
	mat_block_entity_daylight, // to force output signal
	mat_block_entity_comparator, // to store output strength
	mat_block_entity_bed, // for rendering
	mat_block_entity_conduit, // to check activation
	mat_block_entity_bell // to render bell sway

} mat_block_entity_type_t;