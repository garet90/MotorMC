#pragma once
#include "../main.h"

// create a bitset n bits long
#define utl_bitset(n, l) byte_t l [((n) >> 3) + 1]

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