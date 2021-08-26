#include "mnbt_private.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libdeflate.h>

mnbt_doc* mnbt_new() {
	return calloc(1, sizeof(mnbt_doc));
}

mnbt_doc* mnbt_read(const uint8_t* bytes, size_t length, mnbt_compression compression) {

	size_t i = 0;

	switch (compression) {
		case MNBT_NONE: {

			mnbt_doc* doc = mnbt_new();
			do {
			   i +=  _mnbt_read_tag(doc, NULL, bytes + i);
			} while (i < length);

			if (doc->count != 0) {
				doc->root = doc->tags[doc->count - 1];
			}

			return doc;
		}
		case MNBT_GZIP: {
			struct libdeflate_decompressor* decompressor = libdeflate_alloc_decompressor();
			uint8_t d_bytes[length * 4];
			
			if (libdeflate_gzip_decompress(decompressor, bytes, length, d_bytes, length * 4, &length) != LIBDEFLATE_SUCCESS)
				return NULL;
			
			libdeflate_free_decompressor(decompressor);

			mnbt_doc* doc = mnbt_new();
			do {
				i += _mnbt_read_tag(doc, NULL, d_bytes + i);
			} while (i < length);

			if (doc->count != 0) {
				doc->root = doc->tags[doc->count - 1];
			}

			return doc;
		}
		case MNBT_ZLIB: {
			struct libdeflate_decompressor* decompressor = libdeflate_alloc_decompressor();
			uint8_t d_bytes[length * 4];
			if (libdeflate_zlib_decompress(decompressor, bytes, length, d_bytes, length * 4, &length) != LIBDEFLATE_SUCCESS)
				return NULL;
			
			libdeflate_free_decompressor(decompressor);

			mnbt_doc* doc = mnbt_new();
			do {
				i += _mnbt_read_tag(doc, NULL, d_bytes + i);
			} while (i < length);

			if (doc->count != 0) {
				doc->root = doc->tags[doc->count - 1];
			}

			return doc;
		}
		default: {
			return NULL;
		}
	}

}

mnbt_doc* mnbt_read_file(const char* file, mnbt_compression compression) {

	FILE* f = fopen(file, "rb");

	if (f == NULL) {
		return NULL;
	}

	fseek(f, 0, SEEK_END);
	size_t fsize = ftell(f);
	fseek(f, 0, SEEK_SET);

	uint8_t* bytes = malloc(fsize);
	if (fread(bytes, 1, fsize, f) < fsize) {
		fclose(f);
		free(bytes);
		return NULL;
	}
	fclose(f);

	mnbt_doc* doc = mnbt_read(bytes, fsize, compression);

	free(bytes);

	return doc;

}

size_t _mnbt_read_tag(mnbt_doc* document, mnbt_tag** tag_out, const uint8_t* bytes) {

	mnbt_tag* tag = malloc(sizeof(mnbt_tag));

	if (tag_out != NULL) {
		*tag_out = tag;
	}
	
	// read tagId
	tag->type = bytes[0];

	if (tag->type == MNBT_END) {
		tag->label_length = 0;
		tag->label = NULL;
		_mnbt_add(document, tag);
		return 1;
	}

	tag->label_length = _mnbt_reverse_short(*((uint16_t*) (bytes + 1)));

	tag->label = malloc(tag->label_length + 1);
	memcpy(tag->label, bytes + 3, tag->label_length);
	tag->label[tag->label_length] = 0;
	size_t length = 3 + tag->label_length;

	length += _mnbt_read_val(document, tag->type, &tag->value, bytes + length);

	_mnbt_add(document, tag);

	return length;

}

mnbt_tag* mnbt_new_tag(mnbt_doc* document, const char* label, uint16_t label_length, mnbt_type type, mnbt_val value) {

	mnbt_tag* tag = malloc(sizeof(mnbt_tag));

	tag->type = type;

	tag->label_length = label_length;
	tag->label = malloc(label_length + 1);
	memcpy(tag->label, label, label_length);
	tag->label[label_length] = 0;

	tag->value = value;

	_mnbt_add(document, tag);

	return tag;

}

