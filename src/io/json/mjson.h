#pragma once
#include <stddef.h>
#include <stdint.h>

/*
All supported JSON types
*/
typedef enum {

	MJSON_OBJECT,
	MJSON_ARRAY,
	MJSON_STRING,
	MJSON_INTEGER,
	MJSON_DOUBLE,
	MJSON_BOOLEAN,
	MJSON_NULL

} mjson_type;

/*
A JSON value. Use mjson_read_* functions to read this value
*/
typedef struct mjson_val mjson_val;

/*
An object property. Either get the label and value fields of this struct
or use mjson_property_get_* functions
*/
typedef struct {
	
	mjson_val* label;
	mjson_val* value;

} mjson_property;

struct mjson_val {

	mjson_type type : 3;

	union {

		struct {

			uint32_t size;
			uint32_t cap;
			mjson_property* properties;

		} Object;

		struct {

			uint32_t size;
			uint32_t cap;
			mjson_val** values;

		} Array;

		struct {

			uint32_t length;
			char* value;

		} String;

		int64_t Integer;
		
		double Double;

		uint8_t Boolean;

	} value;

};

/*
A JSON document. This holds the root tag as well as all tags in the document
*/
typedef struct {

	struct {
		
		uint32_t count;
		uint32_t cap;
		mjson_val** values;

	};

	mjson_val* root;

} mjson_doc;

/*
Create a fresh document for writing
*/
mjson_doc* mjson_new();

/*
Read a document from memory
*/
mjson_doc* mjson_read(const char* read, size_t length);

/*
Read a file as a document
*/
mjson_doc* mjson_read_file(const char* file);

/*
Write a file to memory
*/
size_t mjson_write(mjson_doc* doc, char* write);

/*
Write a file to the disk with max length
*/
size_t mjson_write_file(mjson_doc* doc, const char* file, size_t max_length);

/*
Get size of a value
For strings and arrays, this is the length
For objects, this is the number of properties
*/
static inline uint32_t mjson_get_size(mjson_val* val) {
	return val->value.String.length;
}

/*
Get the root element of the object
*/
static inline mjson_val* mjson_get_root(mjson_doc* doc) {
	return doc->root;
}

/*
Set the root element of the object
*/
static inline void mjson_set_root(mjson_doc* doc, mjson_val* val) {
	doc->root = val;
}

/*
Get the value as a string
*/
static inline char* mjson_get_string(mjson_val* val) {
	return val->value.String.value;
}

/*
Create a new string value
*/
mjson_val* mjson_string(mjson_doc* doc, const char* string, uint32_t length);

/*
Get value as an integer
*/
static inline int64_t mjson_get_int(mjson_val* val) {
	return val->value.Integer;
}

/*
Create a new integer value
*/
mjson_val* mjson_int(mjson_doc* doc, int64_t val);

/*
Get value as a double
*/
static inline double mjson_get_double(mjson_val* val) {
	return val->value.Double;
}

/*
Create a new double value
*/
mjson_val* mjson_double(mjson_doc* doc, double val);

/*
Read a boolean value
0 is false
1 is true
*/
static inline uint8_t mjson_get_boolean(mjson_val* val) {
	return val->value.Boolean;
}

/*
Create a new boolean value
0 is false
anything else is true
*/
mjson_val* mjson_boolean(mjson_doc* doc, uint8_t val);

/*
Create a new array
Values can be appended to this array with mjson_arr_append
*/
mjson_val* mjson_arr(mjson_doc* doc);

/*
Get element 'idx' of array
*/
static inline mjson_val* mjson_arr_get(mjson_val* val, uint32_t idx) {
	return val->value.Array.values[idx];
}

/*
Append an element to array
*/
void mjson_arr_append(mjson_val* arr, mjson_val* val);

/*
Create an empty object
*/
mjson_val* mjson_obj(mjson_doc* doc);

/*
Get property 'idx' of object
*/
static inline mjson_property mjson_obj_get(mjson_val* val, uint32_t idx) {
	return val->value.Object.properties[idx];
}

/*
Add a new property to the object
*/
void mjson_obj_add(mjson_val* obj, mjson_val* label, mjson_val* value);

/*
Get label of property
*/
static inline mjson_val* mjson_property_get_label(mjson_property property) {
	return property.label;
}

/*
Get value of property
*/
static inline mjson_val* mjson_property_get_value(mjson_property property) {
	return property.value;
}

/*
Create a new null value
*/
mjson_val* mjson_null(mjson_doc* doc);

/*
Free the document
*/
void mjson_free(mjson_doc* doc);