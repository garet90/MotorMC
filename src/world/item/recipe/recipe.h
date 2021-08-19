#pragma once
#include "../../../main.h"
#include "../../../util/vector.h"
#include "../item.h"

typedef enum {

	rec_crafting_shapeless,
	rec_crafting_shaped,
	rec_crafting_special_armordye,
	rec_crafting_special_bookcloning,
	rec_crafting_special_mapcloning,
	rec_crafting_special_mapextending,
	rec_crafting_special_firework_rocket,
	rec_crafting_special_firework_star,
	rec_crafting_special_firework_star_fade,
	rec_crafting_special_repairitem,
	rec_crafting_special_tippedarrow,
	rec_crafting_special_bannerduplicate,
	rec_crafting_special_banneraddpattern,
	rec_crafting_special_shielddecoration,
	rec_crafting_special_shulkerboxcoloring,
	rec_crafting_special_suspiciousstew,
	rec_smelting,
	rec_blasting,
	rec_smoking,
	rec_campfire_cooking,
	rec_stonecutting,
	rec_smithing

} rec_recipe_type_t;

typedef struct {

	rec_recipe_type_t type : 5;
	const char* recipe_id;

	union {

		struct {

			const char* group;
			itm_item_t result;

			size_t ingredient_count;
			struct {
				size_t count;
				itm_item_t ingredient;
			} ingredients[];

		} crafting_shapeless;

		struct {

			const char* group;
			itm_item_t result;

			uint8_t width : 2;
			uint8_t height : 2;

			struct {
				size_t count;
				itm_item_t ingredient;
			} ingredients[];

		} crafting_shaped;

		struct {

			const char* group;
			size_t ingredient_count;
			itm_item_t ingredient;

			itm_item_t result;
			float32_t experience;
			uint32_t cooking_time;

		} smelting;

		struct {

			const char* group;
			size_t ingredient_count;
			itm_item_t ingredient;

			itm_item_t result;

		} stonecutting;

		struct {

			size_t base_count;
			itm_item_t base;

			size_t addition_count;
			itm_item_t addition;

			itm_item_t result;

		} smithing;

	} data;

} rec_recipe_t;

extern utl_vector_t rec_recipes;

extern void rec_serialize(pck_packet_t* packet, const rec_recipe_t* recipe);