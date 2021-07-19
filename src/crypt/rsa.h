#pragma once
#include "../main.h"
#include <tfm.h>

//#define CRY_DEBUG

typedef struct {

	fp_int d;
	fp_int n;

	struct {
		size_t length;
		byte_t bytes[256];
	} ASN1;

} cry_RSAkeypair_t;

extern void cry_genRSAKeyPair(cry_RSAkeypair_t*);

extern void cry_genPrime(fp_int*, size_t);

extern void cry_decryptRSA(byte_t*, const byte_t*, size_t, cry_RSAkeypair_t*);
