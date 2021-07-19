#pragma once
#include "../main.h"

typedef enum io_endianness {
    IO_LITTLE_ENDIAN = 0,
    IO_BIG_ENDIAN = 1
} io_endianness_t;

static inline io_endianness_t io_getEndianness() {
    
    const uint8_t array[] = { 0xAA, 0xBB };

    if (*((uint16_t*) array) == 0xAABB) {
        return IO_BIG_ENDIAN;
    } else {
        return IO_LITTLE_ENDIAN;
    }

}

static inline int8_t io_readInt8(const byte_t* buffer) {
    return *buffer;
}

static inline int16_t io_readInt16(const byte_t* buffer, io_endianness_t endianness) {

    if (io_getEndianness() == endianness) {

        return *((int16_t*) buffer);

    } else {

        union {
            int16_t v;
            byte_t b[2];
        } u;

        u.b[1] = buffer[0];
        u.b[0] = buffer[1];

        return u.v;

    }

}

static inline int32_t io_readInt32(const byte_t* buffer, io_endianness_t endianness) {

    if (io_getEndianness() == endianness) {

        return *((int32_t*) buffer);

    } else {

        union {
            int32_t v;
            byte_t b[4];
        } u;

        u.b[3] = buffer[0];
        u.b[2] = buffer[1];
        u.b[1] = buffer[2];
        u.b[0] = buffer[3];

        return u.v;

    }

}

static inline int64_t io_readInt64(const byte_t* buffer, io_endianness_t endianness) {

    if (io_getEndianness() == endianness) {
        
        return *((int64_t*) buffer);

    } else {

        union {
            int64_t v;
            byte_t b[8];
        } u;

        u.b[7] = buffer[0];
        u.b[6] = buffer[1];
        u.b[5] = buffer[2];
        u.b[4] = buffer[3];
        u.b[3] = buffer[4];
        u.b[2] = buffer[5];
        u.b[1] = buffer[6];
        u.b[0] = buffer[7];

        return u.v;

    }

}

static inline float32_t io_readFloat32(const byte_t* buffer, io_endianness_t endianness) {

    if (io_getEndianness() == endianness) {

        return *((float32_t*) buffer);

    } else {

        union {
            float32_t v;
            byte_t b[4];
        } u;

        u.b[3] = buffer[0];
        u.b[2] = buffer[1];
        u.b[1] = buffer[2];
        u.b[0] = buffer[3];

        return u.v;

    }

}

static inline float64_t io_readFloat64(const byte_t* buffer, io_endianness_t endianness) {

    if (io_getEndianness() == endianness) {
        
        return *((float64_t*) buffer);

    } else {

        union {
            float64_t v;
            byte_t b[8];
        } u;

        u.b[7] = buffer[0];
        u.b[6] = buffer[1];
        u.b[5] = buffer[2];
        u.b[4] = buffer[3];
        u.b[3] = buffer[4];
        u.b[2] = buffer[5];
        u.b[1] = buffer[6];
        u.b[0] = buffer[7];

        return u.v;

    }

}

static inline int32_t io_readVarInt(const byte_t* buffer, size_t* length) {
    
    int32_t result = 0;
    *length = 0;
    int8_t read;

    if (io_getEndianness() == IO_LITTLE_ENDIAN) {

        do {
            read = io_readInt8(buffer + *length);
            result |= ((read & 0x7F) << (7 * *length));

            *length += 1;
        } while ((read & 0x80) != 0);

    } else {
        // TODO big endian
    }

    return result;

}

static inline int64_t io_readVarLong(const byte_t* buffer, size_t* length) {
    
    int64_t result = 0;
    *length = 0;
    int8_t read;

    if (io_getEndianness() == IO_LITTLE_ENDIAN) {

        do {
            read = io_readInt8(buffer + *length);
            result |= ((read & 0x7F) << (7 * *length));

            *length += 1;
        } while ((read & 0x80) != 0);

    } else {
        // TODO big endian
    }

    return result;

}

