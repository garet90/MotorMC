#pragma once

#include <stddef.h>
#include <stdint.h>

/*
Which compression to use
*/
typedef enum {

	MNBT_NONE = 0,
	MNBT_GZIP = 1,
	MNBT_ZLIB = 2

} mnbt_compression;

/*
A NBT type
*/
typedef enum {

	MNBT_END = 0,
	MNBT_BYTE = 1,
	MNBT_SHORT = 2,
	MNBT_INT = 3,
	MNBT_LONG = 4,
	MNBT_FLOAT = 5,
	MNBT_DOUBLE = 6,
	MNBT_BYTE_ARRAY = 7,
	MNBT_STRING = 8,
	MNBT_LIST = 9,
	MNBT_COMPOUND = 10,
	MNBT_INT_ARRAY = 11,
	MNBT_LONG_ARRAY = 12

} mnbt_type;

/*
A NBT value
Can be any valid NBT type and can hold data
*/
typedef union mnbt_val mnbt_val;

/*
A NBT tag
Has a label, type, and a value
*/
typedef struct mnbt_tag mnbt_tag;

union mnbt_val {

	int8_t Byte;
	int16_t Short;
	int32_t Int;
	int64_t Long;
	float Float;
	double Double;
	struct {
		uint32_t size;
		int8_t* bytes;
	} Byte_Array;
	struct {
		uint16_t length;
		char* string;
	} String;
	struct {
		uint32_t size;
		uint32_t cap;
		mnbt_type type;
		mnbt_val* list;
	} List;
	struct {
		uint32_t size;
		uint32_t cap;
		mnbt_tag** tags;
	} Compound;
	struct {
		uint32_t size;
		int32_t* ints;
	} Int_Array;
	struct {
		uint32_t size;
		int64_t* longs;
	} Long_Array;

};

struct mnbt_tag {

	mnbt_type type;
	
	uint16_t label_length;
	char* label;

	mnbt_val value;

};

/*
A NBT document
Holds references to all allocated tags and the root tag for traversing through the document
*/
typedef struct {

	struct {
		
		uint32_t count;
		uint32_t cap;
		mnbt_tag** tags;

	};

	mnbt_tag* root;

} mnbt_doc;

/*
Create a fresh NBT document for reading and writing
*/
mnbt_doc* mnbt_new();

/*
Read vlaues 'bytes' byte array until 'length' has been reached.
*/
mnbt_doc* mnbt_read(const uint8_t* bytes, size_t length, mnbt_compression compression);

/*
Read file as NBT document for reading and editing
*/
mnbt_doc* mnbt_read_file(const char* file, mnbt_compression compression);

/*
Write the document to byte array, starting at the root tag and working inward
Returns the length of the NBT in byte form
*/
size_t mnbt_write(mnbt_doc* document, uint8_t* bytes, mnbt_compression compression);

/*
Write the document to the file, starting at the root tag and working inward
Returns the length of the resulting file or 0 on error
*/
size_t mnbt_write_file(mnbt_doc* document, const char* file, size_t max_file_length, mnbt_compression compression);

/*
Create new tag with label and value
*/
mnbt_tag* mnbt_new_tag(mnbt_doc* document, const char* label, uint16_t label_length, mnbt_type type, mnbt_val value);

/*
Get the root tag of the document
If there are multiple tags in the root the last will become the root
*/
static inline mnbt_tag* mnbt_get_root(mnbt_doc* document) {
	return document->root;
}

/*
Set the root tag of the document
Any tag can be set as the root, even roots with parents
*/
static inline void mnbt_set_root(mnbt_doc* document, mnbt_tag* tag) {
	document->root = tag;
}

/*
Get the size of the tag's value
Works for Byte Arrays, Lists, Compound Tags, Int Arrays, and Long Arrays
Does NOT work with strings
*/
static inline uint32_t mnbt_get_size(mnbt_tag* tag) {
	return tag->value.Byte_Array.size;
}

/*
Get the size of the value
Works for Byte Arrays, Lists, Compound Tags, Int Arrays, and Long Arrays
Does NOT work with strings
*/
static inline uint32_t mnbt_val_get_size(mnbt_val val) {
	return val.Byte_Array.size;
}

/*
Get the length of the tag's value
ONLY works for strings
*/
static inline uint16_t mnbt_get_length(mnbt_tag* tag) {
	return tag->value.String.length;
}

/*
Get the length of the value
ONLY works for strings
*/
static inline uint16_t mnbt_val_get_length(mnbt_val val) {
	return val.String.length;
}

/*
Get the type of the tag
*/
static inline mnbt_type mnbt_get_type(mnbt_tag* tag) {
	return tag->type;
}

/*
Get the length of the label of the tag
Faster than strlen() as length is cached
*/
static inline uint16_t mnbt_get_label_length(mnbt_tag* tag) {
	return tag->label_length;
}

/*
Get the label of the tag
*/
static inline const char* mnbt_get_label(mnbt_tag* tag) {
	return tag->label;
}

static inline int8_t mnbt_get_byte(mnbt_tag* tag) {
	return tag->value.Byte;
}

static inline int8_t mnbt_val_get_byte(mnbt_val val) {
	return val.Byte;
}

