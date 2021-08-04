#include "play.h"
#include "../../io/logger/logger.h"
#include "../../io/nbt/mnbt.h"
#include "../../motor.h"
#include "../../world/world.h"

bool_t phd_play(ltg_client_t* client, pck_packet_t* packet) {

	pck_readVarInt(packet); // packet length
	int32_t id = pck_readVarInt(packet);

	switch (id) {
	case 0x00: // teleport confirm
		return phd_handleTeleportConfirm(client, packet);
	case 0x04:
		return phd_handleClientStatus(client, packet);
	case 0x05: // client settings
		return phd_handleClientSettings(client, packet);
	case 0x12:
		return phd_handlePlayerPositionAndLook(client, packet);
	default:
		log_warn("Unknown packet %x received in play state!", id);
		return false;
	}

}

bool_t phd_handleTeleportConfirm(ltg_client_t* client, pck_packet_t* packet) {

	assert(client != NULL);
	assert(packet != NULL);

	return false;

}

bool_t phd_handleClientStatus(ltg_client_t* client, pck_packet_t* packet) {

	assert(client != NULL);
	assert(packet != NULL);

	return false;

}

bool_t phd_handleClientSettings(ltg_client_t* client, pck_packet_t* packet) {

	assert(client != NULL);
	assert(packet != NULL);

	return false;

}

bool_t phd_handlePlayerPositionAndLook(ltg_client_t* client, pck_packet_t* packet) {

	assert(client != NULL);
	assert(packet != NULL);

	return false;

}

