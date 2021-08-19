#include <string.h>
#include "recipe.h"

utl_vector_t rec_recipes = {
	.bytes_per_element = sizeof(rec_recipe_t*)
};

void rec_serialize(pck_packet_t* packet, const rec_recipe_t* recipe) {

	const char* types[] = {
		"crafting_shapeless",
		"crafting_shaped",
		"crafting_special_armordye",
		"crafting_special_bookcloning",
		"crafting_special_mapcloning",
		"crafting_special_mapextending",
		"crafting_special_firework_rocket",
		"crafting_special_firework_star",
		"crafting_special_firework_star_fade",
		"crafting_special_repairitem",
		"crafting_special_tippedarrow",
		"crafting_special_bannerduplicate",
		"crafting_special_banneraddpattern",
		"crafting_special_shielddecoration",
		"crafting_special_shulkerboxcoloring",
		"crafting_special_suspiciousstew",
		"smelting",
		"blasting",
		"smoking",
		"campfire_cooking",
		"stonecutting",
		"smithing"
	};

	pck_write_string(packet, types[recipe->type], strlen(types[recipe->type]));
	pck_write_string(packet, recipe->recipe_id, strlen(recipe->recipe_id));

	switch (recipe->type) {
		case rec_crafting_shapeless: {
			pck_write_string(packet, recipe->data.crafting_shapeless.group, strlen(recipe->data.crafting_shapeless.group));
			pck_write_var_int(packet, recipe->data.crafting_shapeless.ingredient_count);
			for (size_t i = 0; i < recipe->data.crafting_shapeless.ingredient_count; ++i) {
				pck_write_var_int(packet, recipe->data.crafting_shapeless.ingredients[i].count);
				itm_serialize(packet, &recipe->data.crafting_shapeless.ingredients[i].ingredient);
			}
			itm_serialize(packet, &recipe->data.crafting_shapeless.result);
		} break;
		case rec_crafting_shaped: {
			pck_write_var_int(packet, recipe->data.crafting_shaped.width);
			pck_write_var_int(packet, recipe->data.crafting_shaped.height);
			pck_write_string(packet, recipe->data.crafting_shaped.group, strlen(recipe->data.crafting_shaped.group));
			for (size_t i = 0; i < recipe->data.crafting_shaped.width * recipe->data.crafting_shaped.height; ++i) {
				pck_write_var_int(packet, recipe->data.crafting_shaped.ingredients[i].count);
				itm_serialize(packet, &recipe->data.crafting_shaped.ingredients[i].ingredient);
			}
			itm_serialize(packet, &recipe->data.crafting_shaped.result);
		} break;
		case rec_smelting:
		case rec_blasting:
		case rec_smoking:
		case rec_campfire_cooking: {
			pck_write_string(packet, recipe->data.smelting.group, strlen(recipe->data.smelting.group));
			pck_write_var_int(packet, recipe->data.smelting.ingredient_count);
			itm_serialize(packet, &recipe->data.smelting.ingredient);
			itm_serialize(packet, &recipe->data.smelting.result);
			pck_write_float32(packet, recipe->data.smelting.experience);
			pck_write_var_int(packet, recipe->data.smelting.cooking_time);
		} break;
		case rec_stonecutting: {
			pck_write_string(packet, recipe->data.stonecutting.group, strlen(recipe->data.stonecutting.group));
			pck_write_var_int(packet, recipe->data.stonecutting.ingredient_count);
			itm_serialize(packet, &recipe->data.stonecutting.ingredient);
			itm_serialize(packet, &recipe->data.stonecutting.result);
		} break;
		case rec_smithing: {
			pck_write_var_int(packet, recipe->data.smithing.base_count);
			itm_serialize(packet, &recipe->data.smithing.base);
			pck_write_var_int(packet, recipe->data.smithing.addition_count);
			itm_serialize(packet, &recipe->data.smithing.addition);
			itm_serialize(packet, &recipe->data.smithing.result);
		} break;
		default: break;
	}

}