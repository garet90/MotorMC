#include <stdlib.h>
#include "../../util/str_util.h"
#include "../../main.h"
#include "../../io/nbt/mnbt.h"
#include "codec.h"
#include "biomes.h"

mat_codec_t* mat_codec = NULL;

mat_codec_t* mat_dimension_codec[mat_dimension_count] = {};

const mat_codec_t* mat_get_codec() {
	
	const string_t precipitation_types[] = {
		UTL_CSTRTOSTR("rain"),
		UTL_CSTRTOSTR("snow"),
		UTL_CSTRTOSTR("none")
	};

	const string_t biome_categories[] = {
		UTL_CSTRTOSTR("none"),
		UTL_CSTRTOSTR("ocean"),
		UTL_CSTRTOSTR("plains"),
		UTL_CSTRTOSTR("desert"),
		UTL_CSTRTOSTR("forest"),
		UTL_CSTRTOSTR("extreme_hills"),
		UTL_CSTRTOSTR("taiga"),
		UTL_CSTRTOSTR("swamp"),
		UTL_CSTRTOSTR("river"),
		UTL_CSTRTOSTR("nether"),
		UTL_CSTRTOSTR("the_end"),
		UTL_CSTRTOSTR("icy"),
		UTL_CSTRTOSTR("mushroom"),
		UTL_CSTRTOSTR("beach"),
		UTL_CSTRTOSTR("jungle"),
		UTL_CSTRTOSTR("mesa"),
		UTL_CSTRTOSTR("savanna"),
		UTL_CSTRTOSTR("underground"),
		UTL_CSTRTOSTR("mountain"),
	};

	const string_t grass_color_modifiers[] = {
		UTL_CSTRTOSTR(""),
		UTL_CSTRTOSTR("swamp"),
		UTL_CSTRTOSTR("dark_forest")
	};

	const string_t temperature_modifiers[] = {
		UTL_CSTRTOSTR(""),
		UTL_CSTRTOSTR("frozen")
	};
	
	if (mat_codec == NULL) {

		// dimension codec
		mnbt_doc* doc = mnbt_new();
		mnbt_tag* root = mnbt_new_tag(doc, UTL_CSTRTOARG(""), MNBT_COMPOUND, mnbt_val_compound());
		mnbt_set_root(doc, root);

		mnbt_tag* dimension_type = mnbt_new_tag(doc, UTL_CSTRTOARG("minecraft:dimension_type"), MNBT_COMPOUND, mnbt_val_compound());
		mnbt_push_tag(dimension_type, mnbt_new_tag(doc, UTL_CSTRTOARG("type"), MNBT_STRING, mnbt_val_string(UTL_CSTRTOARG("minecraft:dimension_type"))));
		mnbt_tag* dimension_list = mnbt_new_tag(doc, UTL_CSTRTOARG("value"), MNBT_LIST, mnbt_val_list(MNBT_COMPOUND));
		for (mat_dimension_type_t i = 0; i < mat_dimension_count; ++i) {
			const mat_dimension_t* dimension = mat_get_dimension_by_type(i);
			mnbt_val compound = mnbt_val_compound();
			mnbt_val_push_tag(&compound, mnbt_new_tag(doc, UTL_CSTRTOARG("name"), MNBT_STRING, mnbt_val_string(UTL_STRTOARG(dimension->name))));
			mnbt_val_push_tag(&compound, mnbt_new_tag(doc, UTL_CSTRTOARG("id"), MNBT_INT, mnbt_val_int(i)));
			mnbt_tag* element = mnbt_new_tag(doc, UTL_CSTRTOARG("element"), MNBT_COMPOUND, mnbt_val_compound());
			mnbt_push_tag(element, mnbt_new_tag(doc, UTL_CSTRTOARG("piglin_safe"), MNBT_BYTE, mnbt_val_byte(dimension->piglin_safe)));
			mnbt_push_tag(element, mnbt_new_tag(doc, UTL_CSTRTOARG("natural"), MNBT_BYTE, mnbt_val_byte(dimension->natural)));
			mnbt_push_tag(element, mnbt_new_tag(doc, UTL_CSTRTOARG("ambient_light"), MNBT_FLOAT, mnbt_val_float(dimension->ambient_light)));
			if (dimension->has_fixed_time) {
				mnbt_push_tag(element, mnbt_new_tag(doc, UTL_CSTRTOARG("fixed_time"), MNBT_LONG, mnbt_val_long(dimension->fixed_time)));
			}
			mnbt_push_tag(element, mnbt_new_tag(doc, UTL_CSTRTOARG("infiniburn"), MNBT_STRING, mnbt_val_string(UTL_CSTRTOARG(""))));
			mnbt_push_tag(element, mnbt_new_tag(doc, UTL_CSTRTOARG("respawn_anchor_works"), MNBT_BYTE, mnbt_val_byte(dimension->respawn_anchor_works)));
			mnbt_push_tag(element, mnbt_new_tag(doc, UTL_CSTRTOARG("has_skylight"), MNBT_BYTE, mnbt_val_byte(dimension->has_skylight)));
			mnbt_push_tag(element, mnbt_new_tag(doc, UTL_CSTRTOARG("bed_works"), MNBT_BYTE, mnbt_val_byte(dimension->bed_works)));
			mnbt_push_tag(element, mnbt_new_tag(doc, UTL_CSTRTOARG("effects"), MNBT_STRING, mnbt_val_string(UTL_STRTOARG(dimension->effects))));
			mnbt_push_tag(element, mnbt_new_tag(doc, UTL_CSTRTOARG("has_raids"), MNBT_BYTE, mnbt_val_byte(dimension->has_raids)));
			mnbt_push_tag(element, mnbt_new_tag(doc, UTL_CSTRTOARG("min_y"), MNBT_INT, mnbt_val_int(dimension->min_y)));
			mnbt_push_tag(element, mnbt_new_tag(doc, UTL_CSTRTOARG("height"), MNBT_INT, mnbt_val_int(dimension->height)));
			mnbt_push_tag(element, mnbt_new_tag(doc, UTL_CSTRTOARG("logical_height"), MNBT_INT, mnbt_val_int(dimension->logical_height)));
			mnbt_push_tag(element, mnbt_new_tag(doc, UTL_CSTRTOARG("coordinate_scale"), MNBT_FLOAT, mnbt_val_float(dimension->coordinate_scale)));
			mnbt_push_tag(element, mnbt_new_tag(doc, UTL_CSTRTOARG("ultrawarm"), MNBT_BYTE, mnbt_val_byte(dimension->ultrawarm)));
			mnbt_push_tag(element, mnbt_new_tag(doc, UTL_CSTRTOARG("has_ceiling"), MNBT_BYTE, mnbt_val_byte(dimension->has_ceiling)));
			mnbt_val_push_tag(&compound, element);
			mnbt_list_push(dimension_list, compound);
		}
		mnbt_push_tag(dimension_type, dimension_list);
		mnbt_push_tag(root, dimension_type);

		mnbt_tag* biomes = mnbt_new_tag(doc, UTL_CSTRTOARG("minecraft:worldgen/biome"), MNBT_COMPOUND, mnbt_val_compound());
		mnbt_push_tag(biomes, mnbt_new_tag(doc, UTL_CSTRTOARG("type"), MNBT_STRING, mnbt_val_string(UTL_CSTRTOARG("minecraft:worldgen/biome"))));
		mnbt_tag* biomes_list = mnbt_new_tag(doc, UTL_CSTRTOARG("value"), MNBT_LIST, mnbt_val_list(MNBT_COMPOUND));
		for (mat_biome_type_t i = 0; i < mat_biome_count; ++i) {
			const mat_biome_t* biome = mat_get_biome_by_type(i);
			mnbt_val compound = mnbt_val_compound();
			mnbt_val_push_tag(&compound, mnbt_new_tag(doc, UTL_CSTRTOARG("name"), MNBT_STRING, mnbt_val_string(UTL_STRTOARG(biome->name))));
			mnbt_val_push_tag(&compound, mnbt_new_tag(doc, UTL_CSTRTOARG("id"), MNBT_INT, mnbt_val_int(i)));
			mnbt_tag* element = mnbt_new_tag(doc, UTL_CSTRTOARG("element"), MNBT_COMPOUND, mnbt_val_compound());
			mnbt_push_tag(element, mnbt_new_tag(doc, UTL_CSTRTOARG("precipitation"), MNBT_STRING, mnbt_val_string(UTL_STRTOARG(precipitation_types[biome->precipitation]))));
			mnbt_push_tag(element, mnbt_new_tag(doc, UTL_CSTRTOARG("temperature"), MNBT_FLOAT, mnbt_val_float(biome->temperature)));
			mnbt_push_tag(element, mnbt_new_tag(doc, UTL_CSTRTOARG("downfall"), MNBT_FLOAT, mnbt_val_float(biome->downfall)));
			mnbt_push_tag(element, mnbt_new_tag(doc, UTL_CSTRTOARG("category"), MNBT_STRING, mnbt_val_string(UTL_STRTOARG(biome_categories[biome->category]))));
			if (biome->temperature_modifier != mat_temperature_modifier_none) {
				mnbt_push_tag(element, mnbt_new_tag(doc, UTL_CSTRTOARG("temperature_modifier"), MNBT_STRING, mnbt_val_string(UTL_STRTOARG(temperature_modifiers[biome->temperature_modifier]))));
			}
			mnbt_tag* effects = mnbt_new_tag(doc, UTL_CSTRTOARG("effects"), MNBT_COMPOUND, mnbt_val_compound());
			mnbt_push_tag(effects, mnbt_new_tag(doc, UTL_CSTRTOARG("sky_color"), MNBT_INT, mnbt_val_int(biome->effects.sky_color)));
			mnbt_push_tag(effects, mnbt_new_tag(doc, UTL_CSTRTOARG("water_color"), MNBT_INT, mnbt_val_int(biome->effects.water_color)));
			mnbt_push_tag(effects, mnbt_new_tag(doc, UTL_CSTRTOARG("water_fog_color"), MNBT_INT, mnbt_val_int(biome->effects.water_fog_color)));
			mnbt_push_tag(effects, mnbt_new_tag(doc, UTL_CSTRTOARG("fog_color"), MNBT_INT, mnbt_val_int(biome->effects.fog_color)));
			if (biome->effects.has_foliage_color) {
				mnbt_push_tag(effects, mnbt_new_tag(doc, UTL_CSTRTOARG("foliage_color"), MNBT_INT, mnbt_val_int(biome->effects.foliage_color)));
			}
			if (biome->effects.has_grass_color) {
				mnbt_push_tag(effects, mnbt_new_tag(doc, UTL_CSTRTOARG("grass_color"), MNBT_INT, mnbt_val_int(biome->effects.grass_color)));
			}
			if (biome->effects.grass_color_modifier != mat_grass_color_modifier_none) {
				mnbt_push_tag(effects, mnbt_new_tag(doc, UTL_CSTRTOARG("grass_color_modifier"), MNBT_STRING, mnbt_val_string(UTL_STRTOARG(grass_color_modifiers[biome->effects.grass_color_modifier]))));
			}
			if (UTL_STRTOCSTR(biome->effects.music.sound) != NULL) {
				mnbt_tag* music = mnbt_new_tag(doc, UTL_CSTRTOARG("music"), MNBT_COMPOUND, mnbt_val_compound());
				mnbt_push_tag(music, mnbt_new_tag(doc, UTL_CSTRTOARG("replace_current_music"), MNBT_BYTE, mnbt_val_byte(biome->effects.music.replace_current_music)));
				mnbt_push_tag(music, mnbt_new_tag(doc, UTL_CSTRTOARG("sound"), MNBT_STRING, mnbt_val_string(UTL_STRTOARG(biome->effects.music.sound))));
				mnbt_push_tag(music, mnbt_new_tag(doc, UTL_CSTRTOARG("max_delay"), MNBT_INT, mnbt_val_int(biome->effects.music.max_delay)));
				mnbt_push_tag(music, mnbt_new_tag(doc, UTL_CSTRTOARG("min_delay"), MNBT_INT, mnbt_val_int(biome->effects.music.min_delay)));
				mnbt_push_tag(effects, music);
			}
			if (UTL_STRTOCSTR(biome->effects.ambient_sound) != NULL) {
				mnbt_push_tag(effects, mnbt_new_tag(doc, UTL_CSTRTOARG("ambient_sound"), MNBT_STRING, mnbt_val_string(UTL_STRTOARG(biome->effects.ambient_sound))));
			}
			if (UTL_STRTOCSTR(biome->effects.additions_sound.sound) != NULL) {
				mnbt_tag* additions_sound = mnbt_new_tag(doc, UTL_CSTRTOARG("additions_sound"), MNBT_COMPOUND, mnbt_val_compound());
				mnbt_push_tag(additions_sound, mnbt_new_tag(doc, UTL_CSTRTOARG("sound"), MNBT_STRING, mnbt_val_string(UTL_STRTOARG(biome->effects.additions_sound.sound))));
				mnbt_push_tag(additions_sound, mnbt_new_tag(doc, UTL_CSTRTOARG("tick_chance"), MNBT_INT, mnbt_val_int(biome->effects.additions_sound.tick_chance)));
				mnbt_push_tag(effects, additions_sound);
			}
			if (UTL_STRTOCSTR(biome->effects.mood_sound.sound) != NULL) {
				mnbt_tag* mood_sound = mnbt_new_tag(doc, UTL_CSTRTOARG("mood_sound"), MNBT_COMPOUND, mnbt_val_compound());
				mnbt_push_tag(mood_sound, mnbt_new_tag(doc, UTL_CSTRTOARG("sound"), MNBT_STRING, mnbt_val_string(UTL_STRTOARG(biome->effects.mood_sound.sound))));
				mnbt_push_tag(mood_sound, mnbt_new_tag(doc, UTL_CSTRTOARG("tick_delay"), MNBT_INT, mnbt_val_int(biome->effects.mood_sound.tick_delay)));
				mnbt_push_tag(mood_sound, mnbt_new_tag(doc, UTL_CSTRTOARG("offset"), MNBT_DOUBLE, mnbt_val_double(biome->effects.mood_sound.offset)));
				mnbt_push_tag(mood_sound, mnbt_new_tag(doc, UTL_CSTRTOARG("block_search_extent"), MNBT_INT, mnbt_val_int(biome->effects.mood_sound.block_search_extent)));
				mnbt_push_tag(effects, mood_sound);
			}
			mnbt_push_tag(element, effects);
			if (UTL_STRTOCSTR(biome->particle.options.type) != NULL) {
				mnbt_tag* particle = mnbt_new_tag(doc, UTL_CSTRTOARG("particle"), MNBT_COMPOUND, mnbt_val_compound());
				mnbt_push_tag(particle, mnbt_new_tag(doc, UTL_CSTRTOARG("probability"), MNBT_FLOAT, mnbt_val_float(biome->particle.probability)));
				mnbt_tag* options = mnbt_new_tag(doc, UTL_CSTRTOARG("options"), MNBT_COMPOUND, mnbt_val_compound());
				mnbt_push_tag(options, mnbt_new_tag(doc, UTL_CSTRTOARG("type"), MNBT_STRING, mnbt_val_string(UTL_STRTOARG(biome->particle.options.type))));
				mnbt_push_tag(particle, options);
				mnbt_push_tag(element, particle);
			}
			mnbt_val_push_tag(&compound, element);
			mnbt_list_push(biomes_list, compound);
		}
		mnbt_push_tag(biomes, biomes_list);
		mnbt_push_tag(root, biomes);

		mat_codec = malloc(sizeof(mat_codec_t) + 65536);
		mat_codec->size = mnbt_write(doc, mat_codec->bytes, MNBT_NONE);

		mnbt_free(doc);

		void* resized_codec = realloc(mat_codec, sizeof(mat_codec_t) + mat_codec->size);
		if (resized_codec != NULL) {
			mat_codec = resized_codec;
		}

	}

	return mat_codec;

}

