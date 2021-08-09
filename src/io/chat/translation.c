#include "translation.h"

void cht_jsonify_translation(yyjson_mut_doc* doc, yyjson_mut_val* obj, const cht_translation_t* translation) {

    const char* translations[] = {
        "chat.type.text",
        "multiplayer.player.joined",
        "multiplayer.player.left"
    };

    yyjson_mut_obj_add(obj, yyjson_mut_str(doc, "translate"), yyjson_mut_str(doc, translations[translation->translate]));

    if (translation->color != cht_nocolor) {
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

			yyjson_mut_obj_add(obj, yyjson_mut_str(doc, "color"), yyjson_mut_str(doc, colors[translation->color]));
		} else {
			char color[9];
			sprintf(color, "%x", translation->color);
			yyjson_mut_obj_add(obj, yyjson_mut_str(doc, "color"), yyjson_mut_str(doc, color));
		}
	}

    if (translation->with.size != 0) {
        yyjson_mut_val* with = yyjson_mut_arr(doc);

        for (size_t i = 0; i < translation->with.size; ++i) {
            
            yyjson_mut_val* with_obj = yyjson_mut_obj(doc);

            cht_jsonify(doc, with_obj, UTL_VECTOR_GET_AS(cht_component_t*, &translation->with, i));

            yyjson_mut_arr_append(with, with_obj);

        }

        yyjson_mut_obj_add(obj, yyjson_mut_str(doc, "with"), with);
    }

}

size_t cht_write_translation(const cht_translation_t* translation, char* message) {

	yyjson_mut_doc* doc = yyjson_mut_doc_new(NULL);
	yyjson_mut_val* obj = yyjson_mut_obj(doc);
	yyjson_mut_doc_set_root(doc, obj);

	cht_jsonify_translation(doc, obj, translation);

    size_t str_len;
	char* str = yyjson_mut_write(doc, YYJSON_WRITE_NOFLAG, &str_len);
    memcpy(message, str, str_len);

	free(str);

	yyjson_mut_doc_free(doc);

	return str_len;

}

void cht_term_translation(cht_translation_t* translation) {
    
    utl_vector_term(&translation->with);

}