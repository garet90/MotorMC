#include "random.h"

#ifdef __WINDOWS__
#include <windows.h>
#include <Wincrypt.h>
#else
#include <stdio.h>
#endif

extern void cry_randomBytes(byte_t* bytes, size_t count) {

#ifdef __WINDOWS__
	HCRYPTPROV hCryptProv;
	if (!CryptAcquireContext(
			&hCryptProv,
			NULL,
			NULL,
			PROV_RSA_FULL,
			CRYPT_VERIFYCONTEXT)) {
		if (GetLastError() == (uint32_t) NTE_BAD_KEYSET) {
			if(!CryptAcquireContext(
                &hCryptProv,
                NULL,
                NULL,
                PROV_RSA_FULL,
                CRYPT_NEWKEYSET)) {
				log_error("Error in CryptAcquireContext");
				return;
			}
		} else {
			log_error("Error in CryptAcquireContext");
			return;
		}
	}
	CryptGenRandom(
			hCryptProv,
			count,
			bytes);
	if (!CryptReleaseContext(
			hCryptProv,
			0)) {
		log_error("Could not release hCryptProv");
	}
#else
	FILE *f;
	f = fopen("/dev/urandom", "r");
	if (feof(f)) {
		log_error("Could not open /dev/urandom!");
		return;
	}
	if (fread(bytes, sizeof(byte_t), count, f) < sizeof(byte_t) * count) {
		log_error("Failed to read secure random bytes!");
	}
	fclose(f);
#endif

}
