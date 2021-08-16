#pragma once
#include "mjson.h"

size_t _mjson_read_val(mjson_doc* doc, const char* bytes, mjson_val** val_out);

static inline size_t _mjson_read_whitespace(const char* bytes) {

	size_t i = 0;

	for (;; ++i) {
		switch (bytes[i]) {
			case ' ':
			case '\n':
			case '\r':
			case '\t':
				continue;
			default:
				return i;
		}
	}

}

size_t _mjson_write_val(mjson_val* val, char* bytes);

void _mjson_doc_add(mjson_doc* doc, mjson_val* val);

void _mjson_free_val(mjson_val* val);