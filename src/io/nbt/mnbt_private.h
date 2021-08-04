#pragma once
#include "mnbt.h"

size_t _mnbt_read_tag(mnbt_doc* document, mnbt_tag** tag, const uint8_t* bytes);
size_t _mnbt_read_val(mnbt_doc* document, mnbt_type type, mnbt_val* value, const uint8_t* bytes);

void _mnbt_add(mnbt_doc* document, mnbt_tag* tag);

size_t _mnbt_write_tag(mnbt_tag* tag, uint8_t* bytes);
size_t _mnbt_write_val(mnbt_type type, mnbt_val val, uint8_t* bytes);

static inline int16_t _mnbt_reverse_short(int16_t val) {
    const uint8_t e[2] = { 0xAA, 0xBB };
    if (*((uint16_t*) e) == 0xAABB) {
        return val;
    }

    union {
        int16_t v;
        int8_t b[2];
    } i = {
        .v = val
    };

    union {
        int16_t v;
        int8_t b[2];
    } o;

    o.b[0] = i.b[1];
    o.b[1] = i.b[0];

    return o.v;
}

static inline int32_t _mnbt_reverse_int(int32_t val) {
    const uint8_t e[2] = { 0xAA, 0xBB };
    if (*((uint16_t*) e) == 0xAABB) {
        return val;
    }

    union {
        int32_t v;
        int8_t b[4];
    } i = {
        .v = val
    };

    union {
        int32_t v;
        int8_t b[4];
    } o;

    o.b[0] = i.b[3];
    o.b[1] = i.b[2];
    o.b[2] = i.b[1];
    o.b[3] = i.b[0];

    return o.v;
}

static inline int64_t _mnbt_reverse_long(int64_t val) {
    const uint8_t e[2] = { 0xAA, 0xBB };
    if (*((uint16_t*) e) == 0xAABB) {
        return val;
    }

    union {
        int64_t v;
        int8_t b[8];
    } i = {
        .v = val
    };

    union {
        int64_t v;
        int8_t b[8];
    } o;

    o.b[0] = i.b[7];
    o.b[1] = i.b[6];
    o.b[2] = i.b[5];
    o.b[3] = i.b[4];
    o.b[4] = i.b[3];
    o.b[5] = i.b[2];
    o.b[6] = i.b[1];
    o.b[7] = i.b[0];

    return o.v;
}

static inline float _mnbt_reverse_float(float val) {
    const uint8_t e[2] = { 0xAA, 0xBB };
    if (*((uint16_t*) e) == 0xAABB) {
        return val;
    }

    union {
        float v;
        int8_t b[4];
    } i = {
        .v = val
    };

    union {
        float v;
        int8_t b[4];
    } o;

    o.b[0] = i.b[3];
    o.b[1] = i.b[2];
    o.b[2] = i.b[1];
    o.b[3] = i.b[0];

    return o.v;
}

static inline double _mnbt_reverse_double(double val) {
    const uint8_t e[2] = { 0xAA, 0xBB };
    if (*((uint16_t*) e) == 0xAABB) {
        return val;
    }

    union {
        double v;
        int8_t b[8];
    } i = {
        .v = val
    };

    union {
        double v;
        int8_t b[8];
    } o;

    o.b[0] = i.b[7];
    o.b[1] = i.b[6];
    o.b[2] = i.b[5];
    o.b[3] = i.b[4];
    o.b[4] = i.b[3];
    o.b[5] = i.b[2];
    o.b[6] = i.b[1];
    o.b[7] = i.b[0];

    return o.v;
}