size_t _mnbt_read_val(mnbt_doc* document, mnbt_type type, mnbt_val* value, const uint8_t* bytes) {

	switch (type) {
		case MNBT_END: {
			return 0;
		}
		case MNBT_BYTE: {
			value->Byte = *bytes;
			return 1;
		}
		case MNBT_SHORT: {
			value->Short = _mnbt_reverse_short(*((int16_t*) bytes));
			return 2;
		}
		case MNBT_INT: {
			value->Int = _mnbt_reverse_int(*((int32_t*) bytes));
			return 4;
		}
		case MNBT_LONG: {
			value->Long = _mnbt_reverse_long(*((int64_t*) bytes));
			return 8;
		}
		case MNBT_FLOAT: {
			value->Float = _mnbt_reverse_float(*((float*) bytes));
			return 4;
		}
		case MNBT_DOUBLE: {
			value->Double = _mnbt_reverse_double(*((double*) bytes));
			return 8;
		}
		case MNBT_BYTE_ARRAY: {
			value->Byte_Array.size = _mnbt_reverse_int(*((uint32_t*) bytes));
			bytes += 4;
			value->Byte_Array.bytes = malloc(value->Byte_Array.size);
			memcpy(value->Byte_Array.bytes, bytes, value->Byte_Array.size);
			return value->Byte_Array.size + 4;
		}
		case MNBT_STRING: {
			value->String.length = _mnbt_reverse_short(*((uint16_t*) bytes));
			bytes += 2;
			value->String.string = malloc(value->String.length + 1);
			memcpy(value->String.string, bytes, value->String.length);
			value->String.string[value->String.length] = 0;
			return value->String.length + 2;
		}
		case MNBT_LIST: {
			value->List.type = bytes[0];
			bytes += 1;
			value->List.size = _mnbt_reverse_int(*((uint32_t*) bytes));
			bytes += 4;

			value->List.list = malloc(sizeof(mnbt_val) * value->List.size);
			
			size_t length = 0;
			for (uint32_t i = 0; i < value->List.size; ++i) {
				length += _mnbt_read_val(document, value->List.type, value->List.list + i, bytes + length);
			}

			return 5 + length;
		}
		case MNBT_COMPOUND: {
			
			value->Compound.size = 0;
			mnbt_tag* tag = NULL;
			
			size_t length = 0;
			
			value->Compound.cap = 2;
			value->Compound.tags = malloc(sizeof(mnbt_tag) * 2);

			for(;;) {

				length += _mnbt_read_tag(document, &tag, bytes + length);
				
				if (tag->type == MNBT_END) {
					break;
				}

				if (value->Compound.size == value->Compound.cap) {
					value->Compound.cap *= 2;
					value->Compound.tags = realloc(value->Compound.tags, sizeof(mnbt_tag) * value->Compound.cap);
				}

				value->Compound.tags[value->Compound.size++] = tag; 

			}

			return length;
		}
		case MNBT_INT_ARRAY: {
			value->Int_Array.size = _mnbt_reverse_int(*((uint32_t*) bytes));
			bytes += 4;
			value->Int_Array.ints = malloc(value->Int_Array.size * 4);
			for (uint32_t i = 0; i < value->Int_Array.size; ++i) {
				value->Int_Array.ints[i] = _mnbt_reverse_int(((uint32_t*) bytes)[i]);
			}
			return (value->Int_Array.size * 4) + 4;
		}
		case MNBT_LONG_ARRAY: {
			value->Long_Array.size = _mnbt_reverse_int(*((uint32_t*) bytes));
			bytes += 4;
			value->Long_Array.longs = malloc(value->Long_Array.size * 8);
			for (uint32_t i = 0; i < value->Long_Array.size; ++i) {
				value->Long_Array.longs[i] = _mnbt_reverse_long(((uint64_t*) bytes)[i]);
			}
			return (value->Long_Array.size * 8) + 4;
		}
		default: {
			return 0;
		}
	}

}

void _mnbt_add(mnbt_doc* document, mnbt_tag* tag) {

	if (document->count == document->cap) {
		if (document->cap == 0) {
			document->cap = 2;
			document->tags = malloc(sizeof(mnbt_tag*) * 2);
		} else {
			document->cap *= 2;
			document->tags = realloc(document->tags, sizeof(mnbt_tag*) * document->cap);
		}
	}

	document->tags[document->count++] = tag;

}

