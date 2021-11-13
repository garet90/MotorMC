#include <stdio.h>
#include "translation.h"
#include "chat.h"
#include "../../util/util.h"
#include "../../util/str_util.h"

void cht_jsonify_translation(mjson_doc* doc, mjson_val* obj, const cht_translation_t* translation) {

	const string_t translations[] = {
		UTL_CSTRTOSTR("chat.type.text"),
		UTL_CSTRTOSTR("multiplayer.player.joined"),
		UTL_CSTRTOSTR("multiplayer.player.left"),
		UTL_CSTRTOSTR("multiplayer.disconnect.outdated_client"),
		UTL_CSTRTOSTR("multiplayer.disconnect.outdated_server"),
		UTL_CSTRTOSTR("multiplayer.disconnect.server_shutdown")
	};

	mjson_obj_add(obj, mjson_string(doc, UTL_CSTRTOARG("translate")), mjson_string(doc, UTL_STRTOARG(translations[translation->translate])));

	if (translation->color != cht_no_color) {
		if (translation->color <= 0xF) {
			const string_t colors[] = {
				UTL_CSTRTOSTR("black"),
				UTL_CSTRTOSTR("dark_blue"),
				UTL_CSTRTOSTR("dark_green"),
				UTL_CSTRTOSTR("dark_aqua"),
				UTL_CSTRTOSTR("dark_red"),
				UTL_CSTRTOSTR("dark_purple"),
				UTL_CSTRTOSTR("gold"),
				UTL_CSTRTOSTR("gray"),
				UTL_CSTRTOSTR("dark_gray"),
				UTL_CSTRTOSTR("blue"),
				UTL_CSTRTOSTR("green"),
				UTL_CSTRTOSTR("aqua"),
				UTL_CSTRTOSTR("red"),
				UTL_CSTRTOSTR("light_purple"),
				UTL_CSTRTOSTR("yellow"),
				UTL_CSTRTOSTR("white")
			};

			mjson_obj_add(obj, mjson_string(doc, UTL_CSTRTOARG("color")), mjson_string(doc, UTL_STRTOARG(colors[translation->color])));
		} else {
			char color[8];
			// convert int to hex
			utl_write_byte_hex(color, ((byte_t*) &translation->color)[0]);
			utl_write_byte_hex(color + 2, ((byte_t*) &translation->color)[1]);
			utl_write_byte_hex(color + 4, ((byte_t*) &translation->color)[2]);
			utl_write_byte_hex(color + 6, ((byte_t*) &translation->color)[3]);

			mjson_obj_add(obj, mjson_string(doc, UTL_CSTRTOARG("color")), mjson_string(doc, color, 8));
		}
	}

	if (translation->with.size != 0) {
		mjson_val* with = mjson_arr(doc);

		for (size_t i = 0; i < translation->with.size; ++i) {
			
			mjson_val* with_obj = mjson_obj(doc);

			cht_jsonify(doc, with_obj, UTL_VECTOR_GET_AS(cht_component_t*, &translation->with, i));

			mjson_arr_append(with, with_obj);

		}

		mjson_obj_add(obj, mjson_string(doc, UTL_CSTRTOARG("with")), with);
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