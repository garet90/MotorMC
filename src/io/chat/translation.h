#pragma once
#include "../../main.h"
#include "chat.h"

typedef enum {

    cht_translation_cht_type_text

} cht_translation_type_t;

typedef struct {

    cht_translation_type_t translate;

    utl_vector_t with;

} cht_translation_t;

static /*in-plugin*/ const cht_translation_t cht_translation_new = {
	.with = {
		.bytes_per_element = sizeof(cht_component_t*)
	}
};

static inline void cht_add_with(cht_translation_t* translation, const cht_component_t* with) {
	utl_vector_push(&translation->with, &with);
}

extern void cht_jsonify_translation(yyjson_mut_doc*, yyjson_mut_val*, const cht_translation_t*);
extern size_t cht_write_translation(const cht_translation_t*, char*);

extern void cht_term_translation(cht_translation_t* translation);