size_t mnbt_write(mnbt_doc* document, uint8_t* bytes, mnbt_compression compression) {

	size_t length = _mnbt_write_tag(mnbt_get_root(document), bytes);

	switch (compression) {
		case MNBT_NONE: {
			return length;
		}
		case MNBT_GZIP: {
			struct libdeflate_compressor* compressor = libdeflate_alloc_compressor(12);
			length = libdeflate_gzip_compress(compressor, bytes, length, bytes, length * 4);
			libdeflate_free_compressor(compressor);

			return length;
		}
		case MNBT_ZLIB: {
			struct libdeflate_compressor* compressor = libdeflate_alloc_compressor(12);
			length = libdeflate_zlib_compress(compressor, bytes, length, bytes, length * 4);
			libdeflate_free_compressor(compressor);

			return length;
		}
		default: {
			return 0;
		}
	}

}

size_t mnbt_write_file(mnbt_doc* document, const char* file, size_t max_file_length, mnbt_compression compression) {

	uint8_t buffer[max_file_length];
	const size_t size = mnbt_write(document, buffer, compression);

	FILE* f = fopen(file, "wb");

	fwrite(buffer, size, 1, f);

	fclose(f);

	return size;

}

size_t _mnbt_write_tag(mnbt_tag* tag, uint8_t* bytes) {

	// write type id
	*bytes = (uint8_t) tag->type;
	bytes += 1;

	if (tag->type == MNBT_END) {
		return 1;
	}

	// write length of label
	*((uint16_t*) bytes) = _mnbt_reverse_short(tag->label_length);
	bytes += 2;

	memcpy(bytes, tag->label, tag->label_length);
	bytes += tag->label_length;

	const size_t val_len = _mnbt_write_val(tag->type, tag->value, bytes);

	return val_len + 3 + tag->label_length;

}

size_t _mnbt_write_val(mnbt_type type, mnbt_val val, uint8_t* bytes) {

	switch (type) {
		case MNBT_END: {
			return 0;
		}
		case MNBT_BYTE: {
			*bytes = val.Byte;
			return 1;
		}
		case MNBT_SHORT: {
			*((uint16_t*) bytes) = _mnbt_reverse_short(val.Short);
			return 2;
		}
		case MNBT_INT: {
			*((uint32_t*) bytes) = _mnbt_reverse_int(val.Int);
			return 4;
		}
		case MNBT_LONG: {
			*((uint64_t*) bytes) = _mnbt_reverse_long(val.Long);
			return 8;
		}
		case MNBT_FLOAT: {
			*((float*) bytes) = _mnbt_reverse_float(val.Float);
			return 4;
		}
		case MNBT_DOUBLE: {
			*((double*) bytes) = _mnbt_reverse_double(val.Double);
			return 8;
		}
		case MNBT_BYTE_ARRAY: {
			*((uint32_t*) bytes) = _mnbt_reverse_int(val.Byte_Array.size);
			bytes += 4;
			memcpy(bytes, val.Byte_Array.bytes, val.Byte_Array.size);
			return val.Byte_Array.size + 4;
		}
		case MNBT_STRING: {
			*((uint16_t*) bytes) = _mnbt_reverse_short(val.String.length);
			bytes += 2;
			memcpy(bytes, val.String.string, val.String.length);
			return val.String.length + 2;
		}
		case MNBT_LIST: {
			*bytes = val.List.type;
			*((uint32_t*) (bytes + 1)) = _mnbt_reverse_int(val.List.size);

			size_t length = 5;
			for (uint32_t i = 0; i < val.List.size; ++i) {
				length += _mnbt_write_val(val.List.type, val.List.list[i], bytes + length);
			}

			return length;
		}
		case MNBT_COMPOUND: {
			
			size_t length = 0;
			for (uint32_t i = 0; i < val.Compound.size; ++i) {
				length += _mnbt_write_tag(val.Compound.tags[i], bytes + length);
			}

			// write tag_end
			bytes[length++] = 0;

			return length;

		}
		case MNBT_INT_ARRAY: {
			*((uint32_t*) bytes) = _mnbt_reverse_int(val.Int_Array.size);
			bytes += 4;
			size_t length = 4;
			for (uint32_t i = 0; i < val.Int_Array.size; ++i) {
				*((int32_t*) bytes) = _mnbt_reverse_int(val.Int_Array.ints[i]);
				bytes += 4;
				length += 4;
			}

			return length;
		}
		case MNBT_LONG_ARRAY: {
			*((uint32_t*) bytes) = _mnbt_reverse_int(val.Long_Array.size);
			bytes += 4;
			size_t length = 4;
			for (uint32_t i = 0; i < val.Long_Array.size; ++i) {
				*((int64_t*) bytes) = _mnbt_reverse_long(val.Long_Array.longs[i]);
				bytes += 8;
				length += 8;
			}

			return length;
		}
		default: {
			return 0;
		}
	}

}

