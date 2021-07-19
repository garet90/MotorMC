#include "material.h"


const mat_hitbox_t mat_hitboxes[] = {

		{ // full block
				.x = 0,
				.y = 0,
				.z = 0,
				.length = 1,
				.width = 1,
				.height = 1
		},
		{ // lower half slab
				.x = 0,
				.y = 0,
				.z = 0,
				.length = 1,
				.width = 1,
				.height = 0.5
		},
		{ // upper half slab
				.x = 0,
				.y = 0.5,
				.z = 0,
				.length = 1,
				.width = 1,
				.height = 0.5
		}

};


// STATE PROPERTIES

const mat_modifier_t mat_modifier_half = {

		.properties_size = 2,
		.properties = {

				{
						.hitbox = 1
				},

				{
						.hitbox = 2
				}

		}

};

const mat_modifier_t* mat_modifiers[] = {

		&mat_modifier_half

};


// BLOCK ENTITIES

const mat_block_entity_t* mat_block_entities[] = {
	NULL
};


// BLOCKS

const mat_block_t mat_air = {
	.light = 0x00
};

const mat_block_t* mat_blocks[] = {

		&mat_air

};
