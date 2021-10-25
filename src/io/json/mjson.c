#include "mjson_private.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

mjson_doc* mjson_new() {

	return calloc(1, sizeof(mjson_doc));

}

mjson_doc* mjson_read(const char* read, size_t length) {

	size_t i = _mjson_read_whitespace(read + 0);
	mjson_doc* doc = mjson_new();

	do {
		i += _mjson_read_val(doc, read + i, NULL);
	} while (i < length);

	if (doc->count > 0) {
		doc->root = doc->values[0];
	}

	return doc;

}

mjson_doc* mjson_read_file(const char* file) {

	FILE* f = fopen(file, "rb");

	if (f == NULL) {
		return NULL;
	}

	fseek(f, 0, SEEK_END);
	size_t fsize = ftell(f);
	fseek(f, 0, SEEK_SET);

	char* bytes = malloc(fsize + 1);
	if (fread(bytes, 1, fsize, f) < fsize) {
		fclose(f);
		free(bytes);
		return NULL;
	}
	fclose(f);
	bytes[fsize] = '\0';

	mjson_doc* doc = mjson_read(bytes, fsize);

	free(bytes);

	return doc;

}

size_t _mjson_read_val(mjson_doc* doc, const char* bytes, mjson_val** val_out) {

	size_t i = 0;

	mjson_val* val = NULL;

	switch (bytes[i]) {
		case '{': { // object
			val = mjson_obj(doc);
			i++; // '{'
			i += _mjson_read_whitespace(bytes + i);
			while (bytes[i] != '}') {
				mjson_val* label;
				i += _mjson_read_val(doc, bytes + i, &label);

				i++; // ':'
				i += _mjson_read_whitespace(bytes + i);

				mjson_val* value;
				i += _mjson_read_val(doc, bytes + i, &value);

				if (bytes[i] == ',')
					i++;

				i += _mjson_read_whitespace(bytes + i);

				mjson_obj_add(val, label, value);
			}
			i++;
		} break;
		case '[': { // array
			val = mjson_arr(doc);
			i++; // '['
			i += _mjson_read_whitespace(bytes + i);
			while (bytes[i] != ']') {
				mjson_val* arr_item;
				i += _mjson_read_val(doc, bytes + i, &arr_item);
				
				if (bytes[i] == ',')
					i++;
					
				i += _mjson_read_whitespace(bytes + i);

				mjson_arr_append(val, arr_item);
			}
			i++;
		} break;
		case '"': { // string
			i++;
			size_t start = i;

			for (; bytes[i] != '"' && bytes[i - 1] != '\\'; ++i);

			val = mjson_string(doc, (const char*) bytes + start, i - start);

			i++;
		} break;
		case 't': { // true
			val = mjson_boolean(doc, 1);
			i += 4;
		} break;
		case 'f': { // false
			val = mjson_boolean(doc, 0);
			i += 5;
		} break;
		case 'n': { // null
			val = mjson_null(doc);
			i += 4;
		} break;
		case '-': // number
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9': {
			int64_t w = 0;
			double d = 0;
			uint8_t negative = 0;
			double fraction = 0;

			for (;; ++i) {
				switch (bytes[i]) {
					case '-': {
						negative = 1;
					} break;
					case '0':
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9': {
						if (fraction != 0) {
							d += (bytes[i] - '0') * fraction;
							fraction /= 10;
						} else {
							w = (w * 10) + (bytes[i] - '0');
							d = (d * 10) + (bytes[i] - '0');
						}
					} break;
					case '.': {
						fraction = 0.1;
					} break;
					default: {
						if (fraction != 0) {
							val = mjson_double(doc, negative ? -d : d);
						} else {
							val = mjson_int(doc, negative ? -w : w);
						}
						goto done;
					}
				}
			}

			done:
			break;
		} break;
	}

	if (val_out != NULL) {
		*val_out = val;
	}

	i += _mjson_read_whitespace(bytes + i);

	return i;

}

size_t mjson_write(mjson_doc* doc, char* write) {

	size_t size = _mjson_write_val(mjson_get_root(doc), write);
	write[size] = '\0';

	return size;

}

