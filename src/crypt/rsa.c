#include "rsa.h"
#include "../util/util.h"
#include "../io/logger/logger.h"
#include "random.h"

void cry_rsa_gen_key_pair(cry_rsa_keypair_t* keypair) {

	// e for generating d
	mpz_t e;
	mpz_init_set_ui(e, 65537);

	mpz_t p, q;
	mpz_init2(p, 512);
	mpz_init2(q, 512);

	cry_gen_prime(p, 64);
	cry_gen_prime(q, 64);

#ifdef CRY_DEBUG
	char str[514];
	mpz_get_str(str, 16, p);
	log_info("p: 0x%s", str);
	
	mpz_get_str(str, 16, q);
	log_info("q: 0x%s", str);
#endif

	mpz_init2(keypair->n, 1024);
	mpz_mul(keypair->n, p, q);

	mpz_init2(keypair->d, 1024);

#ifdef CRY_DEBUG
	mpz_get_str(str, 16, keypair->n);
	log_info("n: 0x%s", str);
#endif

	mpz_sub_ui(p, p, 1);
	mpz_sub_ui(q, q, 1);

	mpz_lcm(p, q, p);

	mpz_invert(keypair->d, e, p);

#ifdef CRY_DEBUG
	mpz_get_str(str, 16, keypair->d);
	log_info("d: 0x%s", str);

	// e * d MOD lambda must be 1
	mpz_mul(q, e, keypair->d);
	mpz_mod(q, q, p);
	if (mpz_cmp_ui(q, 1) == 0) {
		log_info("RSA keys are valid");
	} else {
		log_error("RSA keys are invalid!!");
	}
#endif

	mpz_clears(e, p, q, NULL);

	//ASN1

	const byte_t prefix[] = {
		0x30, 0x81, 0x9F, 0x30, 0x0D,
		0x06, 0x09, 0x2A, 0x86, 0x48,
		0x86, 0xF7, 0x0D, 0x01, 0x01,
		0x01, 0x05, 0x00, 0x03, 0x81,
		0x8D, 0x00, 0x30, 0x81, 0x89,
		0x02, 0x81, 0x81
	};

	const byte_t suffix[] = {
		0x02, 0x03, 0x01, 0x00, 0x01
	};

	memcpy(keypair->ASN1.bytes, prefix, sizeof(prefix));

	mpz_export(keypair->ASN1.bytes + sizeof(prefix) + 1, NULL, 1, sizeof(byte_t), 0, 0, keypair->n);

	memcpy(keypair->ASN1.bytes + sizeof(prefix) + 129, suffix, sizeof(suffix));

	keypair->ASN1.length = sizeof(prefix) + 129 + sizeof(suffix);

}

void cry_gen_prime(mpz_t prime, size_t size) {

	byte_t bytes[size];
	cry_random_bytes(bytes, size);
	bytes[size - 1] |= 0x1; // make sure it's odd
	bytes[0] |= 0xC0; // make sure top two bits are 1 (so the product is the correct bit length)

	mpz_import(prime, size, 1, sizeof(byte_t), 0, 0, bytes);

	mpz_nextprime(prime, prime);

}

size_t cry_rsa_decrypt(byte_t* out, const byte_t* message, size_t size, cry_rsa_keypair_t* keypair) {

	mpz_t c;
	mpz_init2(c, size << 3);
	mpz_import(c, size, 1, sizeof(byte_t), 0, 0, message);

	mpz_powm_sec(c, c, keypair->d, keypair->n);

	size_t out_size = 0;
	mpz_export(out, &out_size, 1, sizeof(byte_t), 0, 0, c);

	utl_reverse_bytes(out, out, out_size);

	mpz_clear(c);

	return out_size;

}