#pragma once

#include "translation.d.h"
#include "chat.d.h"

#include "../../main.h"
#include "../json/mjson.h"
#include "../../util/vector.h"

struct cht_translation {

	cht_translation_type_t translate;

	cht_color_t color;

	utl_vector_t with;

};

static /*in-plugin*/ const cht_translation_t cht_translation_new = {
	.color = cht_no_color,
	.with = UTL_VECTOR_INITIALIZER(cht_component_t*)
};

static inline void cht_add_with(cht_translation_t* translation, const cht_component_t* with) {
	utl_vector_push(&translation->with, &with);
}

extern void cht_jsonify_translation(mjson_doc*, mjson_val*, const cht_translation_t*);
extern size_t cht_write_translation(const cht_translation_t*, char*);

static inline void cht_term_translation(cht_translation_t* translation) {
	utl_term_vector(&translation->with);
}