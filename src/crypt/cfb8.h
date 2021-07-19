#pragma once
#include <tomcrypt.h>
#include "../main.h"

/** A block cipher CFB structure with a bit width of 8 */
typedef struct {

	/** The index of the cipher chosen */
	int
		cipher,
	/** The block size of the given cipher */
		blocklen;
	/** The current IV */
	unsigned char
		IV[MAXBLOCKSIZE];
	/** The scheduled key */
	symmetric_key key;

} symmetric_CFB8;

extern int cfb8_start(int cipher, const byte_t* IV, const byte_t* key, int keylen, int num_rounds, symmetric_CFB8* cfb8);

extern int cfb8_setiv(const byte_t* IV, unsigned long len, symmetric_CFB8* cfb8);
extern int cfb8_getiv(byte_t* IV, unsigned long* len, const symmetric_CFB8* cfb8);

extern int cfb8_encrypt(const byte_t* pt, byte_t* ct, unsigned long len, symmetric_CFB8* cfb8);
extern int cfb8_decrypt(const byte_t* ct, byte_t* pt, unsigned long len, symmetric_CFB8* cfb8);

extern int cfb8_done(symmetric_CFB8* cfb8);
