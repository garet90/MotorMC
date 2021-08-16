#include <stdio.h>
#include <string.h>
#include "translation.h"
#include "../../util/util.h"

void cht_jsonify_translation(mjson_doc* doc, mjson_val* obj, const cht_translation_t* translation) {

	const char* translations[] = {
		"chat.type.text",
		"multiplayer.player.joined",
		"multiplayer.player.left",
		"multiplayer.disconnect.outdated_client",
		"multiplayer.disconnect.outdated_server",
		"multiplayer.disconnect.server_shutdown"
	};

	mjson_obj_add(obj, mjson_string(doc, "translate", 9), mjson_string(doc, translations[translation->translate], strlen(translations[translation->translate])));

	if (translation->color != cht_no_color) {
		if (translation->color <= 0xF) {
			const char* colors[] = {
				"black",
				"dark_blue",
				"dark_green",
				"dark_aqua",
				"dark_red",
				"dark_purple",
				"gold",
				"gray",
				"dark_gray",
				"blue",
				"green",
				"aqua",
				"red",
				"light_purple",
				"yellow",
				"white"
			};

			mjson_obj_add(obj, mjson_string(doc, "color", 5), mjson_string(doc, colors[translation->color], strlen(colors[translation->color])));
		} else {
			char color[8];
			// convert int to hex
			utl_write_byte_hex(color, ((byte_t*) &translation->color)[0]);
			utl_write_byte_hex(color + 2, ((byte_t*) &translation->color)[1]);
			utl_write_byte_hex(color + 4, ((byte_t*) &translation->color)[2]);
			utl_write_byte_hex(color + 6, ((byte_t*) &translation->color)[3]);

			mjson_obj_add(obj, mjson_string(doc, "color", 5), mjson_string(doc, color, 8));
		}
	}

	if (translation->with.size != 0) {
		mjson_val* with = mjson_arr(doc);

		for (size_t i = 0; i < translation->with.size; ++i) {
			
			mjson_val* with_obj = mjson_obj(doc);

			cht_jsonify(doc, with_obj, UTL_VECTOR_GET_AS(cht_component_t*, &translation->with, i));

			mjson_arr_append(with, with_obj);

		}

		mjson_obj_add(obj, mjson_string(doc, "with", 4), with);
	}

}

size_t cht_write_translation(const cht_translation_t* translation, char* message) {

	mjson_doc* doc = mjson_new();
	mjson_val* obj = mjson_obj(doc);
	mjson_set_root(doc, obj);

	cht_jsonify_translation(doc, obj, translation);

	size_t len = mjson_write(doc, message);

	mjson_free(doc);

	return len;

}