static inline void io_writeInt8(byte_t* buffer, int8_t value) {

    buffer[0] = value;

}

static inline void io_writeInt16(byte_t* buffer, int16_t value, io_endianness_t endianness) {

    if (io_getEndianness() == endianness) {

        *((int16_t*) buffer) = value;
        
    } else {

        union {
            int16_t v;
            byte_t b[2];
        } u = {
            .v = value
        };
        
        buffer[0] = u.b[1];
        buffer[1] = u.b[0];

    }

}

static inline void io_writeInt32(byte_t* buffer, int32_t value, io_endianness_t endianness) {

    if (io_getEndianness() == endianness) {

        *((int32_t*) buffer) = value;

    } else {

        union {
            int32_t v;
            byte_t b[4];
        } u = {
            .v = value
        };

        buffer[0] = u.b[3];
        buffer[1] = u.b[2];
        buffer[2] = u.b[1];
        buffer[3] = u.b[0];

    }

}

static inline void io_writeInt64(byte_t* buffer, int64_t value, io_endianness_t endianness) {

    if (io_getEndianness() == endianness) {

        *((int64_t*) buffer) = value;

    } else {

        union {
            int64_t v;
            byte_t b[8];
        } u = {
            .v = value
        };

        buffer[0] = u.b[7];
        buffer[1] = u.b[6];
        buffer[2] = u.b[5];
        buffer[3] = u.b[4];
        buffer[4] = u.b[3];
        buffer[5] = u.b[2];
        buffer[6] = u.b[1];
        buffer[7] = u.b[0];

    }

}

static inline void io_writeFloat32(byte_t* buffer, float32_t value, io_endianness_t endianness) {

    if (io_getEndianness() == endianness) {

        *((float32_t*) buffer) = value;

    } else {

        union {
            float32_t v;
            byte_t b[4];
        } u = {
            .v = value
        };

        buffer[0] = u.b[3];
        buffer[1] = u.b[2];
        buffer[2] = u.b[1];
        buffer[3] = u.b[0];

    }

}

static inline void io_writeFloat64(byte_t* buffer, float64_t value, io_endianness_t endianness) {

    if (io_getEndianness() == endianness) {

        *((float64_t*) buffer) = value;

    } else {

        union {
            float64_t v;
            byte_t b[8];
        } u = {
            .v = value
        };

        buffer[0] = u.b[7];
        buffer[1] = u.b[6];
        buffer[2] = u.b[5];
        buffer[3] = u.b[4];
        buffer[4] = u.b[3];
        buffer[5] = u.b[2];
        buffer[6] = u.b[1];
        buffer[7] = u.b[0];

    }

}

static inline size_t io_varIntLength(uint32_t value) {

    size_t len = 0;

    do {

        len++;
        value >>= 7;

    } while (value != 0);

    return len;

}

static inline size_t io_writeVarInt(byte_t* buffer, int32_t value) {

    size_t i = 0;
    do {
        int8_t temp = (int8_t) (value & 0x7F);

        value >>= 7;
        if (value != 0) {
            temp |= 0x80;
        }
        io_writeInt8(buffer + i++, temp);
    } while (value != 0);

    return i;

}

static inline size_t io_writeVarLong(byte_t* buffer, int64_t value) {

    size_t i = 0;
    do {
        int8_t temp = (int8_t) (value & 0x7F);

        value >>= 7;
        if (value != 0) {
            temp |= 0x80;
        }
        io_writeInt8(buffer + i++, temp);
    } while (value != 0);

    return i;

}

static inline uint16_t io_htons(uint16_t n) {

	if (io_getEndianness() == IO_LITTLE_ENDIAN) {

        union {
            int16_t v;
            byte_t b[2];
        } i = {
            .v = n
        };

        union {
            int16_t v;
            byte_t b[2];
        } o;

		o.b[0] = i.b[1];
		o.b[1] = i.b[0];

		return o.v;

	}

	return n;

}