mnbt_val mnbt_val_string(const char* string, uint16_t length) {
	mnbt_val val = {
		.String = {
			.length = length,
			.string = malloc(length + 1)
		}
	};
	memcpy(val.String.string, string, length);
	val.String.string[val.String.length] = 0;
	return val;
}

mnbt_val mnbt_val_byte_array(int8_t* bytes, uint32_t size) {
	mnbt_val val = {
		.Byte_Array = {
			.size = size,
			.bytes = malloc(size)
		}
	};
	memcpy(val.Byte_Array.bytes, bytes, size);
	return val;
}

mnbt_val mnbt_val_int_array(int32_t* ints, uint32_t size) {
	mnbt_val val = {
		.Int_Array = {
			.size = size,
			.ints = malloc(size * 4)
		}
	};
	memcpy(val.Int_Array.ints, ints, size * 4);
	return val;
}

mnbt_val mnbt_val_long_array(int64_t* longs, uint32_t size) {
	mnbt_val val = {
		.Long_Array = {
			.size = size,
			.longs = malloc(size * 8)
		}
	};
	memcpy(val.Long_Array.longs, longs, size * 8);
	return val;
}

void mnbt_val_push_tag(mnbt_val* value, mnbt_tag* tag) {

	if (value->Compound.size == value->Compound.cap) {
		if (value->Compound.cap == 0) {
			value->Compound.cap = 2;
			value->Compound.tags = malloc(sizeof(mnbt_tag*) * 2);
		} else {
			value->Compound.cap *= 2;
			value->Compound.tags = realloc(value->Compound.tags, sizeof(mnbt_tag*) * value->Compound.cap);
		}
	}

	value->Compound.tags[value->Compound.size++] = tag;

}

void mnbt_val_list_push(mnbt_val* list, mnbt_val val) {

	if (list->List.size == list->List.cap) {
		if (list->List.cap == 0) {
			list->List.cap = 2;
			list->List.list = malloc(sizeof(mnbt_tag) * 2);
		} else {
			list->List.cap *= 2;
			list->List.list = realloc(list->List.list, sizeof(mnbt_val) * list->List.cap);
		}
	}

	list->List.list[list->List.size++] = val;

}

void _mnbt_free_val(mnbt_type type, mnbt_val val) {

	switch (type) {
		case MNBT_BYTE_ARRAY: {
			free(val.Byte_Array.bytes);
			break;
		}
		case MNBT_STRING: {
			free(val.String.string);
			break;
		}
		case MNBT_LIST: {
			for (uint32_t i = 0; i < val.List.size; ++i) {
				_mnbt_free_val(val.List.type, val.List.list[i]);
			}
			free(val.List.list);
			break;
		}
		case MNBT_COMPOUND: {
			free(val.Compound.tags);
			break;
		}
		case MNBT_INT_ARRAY: {
			free(val.Int_Array.ints);
			break;
		}
		case MNBT_LONG_ARRAY: {
			free(val.Long_Array.longs);
			break;
		}
		default: {
			break;
		}
	}

}

void mnbt_free(mnbt_doc* document) {

	for (uint32_t i = 0; i < document->count; ++i) {
		
		mnbt_tag* tag = document->tags[i];

		free(tag->label);
		
		_mnbt_free_val(tag->type, tag->value);

		free(tag);

	}

	free(document->tags);
	free(document);

}