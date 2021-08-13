#pragma once
#include "../main.h"

typedef struct {

    size_t cursor;

    byte_t bytes[];

} utl_bit_stream_t;

static inline int64_t utl_read_bit_stream(utl_bit_stream_t* stream, size_t bits) {

    union {

        int64_t num;
        byte_t byte[8];

    } result;

    size_t byte = stream->cursor >> 3;
    byte_t bit = stream->cursor & 0x7;

}

static inline void utl_write_bit_stream(utl_bit_stream_t* stream, size_t bits) {

}