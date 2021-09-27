#include "rsa.h"
#include "../util/util.h"
#include "../io/logger/logger.h"
#include "random.h"

void cry_rsa_gen_key_pair(cry_rsa_keypair_t* keypair) {

	// e for generating d
	const byte_t e_val[] = {
		0x01,
		0x00,
		0x01
	};
	fp_int e;
	fp_read_unsigned_bin(&e, e_val, sizeof(e_val));

	// generate two 64 byte primes: p and q
	fp_int p, q;
	cry_gen_prime(&p, 64);
	cry_gen_prime(&q, 64);

#ifdef CRY_DEBUG
	char str[512];
	fp_toradix(&p, str, 16);
	log_info("p: 0x%s", str);
	
	fp_toradix(&q, str, 16);
	log_info("q: 0x%s", str);
#endif

	fp_init(&keypair->d);
	fp_init(&keypair->n);

	fp_mul(&p, &q, &keypair->n);

#ifdef CRY_DEBUG
	fp_toradix(&keypair->n, str, 16);
	log_info("n: 0x%s", str);
#endif

	const byte_t one_val[] = { 0x01 };
	fp_int one;
	fp_read_unsigned_bin(&one, one_val, sizeof(one_val));

	fp_sub(&p, &one, &p);
	fp_sub(&q, &one, &q);
	
	fp_lcm(&p, &q, &p);

	fp_invmod(&e, &p, &keypair->d);

#ifdef CRY_DEBUG
	fp_toradix(&keypair->d, str, 16);
	log_info("d: 0x%s", str);
#endif

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

	fp_to_signed_bin(&keypair->n, keypair->ASN1.bytes + sizeof(prefix));

	memcpy(keypair->ASN1.bytes + sizeof(prefix) + 129, suffix, sizeof(suffix));

	keypair->ASN1.length = sizeof(prefix) + 129 + sizeof(suffix);

}

void cry_gen_prime(fp_int* prime, size_t size) {
	
	const byte_t two_val[] = { 0x02 };
	fp_int two;
	fp_read_unsigned_bin(&two, two_val, sizeof(two_val));

	byte_t bytes[size];
	cry_random_bytes(bytes, size);
	bytes[size - 1] |= 0x1; // make sure it's even
	bytes[0] |= 0xC0; // make sure top two bits are 1 (so the product is the correct bit length)

	fp_read_unsigned_bin(prime, bytes, size);

	while (fp_isprime(prime) != FP_YES) {

		fp_add(prime, &two, prime);

	}

}
void cry_rsa_decrypt(byte_t* out, const byte_t* message, size_t size, cry_rsa_keypair_t* keypair) {

	fp_int c;
	fp_read_unsigned_bin(&c, message, size);

	fp_exptmod(&c, &keypair->d, &keypair->n, &c);

	uint32_t m_size = fp_unsigned_bin_size(&c);
	uint8_t m_arr[m_size];
	fp_to_unsigned_bin(&c, m_arr);

	utl_reverse_bytes(m_arr, out, m_size);

}