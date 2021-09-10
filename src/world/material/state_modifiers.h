#pragma once
#include "../../main.h"

/*
	STATE MODIFIERS
	State modifiers are used to determine the state
*/

typedef enum {

		// north
		// south
		// east
		// west
	mat_state_modifier_facing_cardinal,
		
		// down
		// east
		// north
		// south
		// up
		// west
	mat_state_modifier_facing,
		
		// 0 - 15
	mat_state_modifier_rotation,
		
		// true
		// false
	mat_state_modifier_open,
		
		// true
		// false
	mat_state_modifier_powered,
		
		// true
		// false
	mat_state_modifier_lit,
		
		// x
		// y
		// z
	mat_state_modifier_axis,
		
		// x
		// z
	mat_state_modifier_cardinal_axis,
		
		// ceiling
		// floor
		// wall
	mat_state_modifier_face,
		
		// true
		// false
	mat_state_modifier_waterlogged,
		
		// true
		// false
	mat_state_modifier_down,
		
		// true
		// false
	mat_state_modifier_east,
		
		// true
		// false
	mat_state_modifier_north,
		
		// true
		// false
	mat_state_modifier_south,
		
		// true
		// false
	mat_state_modifier_up,
		
		// true
		// false
	mat_state_modifier_west,
		
		// 0 - 15
	mat_state_modifier_power,
		
		// true
		// false
	mat_state_modifier_triggered,
		
		// 0 - 7
	mat_state_modifier_crop_age,
		
		// 0 - 7
	mat_state_modifier_distance,
		
		// 0 - 15
	mat_state_modifier_stock_age,
		
		// 0 - 15
	mat_state_modifier_liquid_level,
		
		// lower
		// upper
	mat_state_modifier_plant_half,
	
		// 0 or 1
	mat_state_modifier_bamboo_age,
		
		// large
		// none
		// small
	mat_state_modifier_bamboo_leaves,
		
		// 0 or 1
	mat_state_modifier_bamboo_stage,
		
		// true
		// false
	mat_state_modifier_bed_occupied,
		
		// foot
		// head
	mat_state_modifier_bed_part,
		
		// 0 - 5
	mat_state_modifier_hive_honey_level,
		
		// 0 - 3
	mat_state_modifier_beetroot_age,
		
		// true
		// false
	mat_state_modifier_brewing_stand_has_bottle_0,
		
		// true
		// false
	mat_state_modifier_brewing_stand_has_bottle_1,
		
		// true
		// false
	mat_state_modifier_brewing_stand_has_bottle_2,
		
		// true
		// false
	mat_state_modifier_bubble_column_drag,
		
		// true
		// false
	mat_state_modifier_campfire_signal,
		
		// 0 - 6
	mat_state_modifier_cake_bites,
		
		// 0 - 3
	mat_state_modifier_cauldron_level,
		
		// left
		// right
		// single
	mat_state_modifier_chest_type,
		
		// 0 - 5
	mat_state_modifier_chorus_flower_age,
		
		// 0 - 2
	mat_state_modifier_cocoa_age,
		
		// true
		// false
	mat_state_modifier_command_block_conditional,
		
		// 0 - 8
	mat_state_modifier_composter_level,

		// true
		// false
	mat_state_modifier_daylight_detector_inverted,
		
		// lower
		// upper
	mat_state_modifier_door_half,
		
		// left
		// right
	mat_state_modifier_door_hinge,
		
		// true
		// false
	mat_state_modifier_door_open,
		
		// true
		// false
	mat_state_modifier_end_portal_frame_eye,
		
		// 0 - 7
	mat_state_modifier_farmland_moisture,
		
		// true
		// false
	mat_state_modifier_fencegate_in_wall,
		
		// 0 - 15
	mat_state_modifier_fire_age,
		
		// 0 - 3
	mat_state_modifier_frosted_ice_age,
		
		// true
		// false
	mat_state_modifier_grass_snowy,
		
		// true
		// false
	mat_state_modifier_hopper_enabled,
		
		// down_east
		// down_north
		// down_south
		// down_west
		// east_up
		// north_up
		// south_up
		// up_east
		// up_north
		// up_south
		// up_west
		// west_up
	mat_state_modifier_jigsaw_facing,
		
		// true
		// false
	mat_state_modifier_jukebox_has_record,

		// 0 - 25
	mat_state_modifier_vine_age,
		
		// 0 - 1
	mat_state_modifier_lantern_hanging,
		
		// true
		// false
	mat_state_modifier_leaves_persistant,
		
		// true
		// false
	mat_state_modifier_lectern_has_book,
		
		// 0 - 3
	mat_state_modifier_nether_wart_age,
		
		// banjo
		// basedrum
		// base
		// bell
		// bit
		// chime
		// cow_bell
		// didgeridoo
		// flute
		// guitar
		// harp
		// hat
		// iron_xylophone
		// pling
		// snare
		// xylophone
	mat_state_modifier_note_block_instrument,
		
		// 0 - 24
	mat_state_modifier_note_block_note,
		
		// true
		// false
	mat_state_modifier_piston_extended,

		// normal or sticky
	mat_state_modifier_piston_type,
		
		// true
		// false
	mat_state_modifier_piston_short,
		
		// east_west
		// north_east
		// north_south
		// north_west
		// south_east
		// south_west
		// ascending_east
		// ascending_north
		// ascending_south
		// ascending_west
	mat_state_modifier_rail_shape,
		
		// east_west
		// north_south
		// ascending_east
		// ascending_north
		// ascending_south
		// ascending_west
	mat_state_modifier_special_rail_shape,
		
		// compare
		// subtract
	mat_state_modifier_comparator_mode,
		
		// none
		// side
		// up
	mat_state_modifier_redstone_east,
		
		// none
		// side
		// up
	mat_state_modifier_redstone_north,
		
		// none
		// side
		// up
	mat_state_modifier_redstone_south,
		
		// none
		// side
		// up
	mat_state_modifier_redstone_west,
		
		// 1 - 4
	mat_state_modifier_repeater_delay,
		
		// true
		// false
	mat_state_modifier_repeater_locked,
		
		// 0 - 4
	mat_state_modifier_respawn_anchor_charges,
		
		// 0
		// 1
	mat_state_modifier_sapling_stage,
		
		// true
		// false
	mat_state_modifier_scaffolding_bottom,
		
		// 1 - 4
	mat_state_modifier_sea_pickle_pickles,
		
		// bottom
		// top
		// double
	mat_state_modifier_slab_type,
		
		// 1 - 8
	mat_state_modifier_snow_layers,
		
		// bottom
		// top
	mat_state_modifier_stairs_half,
		
		// inner_left
		// inner_right
		// outer_left
		// outer_right
		// straight
	mat_state_modifier_stairs_shape,
		
		// corner
		// data
		// load
		// save
	mat_state_modifier_structure_block_mode,

		// 0 - 3
	mat_state_modifier_sweet_berry_bush_age,

		// true
		// false
	mat_state_modifier_tnt_unstable,

		// bottom
		// top
	mat_state_modifier_trapdoor_half,
		
		// true
		// false
	mat_state_modifier_trapdoor_open,
		
		// true
		// false
	mat_state_modifier_tripwire_attached,
		
		// true
		// false
	mat_state_modifier_tripwire_disarmed,

		// 1 - 4
	mat_state_modifier_turtle_egg_eggs,

		// 0 - 2
	mat_state_modifier_turtle_egg_hatch,

		// low
		// none
		// tall
	mat_state_modifier_wall_east,

		// low
		// none
		// tall
	mat_state_modifier_wall_north,

		// low
		// none
		// tall
	mat_state_modifier_wall_south,

		// low
		// none
		// tall
	mat_state_modifier_wall_west,

		// floor
		// seiling
		// double_wall
		// single_wall
	mat_state_modifier_bell_attachment,

		// down
		// east
		// north
		// south
		// west
	mat_state_modifier_hopper_facing,

		// 0 - 15
	mat_state_modifier_light_level,

		// 0 - 7
	mat_state_modifier_scaffolding_distance,

		// 1 - 4
	mat_state_modifier_candle_candles,

		// inactive
		// active
		// cooldown
	mat_state_modifier_sculk_sensor_phase,

		// tip_merge
		// tip
		// frustum
		// middle
		// base
	mat_state_modifier_dripstone_thickness,

		// up
		// down
	mat_state_modifier_dripstone_direction,

		// true
		// false
	mat_state_modifier_cave_vines_berries,

		// none
		// unstable
		// partial
		// full
	mat_state_modifier_dripleaf_tilt,

} mat_state_modifier_type_t;

typedef struct {

	uint8_t count;

} mat_state_modifier_t;

extern const mat_state_modifier_t* mat_modifiers[];

static inline const mat_state_modifier_t* mat_get_state_modifier_by_type(mat_state_modifier_type_t type) {
	return mat_modifiers[type];
}