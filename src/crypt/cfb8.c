#include "cfb8.h"

int cfb8_start(int cipher, const byte_t* IV, const byte_t* key, int keylen, int num_rounds, symmetric_CFB8* cfb8) {

	int x, err;

	LTC_ARGCHK(IV   != NULL);
	LTC_ARGCHK(key  != NULL);
	LTC_ARGCHK(cfb8 != NULL);

	if ((err = cipher_is_valid(cipher)) != CRYPT_OK) {
		return err;
	}

	/* copy data */
	cfb8->cipher = cipher;
	cfb8->blocklen = cipher_descriptor[cipher].block_length;
	for (x = 0; x < cfb8->blocklen; x++) {
		cfb8->IV[x] = IV[x];
	}

    /* init the cipher */
	if ((err = cipher_descriptor[cipher].setup(key, keylen, num_rounds, &cfb8->key)) != CRYPT_OK) {
    	return err;
    }

    //return cipher_descriptor[cfb8->cipher].ecb_encrypt(cfb8->IV, cfb8->IV, &cfb8->key);

	return CRYPT_OK;

}

int cfb8_setiv(const byte_t* IV, unsigned long len, symmetric_CFB8* cfb8) {

	int err;

	LTC_ARGCHK(IV   != NULL);
	LTC_ARGCHK(cfb8 != NULL);

	if ((err = cipher_is_valid(cfb8->cipher)) != CRYPT_OK) {
		return err;
	}

	if (len != (unsigned long)cfb8->blocklen) {
		return CRYPT_INVALID_ARG;
	}

	XMEMCPY(cfb8->IV, IV, cfb8->blocklen);

	return CRYPT_OK;

}

int cfb8_getiv(byte_t* IV, unsigned long* len, const symmetric_CFB8* cfb8) {

	LTC_ARGCHK(IV   != NULL);
	LTC_ARGCHK(len  != NULL);
	LTC_ARGCHK(cfb8 != NULL);

	if ((unsigned long)cfb8->blocklen > *len) {
		*len = cfb8->blocklen;
		return CRYPT_BUFFER_OVERFLOW;
	}

	XMEMCPY(IV, cfb8->IV, cfb8->blocklen);
	*len = cfb8->blocklen;

	return CRYPT_OK;

}

/**
 * I0 = IV
 * Ii = ((Ii-1 << s) + Ci) mod 2^b
 * Ci = MSBs(Ek(Ii-1)) xor Pi
 */
int cfb8_encrypt(const byte_t* pt, byte_t* ct, unsigned long len, symmetric_CFB8* cfb8) {

	int err;
	byte_t cipher_out[MAXBLOCKSIZE];

	LTC_ARGCHK(pt   != NULL);
	LTC_ARGCHK(ct   != NULL);
	LTC_ARGCHK(cfb8 != NULL);

	if ((err = cipher_is_valid(cfb8->cipher)) != CRYPT_OK) {
		return err;
	}

	/* is blocklen valid? */
	if (cfb8->blocklen < 0 || cfb8->blocklen > (int)sizeof(cfb8->IV)) {
		return CRYPT_INVALID_ARG;
	}

	while (len-- > 0) {

		if ((err = cipher_descriptor[cfb8->cipher].ecb_encrypt(cfb8->IV, cipher_out, &cfb8->key)) != CRYPT_OK) {
			return err;
		}

		memmove(cfb8->IV, cfb8->IV + 1, cfb8->blocklen - 1);
		cfb8->IV[cfb8->blocklen - 1] = *ct = cipher_out[0] ^ *pt;

		pt++;
		ct++;

	}

	return CRYPT_OK;

}

int cfb8_decrypt(const byte_t* ct, byte_t* pt, unsigned long len, symmetric_CFB8* cfb8) {

	int err;
	byte_t cipher_out[MAXBLOCKSIZE];

	LTC_ARGCHK(pt   != NULL);
	LTC_ARGCHK(ct   != NULL);
	LTC_ARGCHK(cfb8 != NULL);

	if ((err = cipher_is_valid(cfb8->cipher)) != CRYPT_OK) {
		return err;
	}

	/* is blocklen valid? */
	if (cfb8->blocklen < 0 || cfb8->blocklen > (int)sizeof(cfb8->IV)) {
		return CRYPT_INVALID_ARG;
	}

	while (len-- > 0) {

		if ((err = cipher_descriptor[cfb8->cipher].ecb_encrypt(cfb8->IV, cipher_out, &cfb8->key)) != CRYPT_OK) {
			return err;
		}

		memmove(cfb8->IV, cfb8->IV + 1, cfb8->blocklen - 1);
		cfb8->IV[cfb8->blocklen - 1] = *ct;

		*pt = cipher_out[0] ^ *ct;

		pt++;
		ct++;

	}

	return CRYPT_OK;

}

int cfb8_done(symmetric_CFB8* cfb8) {

	int err;
	LTC_ARGCHK(cfb8 != NULL);

	if ((err = cipher_is_valid(cfb8->cipher)) != CRYPT_OK) {
	   return err;
	}

	cipher_descriptor[cfb8->cipher].done(&cfb8->key);

	return CRYPT_OK;

}
