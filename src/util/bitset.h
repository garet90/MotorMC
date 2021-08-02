#pragma once
#include "../main.h"

// create a bitset 'length' bits long
#define utl_bitset(length, name) byte_t name [((length) >> 3) + 1]
#define utl_arraybit(x) (1 << (x & 7))

static inline void utl_setBit(byte_t set[], size_t bit) {

    size_t byte = bit >> 3;
    bit &= 0x07;
    
    set[byte] |= (1 << bit);

}

static inline void utl_resetBit(byte_t set[], size_t bit) {

    size_t byte = bit >> 3;
    bit &= 0x07;

    set[byte] &= ~(1 << bit);

}

static inline void utl_flibBit(byte_t set[], size_t bit) {

    size_t byte = bit >> 3;
    bit &= 0x07;

    if (set[byte] & (1 << bit)) {
        set[byte] &= ~(1 << bit);
    } else {
        set[byte] |= (1 << bit);
    }

}

static inline bool_t utl_testBit(const byte_t set[], size_t bit) {
    
    size_t byte = bit >> 3;
    bit &= 0x07;

    return (set[byte] & (1 << bit)) ? true : false;

}