static inline mnbt_val mnbt_val_byte(int8_t value) {
	mnbt_val val = {
		.Byte = value
	};

	return val;
}

static inline int16_t mnbt_get_short(mnbt_tag* tag) {
	return tag->value.Short;
}

static inline int16_t mnbt_val_get_short(mnbt_val val) {
	return val.Short;
}

static inline mnbt_val mnbt_val_short(int16_t value) {
	mnbt_val val = {
		.Short = value
	};

	return val;
}

static inline int32_t mnbt_get_int(mnbt_tag* tag) {
	return tag->value.Int;
}

static inline int32_t mnbt_val_get_int(mnbt_val val) {
	return val.Int;
}

static inline mnbt_val mnbt_val_int(int32_t value) {
	mnbt_val val = {
		.Int = value
	};

	return val;
}

static inline int64_t mnbt_get_long(mnbt_tag* tag) {
	return tag->value.Long;
}

static inline int64_t mnbt_val_get_long(mnbt_val val) {
	return val.Long;
}

static inline mnbt_val mnbt_val_long(int64_t value) {
	mnbt_val val = {
		.Long = value
	};

	return val;
}

static inline float mnbt_get_float(mnbt_tag* tag) {
	return tag->value.Float;
}

static inline float mnbt_val_get_float(mnbt_val val) {
	return val.Float;
}

static inline mnbt_val mnbt_val_float(float value) {
	mnbt_val val = {
		.Float = value
	};

	return val;
}

static inline double mnbt_get_double(mnbt_tag* tag) {
	return tag->value.Double;
}

static inline double mnbt_val_get_double(mnbt_val val) {
	return val.Double;
}

static inline mnbt_val mnbt_val_double(double value) {
	mnbt_val val = {
		.Double = value
	};

	return val;
}

static inline const char* mnbt_get_string(mnbt_tag* tag) {
	return tag->value.String.string;
}

static inline const char* mnbt_val_get_string(mnbt_val val) {
	return val.String.string;
}

mnbt_val mnbt_val_string(const char* string, uint16_t length);

static inline int8_t* mnbt_get_byte_array(mnbt_tag* tag) {
	return tag->value.Byte_Array.bytes;
}

static inline int8_t* mnbt_val_get_byte_array(mnbt_val val) {
	return val.Byte_Array.bytes;
}

mnbt_val mnbt_val_byte_array(int8_t* bytes, uint32_t size);

static inline int32_t* mnbt_get_int_array(mnbt_tag* tag) {
	return tag->value.Int_Array.ints;
}

static inline int32_t* mnbt_val_get_int_array(mnbt_val val) {
	return val.Int_Array.ints;
}

mnbt_val mnbt_val_int_array(int32_t* ints, uint32_t size);

static inline int64_t* mnbt_get_long_array(mnbt_tag* tag) {
	return tag->value.Long_Array.longs;
}

static inline int64_t* mnbt_val_get_long_array(mnbt_val val) {
	return val.Long_Array.longs;
}

mnbt_val mnbt_val_long_array(int64_t* longs, uint32_t size);

static inline mnbt_tag* mnbt_get_tag(mnbt_tag* tag, uint32_t idx) {
	return tag->value.Compound.tags[idx];
}

static inline mnbt_tag* mnbt_val_get_tag(mnbt_val val, uint32_t idx) {
	return val.Compound.tags[idx];
}

void mnbt_val_push_tag(mnbt_val* value, mnbt_tag* tag);

static inline void mnbt_val_set_tag(mnbt_val* value, uint32_t idx, mnbt_tag* tag) {
	value->Compound.tags[idx] = tag;
}

static inline void mnbt_push_tag(mnbt_tag* tag, mnbt_tag* value) {
	mnbt_val_push_tag(&tag->value, value);
}

static inline void mnbt_set_tag(mnbt_tag* tag, uint32_t idx, mnbt_tag* value) {
	tag->value.Compound.tags[idx] = value;
}

static inline mnbt_val mnbt_val_compound() {
	mnbt_val val = {
		.Compound = {
			.size = 0,
			.cap = 0,
			.tags = NULL
		}
	};
	
	return val;
}

static inline mnbt_type mnbt_get_list_type(mnbt_tag* tag) {
	return tag->value.List.type;
}

static inline mnbt_type mnbt_val_get_list_type(mnbt_val val) {
	return val.List.type;
}

static inline mnbt_val mnbt_get_list(mnbt_tag* tag, uint32_t idx) {
	return tag->value.List.list[idx];
}

static inline mnbt_val mnbt_val_get_list(mnbt_val val, uint32_t idx) {
	return val.List.list[idx];
}

static inline mnbt_val mnbt_val_list(mnbt_type type) {
	mnbt_val val = {
		.List = {
			.size = 0,
			.cap = 0,
			.type = type,
			.list = NULL
		}
	};
	
	return val;
}

void mnbt_val_list_push(mnbt_val* list, mnbt_val val);

static inline void mnbt_list_push(mnbt_tag* tag, mnbt_val val) {
	mnbt_val_list_push(&tag->value, val);
}

void mnbt_free(mnbt_doc* document);