#include <stdlib.h>
#include "../../main.h"
#include "material.h"
#include "../../io/nbt/mnbt.h"

mat_codec_t* mat_codec = NULL;

mat_codec_t* mat_dimension_codec[mat_dimension_count] = {};

const mat_codec_t* mat_get_codec() {
	
	if (mat_codec == NULL) {

		// dimension codec
		mnbt_doc* doc = mnbt_new();
		mnbt_tag* root = mnbt_new_tag(doc, "", 0, MNBT_COMPOUND, mnbt_val_compound());
		mnbt_set_root(doc, root);

		mnbt_tag* dimension_type = mnbt_new_tag(doc, "minecraft:dimension_type", 24, MNBT_COMPOUND, mnbt_val_compound());
		mnbt_push_tag(dimension_type, mnbt_new_tag(doc, "type", 4, MNBT_STRING, mnbt_val_string("minecraft:dimension_type", 24)));
		mnbt_tag* dimension_list = mnbt_new_tag(doc, "value", 5, MNBT_LIST, mnbt_val_list(MNBT_COMPOUND));
		for (mat_dimension_type_t i = 0; i < mat_dimension_count; ++i) {
			const mat_dimension_t* dimension = mat_get_dimension_by_type(i);
			mnbt_val compound = mnbt_val_compound();
			mnbt_val_push_tag(&compound, mnbt_new_tag(doc, "name", 4, MNBT_STRING, mnbt_val_string(dimension->name, dimension->name_length)));
			mnbt_val_push_tag(&compound, mnbt_new_tag(doc, "id", 2, MNBT_INT, mnbt_val_int(i)));
			mnbt_tag* element = mnbt_new_tag(doc, "element", 7, MNBT_COMPOUND, mnbt_val_compound());
			mnbt_push_tag(element, mnbt_new_tag(doc, "piglin_safe", 11, MNBT_BYTE, mnbt_val_byte(dimension->piglin_safe)));
			mnbt_push_tag(element, mnbt_new_tag(doc, "natural", 7, MNBT_BYTE, mnbt_val_byte(dimension->natural)));
			mnbt_push_tag(element, mnbt_new_tag(doc, "ambient_light", 13, MNBT_FLOAT, mnbt_val_float(dimension->ambient_light)));
			if (dimension->has_fixed_time) {
				mnbt_push_tag(element, mnbt_new_tag(doc, "fixed_time", 10, MNBT_LONG, mnbt_val_long(dimension->fixed_time)));
			}
			mnbt_push_tag(element, mnbt_new_tag(doc, "infiniburn", 10, MNBT_STRING, mnbt_val_string("", 0)));
			mnbt_push_tag(element, mnbt_new_tag(doc, "respawn_anchor_works", 20, MNBT_BYTE, mnbt_val_byte(dimension->respawn_anchor_works)));
			mnbt_push_tag(element, mnbt_new_tag(doc, "has_skylight", 12, MNBT_BYTE, mnbt_val_byte(dimension->has_skylight)));
			mnbt_push_tag(element, mnbt_new_tag(doc, "bed_works", 9, MNBT_BYTE, mnbt_val_byte(dimension->bed_works)));
			mnbt_push_tag(element, mnbt_new_tag(doc, "effects", 7, MNBT_STRING, mnbt_val_string(dimension->effects, dimension->effects_length)));
			mnbt_push_tag(element, mnbt_new_tag(doc, "has_raids", 9, MNBT_BYTE, mnbt_val_byte(dimension->has_raids)));
			mnbt_push_tag(element, mnbt_new_tag(doc, "min_y", 5, MNBT_INT, mnbt_val_int(dimension->min_y)));
			mnbt_push_tag(element, mnbt_new_tag(doc, "height", 6, MNBT_INT, mnbt_val_int(dimension->height)));
			mnbt_push_tag(element, mnbt_new_tag(doc, "logical_height", 14, MNBT_INT, mnbt_val_int(dimension->logical_height)));
			mnbt_push_tag(element, mnbt_new_tag(doc, "coordinate_scale", 16, MNBT_FLOAT, mnbt_val_float(dimension->coordinate_scale)));
			mnbt_push_tag(element, mnbt_new_tag(doc, "ultrawarm", 9, MNBT_BYTE, mnbt_val_byte(dimension->ultrawarm)));
			mnbt_push_tag(element, mnbt_new_tag(doc, "has_ceiling", 11, MNBT_BYTE, mnbt_val_byte(dimension->has_ceiling)));
			mnbt_val_push_tag(&compound, element);
			mnbt_list_push(dimension_list, compound);
		}
		mnbt_push_tag(dimension_type, dimension_list);
		mnbt_push_tag(root, dimension_type);

		mnbt_tag* biomes = mnbt_new_tag(doc, "minecraft:worldgen/biome", 24, MNBT_COMPOUND, mnbt_val_compound());
		mnbt_push_tag(biomes, mnbt_new_tag(doc, "type", 4, MNBT_STRING, mnbt_val_string("minecraft:worldgen/biome", 24)));
		mnbt_tag* biomes_list = mnbt_new_tag(doc, "value", 5, MNBT_LIST, mnbt_val_list(MNBT_COMPOUND));
		for (mat_biome_type_t i = 0; i < mat_biome_count; ++i) {
			const mat_biome_t* biome = mat_get_biome_by_type(i);
			mnbt_val compound = mnbt_val_compound();
			mnbt_val_push_tag(&compound, mnbt_new_tag(doc, "name", 4, MNBT_STRING, mnbt_val_string(biome->name, biome->name_length)));
			mnbt_val_push_tag(&compound, mnbt_new_tag(doc, "id", 2, MNBT_INT, mnbt_val_int(i)));
			mnbt_tag* element = mnbt_new_tag(doc, "element", 7, MNBT_COMPOUND, mnbt_val_compound());
			mnbt_push_tag(element, mnbt_new_tag(doc, "precipitation", 13, MNBT_STRING, mnbt_val_string(mat_precipitation_type_string(biome->precipitation), mat_precipitation_type_length(biome->precipitation))));
			mnbt_push_tag(element, mnbt_new_tag(doc, "depth", 5, MNBT_FLOAT, mnbt_val_float(biome->depth)));
			mnbt_push_tag(element, mnbt_new_tag(doc, "temperature", 11, MNBT_FLOAT, mnbt_val_float(biome->temperature)));
			mnbt_push_tag(element, mnbt_new_tag(doc, "scale", 5, MNBT_FLOAT, mnbt_val_float(biome->scale)));
			mnbt_push_tag(element, mnbt_new_tag(doc, "downfall", 8, MNBT_FLOAT, mnbt_val_float(biome->downfall)));
			mnbt_push_tag(element, mnbt_new_tag(doc, "category", 8, MNBT_STRING, mnbt_val_string(mat_biome_category_string(biome->category), mat_biome_category_length(biome->category))));
			if (biome->temperature_modifier != mat_temperature_modifier_none) {
				mnbt_push_tag(element, mnbt_new_tag(doc, "temperature_modifier", 20, MNBT_STRING, mnbt_val_string(mat_temperature_modifier_string(biome->temperature_modifier), mat_temperature_modifier_length(biome->temperature_modifier))));
			}
			mnbt_tag* effects = mnbt_new_tag(doc, "effects", 7, MNBT_COMPOUND, mnbt_val_compound());
			mnbt_push_tag(effects, mnbt_new_tag(doc, "sky_color", 9, MNBT_INT, mnbt_val_int(biome->effects.sky_color)));
			mnbt_push_tag(effects, mnbt_new_tag(doc, "water_color", 11, MNBT_INT, mnbt_val_int(biome->effects.water_color)));
			mnbt_push_tag(effects, mnbt_new_tag(doc, "water_fog_color", 15, MNBT_INT, mnbt_val_int(biome->effects.water_fog_color)));
			mnbt_push_tag(effects, mnbt_new_tag(doc, "fog_color", 9, MNBT_INT, mnbt_val_int(biome->effects.fog_color)));
			if (biome->effects.has_foliage_color) {
				mnbt_push_tag(effects, mnbt_new_tag(doc, "foliage_color", 13, MNBT_INT, mnbt_val_int(biome->effects.foliage_color)));
			}
			if (biome->effects.has_grass_color) {
				mnbt_push_tag(effects, mnbt_new_tag(doc, "grass_color", 11, MNBT_INT, mnbt_val_int(biome->effects.grass_color)));
			}
			if (biome->effects.grass_color_modifier != mat_grass_color_modifier_none) {
				mnbt_push_tag(effects, mnbt_new_tag(doc, "grass_color_modifier", 20, MNBT_STRING, mnbt_val_string(mat_grass_color_modifier_string(biome->effects.grass_color_modifier), mat_grass_color_modifier_length(biome->effects.grass_color_modifier))));
			}
			if (biome->effects.music.sound != NULL) {
				mnbt_tag* music = mnbt_new_tag(doc, "music", 5, MNBT_COMPOUND, mnbt_val_compound());
				mnbt_push_tag(music, mnbt_new_tag(doc, "replace_current_music", 21, MNBT_BYTE, mnbt_val_byte(biome->effects.music.replace_current_music)));
				mnbt_push_tag(music, mnbt_new_tag(doc, "sound", 5, MNBT_STRING, mnbt_val_string(biome->effects.music.sound, biome->effects.music.sound_length)));
				mnbt_push_tag(music, mnbt_new_tag(doc, "max_delay", 9, MNBT_INT, mnbt_val_int(biome->effects.music.max_delay)));
				mnbt_push_tag(music, mnbt_new_tag(doc, "min_delay", 9, MNBT_INT, mnbt_val_int(biome->effects.music.min_delay)));
				mnbt_push_tag(effects, music);
			}
			if (biome->effects.ambient_sound != NULL) {
				mnbt_push_tag(effects, mnbt_new_tag(doc, "ambient_sound", 13, MNBT_STRING, mnbt_val_string(biome->effects.ambient_sound, biome->effects.ambient_sound_length)));
			}
			if (biome->effects.additions_sound.sound != NULL) {
				mnbt_tag* additions_sound = mnbt_new_tag(doc, "additions_sound", 15, MNBT_COMPOUND, mnbt_val_compound());
				mnbt_push_tag(additions_sound, mnbt_new_tag(doc, "sound", 5, MNBT_STRING, mnbt_val_string(biome->effects.additions_sound.sound, biome->effects.additions_sound.sound_length)));
				mnbt_push_tag(additions_sound, mnbt_new_tag(doc, "tick_chance", 11, MNBT_INT, mnbt_val_int(biome->effects.additions_sound.tick_chance)));
				mnbt_push_tag(effects, additions_sound);
			}
			if (biome->effects.mood_sound.sound != NULL) {
				mnbt_tag* mood_sound = mnbt_new_tag(doc, "mood_sound", 10, MNBT_COMPOUND, mnbt_val_compound());
				mnbt_push_tag(mood_sound, mnbt_new_tag(doc, "sound", 5, MNBT_STRING, mnbt_val_string(biome->effects.mood_sound.sound, biome->effects.mood_sound.sound_length)));
				mnbt_push_tag(mood_sound, mnbt_new_tag(doc, "tick_delay", 10, MNBT_INT, mnbt_val_int(biome->effects.mood_sound.tick_delay)));
				mnbt_push_tag(mood_sound, mnbt_new_tag(doc, "offset", 6, MNBT_DOUBLE, mnbt_val_double(biome->effects.mood_sound.offset)));
				mnbt_push_tag(mood_sound, mnbt_new_tag(doc, "block_search_extent", 19, MNBT_INT, mnbt_val_int(biome->effects.mood_sound.block_search_extent)));
				mnbt_push_tag(effects, mood_sound);
			}
			mnbt_push_tag(element, effects);
			if (biome->particle.options.type != NULL) {
				mnbt_tag* particle = mnbt_new_tag(doc, "particle", 8, MNBT_COMPOUND, mnbt_val_compound());
				mnbt_push_tag(particle, mnbt_new_tag(doc, "probability", 11, MNBT_FLOAT, mnbt_val_float(biome->particle.probability)));
				mnbt_tag* options = mnbt_new_tag(doc, "options", 7, MNBT_COMPOUND, mnbt_val_compound());
				mnbt_push_tag(options, mnbt_new_tag(doc, "type", 4, MNBT_STRING, mnbt_val_string(biome->particle.options.type, biome->particle.options.type_length)));
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

		mat_codec = realloc(mat_codec, sizeof(mat_codec_t) + mat_codec->size);

	}

	return mat_codec;

}

const mat_codec_t* mat_get_dimension_codec(mat_dimension_type_t type) {

	if (mat_dimension_codec[type] == NULL) {
		const mat_dimension_t* dimension = mat_get_dimension_by_type(type);
		mnbt_doc* doc = mnbt_new();
		mnbt_tag* element = mnbt_new_tag(doc, "", 0, MNBT_COMPOUND, mnbt_val_compound());
		mnbt_push_tag(element, mnbt_new_tag(doc, "piglin_safe", 11, MNBT_BYTE, mnbt_val_byte(dimension->piglin_safe)));
		mnbt_push_tag(element, mnbt_new_tag(doc, "natural", 7, MNBT_BYTE, mnbt_val_byte(dimension->natural)));
		mnbt_push_tag(element, mnbt_new_tag(doc, "ambient_light", 13, MNBT_FLOAT, mnbt_val_float(dimension->ambient_light)));
		if (dimension->has_fixed_time) {
			mnbt_push_tag(element, mnbt_new_tag(doc, "fixed_time", 10, MNBT_LONG, mnbt_val_long(dimension->fixed_time)));
		}
		mnbt_push_tag(element, mnbt_new_tag(doc, "infiniburn", 10, MNBT_STRING, mnbt_val_string("", 0)));
		mnbt_push_tag(element, mnbt_new_tag(doc, "respawn_anchor_works", 20, MNBT_BYTE, mnbt_val_byte(dimension->respawn_anchor_works)));
		mnbt_push_tag(element, mnbt_new_tag(doc, "has_skylight", 12, MNBT_BYTE, mnbt_val_byte(dimension->has_skylight)));
		mnbt_push_tag(element, mnbt_new_tag(doc, "bed_works", 9, MNBT_BYTE, mnbt_val_byte(dimension->bed_works)));
		mnbt_push_tag(element, mnbt_new_tag(doc, "effects", 7, MNBT_STRING, mnbt_val_string(dimension->effects, dimension->effects_length)));
		mnbt_push_tag(element, mnbt_new_tag(doc, "has_raids", 9, MNBT_BYTE, mnbt_val_byte(dimension->has_raids)));
		mnbt_push_tag(element, mnbt_new_tag(doc, "min_y", 5, MNBT_INT, mnbt_val_int(dimension->min_y)));
		mnbt_push_tag(element, mnbt_new_tag(doc, "height", 6, MNBT_INT, mnbt_val_int(dimension->height)));
		mnbt_push_tag(element, mnbt_new_tag(doc, "logical_height", 14, MNBT_INT, mnbt_val_int(dimension->logical_height)));
		mnbt_push_tag(element, mnbt_new_tag(doc, "coordinate_scale", 16, MNBT_FLOAT, mnbt_val_float(dimension->coordinate_scale)));
		mnbt_push_tag(element, mnbt_new_tag(doc, "ultrawarm", 9, MNBT_BYTE, mnbt_val_byte(dimension->ultrawarm)));
		mnbt_push_tag(element, mnbt_new_tag(doc, "has_ceiling", 11, MNBT_BYTE, mnbt_val_byte(dimension->has_ceiling)));
		mnbt_set_root(doc, element);

		mat_dimension_codec[type] = malloc(sizeof(mat_codec_t) + 1024);
		mat_dimension_codec[type]->size = mnbt_write(doc, mat_dimension_codec[type]->bytes, MNBT_NONE);

		mnbt_free(doc);

		mat_dimension_codec[type] = realloc(mat_dimension_codec[type], sizeof(mat_codec_t) + mat_dimension_codec[type]->size);

	}

	return mat_dimension_codec[type];

}