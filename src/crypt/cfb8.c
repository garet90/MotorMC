#include "cfb8.h"

int cfb8_init(byte_t* key, EVP_CIPHER_CTX** e, EVP_CIPHER_CTX** d) {
	
	if ((*e = EVP_CIPHER_CTX_new()) == NULL) {
		return 0;
	}

	if (EVP_EncryptInit_ex(*e, EVP_aes_128_cfb8(), NULL, key, key) != 1) {
		return 0;
	}

	if ((*d = EVP_CIPHER_CTX_new()) == NULL) {
		return 0;
	}

	if (EVP_DecryptInit_ex(*d, EVP_aes_128_cfb8(), NULL, key, key) != 1) {
		return 0;
	}

	return 1;

}

int cfb8_encrypt(EVP_CIPHER_CTX* e, byte_t* restrict data, size_t len, byte_t* restrict out) {

	int out_len = len;
	return EVP_EncryptUpdate(e, out, &out_len, data, len);

}

int cfb8_decrypt(EVP_CIPHER_CTX* d, byte_t* restrict data, size_t len, byte_t* restrict out) {

	int out_len = len;
	return EVP_DecryptUpdate(d, out, &out_len, data, len);

}

int cfb8_done(EVP_CIPHER_CTX* e, EVP_CIPHER_CTX* d) {

	EVP_CIPHER_CTX_cleanup(e);
	EVP_CIPHER_CTX_cleanup(d);

	return 0;

}