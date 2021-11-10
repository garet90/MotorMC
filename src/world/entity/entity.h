#pragma once
#include <pthread.h>
#include "../../main.h"
#include "../../io/chat/chat.h"
#include "../../util/lock_util.h"
#include "../positions.h"

typedef enum {

	ent_standing,
	ent_fall_flying,
	ent_sleeping,
	ent_spin_attack,
	ent_sneaking,
	ent_dying

} ent_pose_t;

typedef enum {

	ent_area_effect_cloud,
	ent_armor_stand,
	ent_arrow,
	ent_axolotl,
	ent_bat,
	ent_bee,
	ent_blaze,
	ent_boat,
	ent_cat,
	ent_cave_spider,
	ent_chicken,
	ent_cod,
	ent_cow,
	ent_creeper,
	ent_dolphin,
	ent_donkey,
	ent_dragon_fireball,
	ent_drowned,
	ent_elder_guardian,
	ent_end_crystal,
	ent_ender_dragon,
	ent_enderman,
	ent_endermite,
	ent_evoker,
	ent_evoker_fangs,
	ent_experience_orb,
	ent_eye_of_ender,
	ent_falling_block,
	ent_firework_rocket,
	ent_fox,
	ent_ghast,
	ent_giant,
	ent_glow_item_frame,
	ent_glow_squid,
	ent_goat,
	ent_guardian,
	ent_hoglin,
	ent_horse,
	ent_husk,
	ent_illusioner,
	ent_iron_golem,
	ent_item,
	ent_item_frame,
	ent_fireball,
	ent_leash_knot,
	ent_lightning_bolt,
	ent_llama,
	ent_llama_spit,
	ent_magma_cube,
	ent_marker,
	ent_minecart,
	ent_minecart_chest,
	ent_minecart_command_block,
	ent_minecart_furnace,
	ent_minecart_hopper,
	ent_minecart_spawner,
	ent_minecart_tnt,
	ent_mule,
	ent_mooshroom,
	ent_ocelot,
	ent_painting,
	ent_panda,
	ent_parrot,
	ent_phantom,
	ent_pig,
	ent_piglin,
	ent_piglin_brute,
	ent_pillager,
	ent_polar_bear,
	ent_tnt,
	ent_pufferfish,
	ent_rabbit,
	ent_ravager,
	ent_salmon,
	ent_sheep,
	ent_shulker,
	ent_shulker_bullet,
	ent_silverfish,
	ent_skeleton,
	ent_skeleton_horse,
	ent_slime,
	ent_small_fireball,
	ent_snow_golem,
	ent_snowball,
	ent_spectral_arrow,
	ent_spider,
	ent_squid,
	ent_stray,
	ent_strider,
	ent_thrown_egg,
	ent_thrown_ender_pearl,
	ent_thrown_experience_bottle,
	ent_thrown_potion,
	ent_thrown_trident,
	ent_trader_llama,
	ent_tropical_fish,
	ent_turtle,
	ent_vex,
	ent_villager,
	ent_vindicator,
	ent_wandering_trader,
	ent_witch,
	ent_wither,
	ent_wither_skeleton,
	ent_wither_skull,
	ent_wolf,
	ent_zoglin,
	ent_zombie,
	ent_zombie_horse,
	ent_zombie_villager,
	ent_zombified_piglin,
	ent_player,
	ent_fishing_hook

} ent_type_t;

typedef struct {

	wld_position_t position;
	wld_chunk_t* _Atomic chunk;
	uint32_t _Atomic chunk_node;

	const uint32_t id;
	const ent_type_t type;

	pthread_mutex_t lock;

	cht_component_t custom_name;
	uint16_t air_ticks;
	ent_pose_t pose : 5;

	bool on_fire : 1;
	bool crouching : 1;
	bool sprinting : 1;
	bool swimming : 1;
	bool invisible : 1;
	bool glowing : 1;
	
	bool flying_with_elytra : 1;
	bool custom_name_visible : 1;
	bool silent : 1;
	bool no_gravity : 1;
	bool on_ground : 1;
	uint8_t powder_snow_ticks;

} ent_entity_t;

extern uint32_t ent_register_entity(ent_entity_t* entity);
extern ent_entity_t* ent_get_entity_by_id(uint32_t id);

static inline void ent_remove_chunk(ent_entity_t* entity) {

	if (entity->chunk != NULL) {

		wld_chunk_remove_entity(entity->chunk, entity->chunk_node);
		entity->chunk = NULL;

	}

}

extern void ent_destroy_entity(uint32_t client_id, void* entity);
extern void ent_send_entity(uint32_t client_id, void* entity);

extern void ent_set_chunk(ent_entity_t* entity);

static inline void ent_on_ground(ent_entity_t* entity, bool on_ground) {
	
	entity->on_ground = on_ground;

}

extern void ent_free_entity(ent_entity_t* entity);