size_t _mjson_write_val(mjson_val* val, char* bytes) {

	size_t i = 0;

	switch (val->type) {
		case MJSON_OBJECT: {
			bytes[0] = '{';
			i += 1;
			for (uint32_t j = 0; j < val->value.Object.size; ++j) {
				if (j != 0) {
					bytes[i] = ',';
					i += 1;
				}
				mjson_property property = val->value.Object.properties[j];
				i += _mjson_write_val(property.label, bytes + i);
				bytes[i] = ':';
				i += 1;
				i += _mjson_write_val(property.value, bytes + i);
			}
			bytes[i] = '}';
			i += 1;
		} break;
		case MJSON_ARRAY: {
			bytes[0] = '[';
			i += 1;
			for (uint32_t j = 0; j < val->value.Array.size; ++j) {
				if (j != 0) {
					bytes[i] = ',';
					i += 1;
				}
				i += _mjson_write_val(val->value.Array.values[j], bytes + i);
			}
			bytes[i] = ']';
			i += 1;
		} break;
		case MJSON_STRING: {
			bytes[i++] = '"';
			for (uint32_t j = 0; j < val->value.String.length; ++j) {
				switch (val->value.String.value[j]) {
					case '"': {
						bytes[i++] = '\\';
						bytes[i++] = '"';
					} break;
					case '\\': {
						bytes[i++] = '\\';
						bytes[i++] = '\\';
					} break;
					case '/': {
						bytes[i++] = '\\';
						bytes[i++] = '/';
					} break;
					case '\b': {
						bytes[i++] = '\\';
						bytes[i++] = 'b';
					} break;
					case '\f': {
						bytes[i++] = '\\';
						bytes[i++] = 'f';
					} break;
					case '\n': {
						bytes[i++] = '\\';
						bytes[i++] = 'n';
					} break;
					case '\r': {
						bytes[i++] = '\\';
						bytes[i++] = 'r';
					} break;
					case '\t': {
						bytes[i++] = '\\';
						bytes[i++] = 't';
					} break;
					default: {
						bytes[i++] = val->value.String.value[j];
					} break;
				}
			}
			bytes[i++] = '"';
		} break;
		case MJSON_INTEGER: {
			i = sprintf((char*) bytes, "%lld", (long long int) val->value.Integer);
		} break;
		case MJSON_DOUBLE: {
			i = sprintf((char*) bytes, "%9.7lf", val->value.Double);
		} break;
		case MJSON_BOOLEAN: {
			if (val->value.Boolean) {
				bytes[0] = 't';
				bytes[1] = 'r';
				bytes[2] = 'u';
				bytes[3] = 'e';
				i = 4;
			} else {
				bytes[0] = 'f';
				bytes[1] = 'a';
				bytes[2] = 'l';
				bytes[3] = 's';
				bytes[4] = 'e';
				i = 5;
			}
		} break;
		case MJSON_NULL: {
			bytes[0] = 'n';
			bytes[1] = 'u';
			bytes[2] = 'l';
			bytes[3] = 'l';
			i = 4;
		} break;
	}

	return i;

}

mjson_val* mjson_string(mjson_doc* doc, const char* string, uint32_t length) {

	mjson_val* str = malloc(sizeof(mjson_val));
	str->type = MJSON_STRING;
	str->value.String.length = length;
	str->value.String.value = malloc(length + 1);
	memcpy(str->value.String.value, string, length);
	str->value.String.value[length] = '\0';

	_mjson_doc_add(doc, str);

	return str;

}

mjson_val* mjson_int(mjson_doc* doc, int64_t val) {

	mjson_val* i = malloc(sizeof(mjson_val));
	i->type = MJSON_INTEGER;
	i->value.Integer = val;

	_mjson_doc_add(doc, i);

	return i;

}

mjson_val* mjson_double(mjson_doc* doc, double val) {

	mjson_val* d = malloc(sizeof(mjson_val));
	d->type = MJSON_DOUBLE;
	d->value.Double = val;

	_mjson_doc_add(doc, d);

	return d;

}

mjson_val* mjson_boolean(mjson_doc* doc, uint8_t val) {

	mjson_val* b = malloc(sizeof(mjson_val));
	b->type = MJSON_BOOLEAN;
	b->value.Boolean = val;

	_mjson_doc_add(doc, b);

	return b;

}

mjson_val* mjson_arr(mjson_doc* doc) {

	mjson_val* arr = calloc(1, sizeof(mjson_val));
	arr->type = MJSON_ARRAY;

	_mjson_doc_add(doc, arr);

	return arr;

}

void mjson_arr_append(mjson_val* arr, mjson_val* value) {

	if (arr->value.Array.size >= arr->value.Array.cap) {
		arr->value.Array.cap = (arr->value.Array.cap > 0 ? arr->value.Array.cap << 1 : 2);
		arr->value.Array.values = realloc(arr->value.Array.values, sizeof(mjson_val*) * arr->value.Array.cap);
	}

	arr->value.Array.values[arr->value.Array.size++] = value;

}

mjson_val* mjson_obj(mjson_doc* doc) {

	mjson_val* obj = calloc(1, sizeof(mjson_val));
	obj->type = MJSON_OBJECT;

	_mjson_doc_add(doc, obj);

	return obj;

}

void mjson_obj_add(mjson_val* obj, mjson_val* label, mjson_val* value) {

	if (obj->value.Object.size >= obj->value.Object.cap) {
		obj->value.Object.cap = (obj->value.Object.cap > 0 ? obj->value.Object.cap << 1 : 2);
		obj->value.Object.properties = realloc(obj->value.Object.properties, sizeof(mjson_property) * obj->value.Object.cap);
	}

	obj->value.Object.properties[obj->value.Object.size].label = label;
	obj->value.Object.properties[obj->value.Object.size++].value = value;

}

mjson_val* mjson_null(mjson_doc* doc) {
	
	mjson_val* null = malloc(sizeof(mjson_val));
	null->type = MJSON_NULL;

	_mjson_doc_add(doc, null);

	return null;

}

void _mjson_doc_add(mjson_doc* doc, mjson_val* val) {

	if (doc->count >= doc->cap) {
		doc->cap = (doc->cap > 0 ? doc->cap << 1 : 2);
		doc->values = realloc(doc->values, sizeof(mjson_val*) * doc->cap);
	}

	doc->values[doc->count++] = val;

}

void mjson_free(mjson_doc* doc) {

	for (uint32_t i = 0; i < doc->count; ++i) {
		_mjson_free_val(doc->values[i]);
	}

	free(doc->values);
	free(doc);

}

void _mjson_free_val(mjson_val* val) {

	switch (val->type) {
		case MJSON_OBJECT: {
			free(val->value.Object.properties);
		} break;
		case MJSON_ARRAY: {
			free(val->value.Array.values);
		} break;
		case MJSON_STRING: {
			free(val->value.String.value);
		} break;
		default: {
			// do nothing
		} break;
	}

	free(val);

}