void phd_sendJoinGame(ltg_client_t* client) {

	pck_inline(packet, 4096, IO_BIG_ENDIAN);
	pck_padLength(packet);

	pck_writeInt32(packet, 0); // entity ID
	pck_writeInt8(packet, sky_main.hardcore);
	pck_writeInt8(packet, sky_main.gamemode);
	pck_writeInt8(packet, -1); // previous game mode

	// worlds
	pck_writeVarInt(packet, sky_main.worlds.size);
	for (size_t i = 0; i < sky_main.worlds.size; ++i) {
		wld_world_t* world = utl_vectorGetAs(wld_world_t*, &sky_main.worlds, i);
		pck_writeString(packet, world->name, world->name_length);
	}

	// dimension codec
	mnbt_doc* doc = mnbt_new();
	mnbt_tag* root = mnbt_new_tag(doc, "", 0, MNBT_COMPOUND, mnbt_val_compound());
	mnbt_set_root(doc, root);

	// dimension type registry TODO generate this once per dimensions change
	mnbt_tag* dimension_type = mnbt_new_tag(doc, "minecraft:dimension_type", 24, MNBT_COMPOUND, mnbt_val_compound());
	mnbt_push_tag(dimension_type, mnbt_new_tag(doc, "type", 4, MNBT_STRING, mnbt_val_string("minecraft:dimension_type", 24)));
	mnbt_tag* dimension_list = mnbt_new_tag(doc, "value", 5, MNBT_LIST, mnbt_val_list(MNBT_COMPOUND));
	for (mat_dimension_type_t i = 0; i < mat_dimension_count; ++i) {
		const mat_dimension_t* dimension = mat_getDimensionByType(i);
		mnbt_val compound = mnbt_val_compound();
		mnbt_val_push_tag(&compound, mnbt_new_tag(doc, "name", 4, MNBT_STRING, mnbt_val_string(dimension->name, dimension->name_length)));
		mnbt_val_push_tag(&compound, mnbt_new_tag(doc, "id", 2, MNBT_INT, mnbt_val_int(i)));
		mnbt_tag* element = mnbt_new_tag(doc, "element", 7, MNBT_COMPOUND, mnbt_val_compound());
		mnbt_push_tag(element, mnbt_new_tag(doc, "piglin_safe", 11, MNBT_BYTE, mnbt_val_byte(mat_dimension_isPiglinSafe(i))));
		mnbt_push_tag(element, mnbt_new_tag(doc, "natural", 7, MNBT_BYTE, mnbt_val_byte(mat_dimension_isNatural(i))));
		mnbt_push_tag(element, mnbt_new_tag(doc, "ambient_light", 13, MNBT_FLOAT, mnbt_val_float(dimension->ambient_light)));
		if (mat_dimension_hasFixedTime(i)) {
			mnbt_push_tag(element, mnbt_new_tag(doc, "fixed_time", 10, MNBT_LONG, mnbt_val_long(mat_dimension_getFixedTime(i))));
		}
		mnbt_push_tag(element, mnbt_new_tag(doc, "infiniburn", 10, MNBT_STRING, mnbt_val_string("", 0)));
		mnbt_push_tag(element, mnbt_new_tag(doc, "respawn_anchor_works", 20, MNBT_BYTE, mnbt_val_byte(mat_dimension_respawnAnchorWorks(i))));
		mnbt_push_tag(element, mnbt_new_tag(doc, "has_skylight", 12, MNBT_BYTE, mnbt_val_byte(mat_dimension_hasSkylight(i))));
		mnbt_push_tag(element, mnbt_new_tag(doc, "bed_works", 9, MNBT_BYTE, mnbt_val_byte(mat_dimension_bedWorks(i))));
		mnbt_push_tag(element, mnbt_new_tag(doc, "effects", 7, MNBT_STRING, mnbt_val_string(dimension->effects, dimension->effects_length)));
		mnbt_push_tag(element, mnbt_new_tag(doc, "has_raids", 9, MNBT_BYTE, mnbt_val_byte(mat_dimension_hasRaids(i))));
		mnbt_push_tag(element, mnbt_new_tag(doc, "min_y", 5, MNBT_INT, mnbt_val_int(dimension->min_y)));
		mnbt_push_tag(element, mnbt_new_tag(doc, "height", 6, MNBT_INT, mnbt_val_int(dimension->height)));
		mnbt_push_tag(element, mnbt_new_tag(doc, "logical_height", 14, MNBT_INT, mnbt_val_int(dimension->logical_height)));
		mnbt_push_tag(element, mnbt_new_tag(doc, "coordinate_scale", 16, MNBT_FLOAT, mnbt_val_float(dimension->coordinate_scale)));
		mnbt_push_tag(element, mnbt_new_tag(doc, "ultrawarm", 9, MNBT_BYTE, mnbt_val_byte(mat_dimension_isUltrawarm(i))));
		mnbt_push_tag(element, mnbt_new_tag(doc, "has_ceiling", 11, MNBT_BYTE, mnbt_val_byte(mat_dimension_hasCeiling(i))));
		mnbt_val_push_tag(&compound, element);
		mnbt_list_push(dimension_list, compound);
	}
	mnbt_push_tag(dimension_type, dimension_list);
	mnbt_push_tag(root, dimension_type);

	mnbt_tag* biomes = mnbt_new_tag(doc, "minecraft:worldgen/biome", 24, MNBT_COMPOUND, mnbt_val_compound());
	mnbt_push_tag(biomes, mnbt_new_tag(doc, "type", 4, MNBT_STRING, mnbt_val_string("minecraft:worldgen/biome", 24)));
	mnbt_tag* biomes_list = mnbt_new_tag(doc, "value", 5, MNBT_LIST, mnbt_val_list(MNBT_COMPOUND));
	for (mat_biome_type_t i = 0; i < mat_biome_count; ++i) {
		const mat_biome_t* biome = mat_getBiomeByType(i);
		mnbt_val compound = mnbt_val_compound();
		mnbt_val_push_tag(&compound, mnbt_new_tag(doc, "name", 4, MNBT_STRING, mnbt_val_string(biome->name, biome->name_length)));
		mnbt_val_push_tag(&compound, mnbt_new_tag(doc, "id", 2, MNBT_INT, mnbt_val_int(i)));
		mnbt_tag* element = mnbt_new_tag(doc, "element", 7, MNBT_COMPOUND, mnbt_val_compound());
		mnbt_push_tag(element, mnbt_new_tag(doc, "precipitation", 13, MNBT_STRING, mnbt_val_string(mat_precipitationTypeAsString(biome->precipitation), mat_precipitationTypeLength(biome->precipitation))));
		mnbt_push_tag(element, mnbt_new_tag(doc, "depth", 5, MNBT_FLOAT, mnbt_val_float(biome->depth)));
		mnbt_push_tag(element, mnbt_new_tag(doc, "temperature", 11, MNBT_FLOAT, mnbt_val_float(biome->temperature)));
		mnbt_push_tag(element, mnbt_new_tag(doc, "scale", 5, MNBT_FLOAT, mnbt_val_float(biome->scale)));
		mnbt_push_tag(element, mnbt_new_tag(doc, "downfall", 8, MNBT_FLOAT, mnbt_val_float(biome->downfall)));
		mnbt_push_tag(element, mnbt_new_tag(doc, "category", 8, MNBT_STRING, mnbt_val_string(mat_biomeCategoryAsString(biome->category), mat_biomeCategoryLength(biome->category))));
		if (biome->temperature_modifier != mat_temperature_modifier_none) {
			mnbt_push_tag(element, mnbt_new_tag(doc, "temperature_modifier", 20, MNBT_STRING, mnbt_val_string(mat_temperatureModifierAsString(biome->temperature_modifier), mat_temperatureModifierLength(biome->temperature_modifier))));
		}
		mnbt_tag* effects = mnbt_new_tag(doc, "effects", 7, MNBT_COMPOUND, mnbt_val_compound());
		mnbt_push_tag(effects, mnbt_new_tag(doc, "sky_color", 9, MNBT_INT, mnbt_val_int(biome->effects.sky_color)));
		mnbt_push_tag(effects, mnbt_new_tag(doc, "water_fog_color", 15, MNBT_INT, mnbt_val_int(biome->effects.water_fog_color)));
		mnbt_push_tag(effects, mnbt_new_tag(doc, "fog_color", 9, MNBT_INT, mnbt_val_int(biome->effects.fog_color)));
		if (mat_biome_hasFoliageColor(i)) {
			mnbt_push_tag(effects, mnbt_new_tag(doc, "foliage_color", 13, MNBT_INT, mnbt_val_int(biome->effects.foliage_color)));
		}
		if (mat_biome_hasGrassColor(i)) {
			mnbt_push_tag(effects, mnbt_new_tag(doc, "grass_color", 11, MNBT_INT, mnbt_val_int(biome->effects.grass_color)));
		}
		if (biome->effects.grass_color_modifier != mat_grass_color_modifier_none) {
			mnbt_push_tag(effects, mnbt_new_tag(doc, "grass_color_modifier", 20, MNBT_STRING, mnbt_val_string(mat_grassColorModifierAsString(biome->effects.grass_color_modifier), mat_grassColorModifierLength(biome->effects.grass_color_modifier))));
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

	mnbt_write_file(doc, "test.nbt", MNBT_NONE);
	mnbt_write_file(doc, "test.gzip.nbt", MNBT_GZIP);
	mnbt_write_file(doc, "test.zlib.nbt", MNBT_ZLIB);

	mnbt_free(doc);

	pck_writeLength(packet);
	ltg_send(client, packet);

}
