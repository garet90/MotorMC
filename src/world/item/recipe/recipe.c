#include "../../../util/str_util.h"
#include "recipe.h"

utl_vector_t rec_recipes = {
	.bytes_per_element = sizeof(rec_recipe_t*)
};

void rec_serialize(pck_packet_t* packet, const rec_recipe_t* recipe) {

	const string_t types[] = {
		UTL_CSTRTOSTR("crafting_shapeless"),
		UTL_CSTRTOSTR("crafting_shaped"),
		UTL_CSTRTOSTR("crafting_special_armordye"),
		UTL_CSTRTOSTR("crafting_special_bookcloning"),
		UTL_CSTRTOSTR("crafting_special_mapcloning"),
		UTL_CSTRTOSTR("crafting_special_mapextending"),
		UTL_CSTRTOSTR("crafting_special_firework_rocket"),
		UTL_CSTRTOSTR("crafting_special_firework_star"),
		UTL_CSTRTOSTR("crafting_special_firework_star_fade"),
		UTL_CSTRTOSTR("crafting_special_repairitem"),
		UTL_CSTRTOSTR("crafting_special_tippedarrow"),
		UTL_CSTRTOSTR("crafting_special_bannerduplicate"),
		UTL_CSTRTOSTR("crafting_special_banneraddpattern"),
		UTL_CSTRTOSTR("crafting_special_shielddecoration"),
		UTL_CSTRTOSTR("crafting_special_shulkerboxcoloring"),
		UTL_CSTRTOSTR("crafting_special_suspiciousstew"),
		UTL_CSTRTOSTR("smelting"),
		UTL_CSTRTOSTR("blasting"),
		UTL_CSTRTOSTR("smoking"),
		UTL_CSTRTOSTR("campfire_cooking"),
		UTL_CSTRTOSTR("stonecutting"),
		UTL_CSTRTOSTR("smithing")
	};

	pck_write_string(packet, UTL_STRTOARG(types[recipe->type]));
	pck_write_string(packet, UTL_STRTOARG(recipe->recipe_id));

	switch (recipe->type) {
		case rec_crafting_shapeless: {
			pck_write_string(packet, UTL_STRTOARG(recipe->data.crafting_shapeless.group));
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
			pck_write_string(packet, UTL_STRTOARG(recipe->data.crafting_shaped.group));
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
			pck_write_string(packet, UTL_STRTOARG(recipe->data.smelting.group));
			pck_write_var_int(packet, recipe->data.smelting.ingredient_count);
			itm_serialize(packet, &recipe->data.smelting.ingredient);
			itm_serialize(packet, &recipe->data.smelting.result);
			pck_write_float32(packet, recipe->data.smelting.experience);
			pck_write_var_int(packet, recipe->data.smelting.cooking_time);
		} break;
		case rec_stonecutting: {
			pck_write_string(packet, UTL_STRTOARG(recipe->data.stonecutting.group));
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