const mat_codec_t* mat_get_dimension_codec(mat_dimension_type_t type) {

	if (mat_dimension_codec[type] == NULL) {
		const mat_dimension_t* dimension = mat_get_dimension_by_type(type);
		mnbt_doc* doc = mnbt_new();
		mnbt_tag* element = mnbt_new_tag(doc, UTL_CSTRTOARG(""), MNBT_COMPOUND, mnbt_val_compound());
		mnbt_push_tag(element, mnbt_new_tag(doc, UTL_CSTRTOARG("piglin_safe"), MNBT_BYTE, mnbt_val_byte(dimension->piglin_safe)));
		mnbt_push_tag(element, mnbt_new_tag(doc, UTL_CSTRTOARG("natural"), MNBT_BYTE, mnbt_val_byte(dimension->natural)));
		mnbt_push_tag(element, mnbt_new_tag(doc, UTL_CSTRTOARG("ambient_light"), MNBT_FLOAT, mnbt_val_float(dimension->ambient_light)));
		if (dimension->has_fixed_time) {
			mnbt_push_tag(element, mnbt_new_tag(doc, UTL_CSTRTOARG("fixed_time"), MNBT_LONG, mnbt_val_long(dimension->fixed_time)));
		}
		mnbt_push_tag(element, mnbt_new_tag(doc, UTL_CSTRTOARG("infiniburn"), MNBT_STRING, mnbt_val_string("", 0)));
		mnbt_push_tag(element, mnbt_new_tag(doc, UTL_CSTRTOARG("respawn_anchor_works"), MNBT_BYTE, mnbt_val_byte(dimension->respawn_anchor_works)));
		mnbt_push_tag(element, mnbt_new_tag(doc, UTL_CSTRTOARG("has_skylight"), MNBT_BYTE, mnbt_val_byte(dimension->has_skylight)));
		mnbt_push_tag(element, mnbt_new_tag(doc, UTL_CSTRTOARG("bed_works"), MNBT_BYTE, mnbt_val_byte(dimension->bed_works)));
		mnbt_push_tag(element, mnbt_new_tag(doc, UTL_CSTRTOARG("effects"), MNBT_STRING, mnbt_val_string(UTL_STRTOARG(dimension->effects))));
		mnbt_push_tag(element, mnbt_new_tag(doc, UTL_CSTRTOARG("has_raids"), MNBT_BYTE, mnbt_val_byte(dimension->has_raids)));
		mnbt_push_tag(element, mnbt_new_tag(doc, UTL_CSTRTOARG("min_y"), MNBT_INT, mnbt_val_int(dimension->min_y)));
		mnbt_push_tag(element, mnbt_new_tag(doc, UTL_CSTRTOARG("height"), MNBT_INT, mnbt_val_int(dimension->height)));
		mnbt_push_tag(element, mnbt_new_tag(doc, UTL_CSTRTOARG("logical_height"), MNBT_INT, mnbt_val_int(dimension->logical_height)));
		mnbt_push_tag(element, mnbt_new_tag(doc, UTL_CSTRTOARG("coordinate_scale"), MNBT_FLOAT, mnbt_val_float(dimension->coordinate_scale)));
		mnbt_push_tag(element, mnbt_new_tag(doc, UTL_CSTRTOARG("ultrawarm"), MNBT_BYTE, mnbt_val_byte(dimension->ultrawarm)));
		mnbt_push_tag(element, mnbt_new_tag(doc, UTL_CSTRTOARG("has_ceiling"), MNBT_BYTE, mnbt_val_byte(dimension->has_ceiling)));
		mnbt_set_root(doc, element);

		mat_dimension_codec[type] = malloc(sizeof(mat_codec_t) + 1024);
		mat_dimension_codec[type]->size = mnbt_write(doc, mat_dimension_codec[type]->bytes, MNBT_NONE);

		mnbt_free(doc);

		mat_dimension_codec[type] = realloc(mat_dimension_codec[type], sizeof(mat_codec_t) + mat_dimension_codec[type]->size);

	}

	return mat_dimension_codec[type];

}