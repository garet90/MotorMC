#pragma once
#include "../main.h"
#include <tfm.h>

//#define CRY_DEBUG

typedef struct {

	fp_int d;
	fp_int n;

	struct {
		size_t length : 8;
		byte_t bytes[256];
	} ASN1;

} cry_rsa_keypair_t;

extern void cry_rsa_gen_key_pair(cry_rsa_keypair_t*);

extern void cry_gen_prime(fp_int*, size_t);

extern void cry_rsa_decrypt(byte_t*, const byte_t*, size_t, cry_rsa_keypair_t*);
