#pragma once
#include "../main.h"
#include <gmp.h>

//#define CRY_DEBUG

typedef struct {

	mpz_t d;
	mpz_t n;

	struct {
		size_t length : 8;
		byte_t bytes[256];
	} ASN1;

} cry_rsa_keypair_t;

extern void cry_rsa_gen_key_pair(cry_rsa_keypair_t*);

extern void cry_gen_prime(mpz_t, size_t);

extern size_t cry_rsa_decrypt(byte_t*, const byte_t*, size_t, cry_rsa_keypair_t*);
