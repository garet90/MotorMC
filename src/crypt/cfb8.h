#include <openssl/evp.h>
#include "../main.h"

int cfb8_init(byte_t* key, EVP_CIPHER_CTX** e, EVP_CIPHER_CTX** d);
int cfb8_encrypt(EVP_CIPHER_CTX* e, byte_t* restrict data, size_t len, byte_t* restrict out);
int cfb8_decrypt(EVP_CIPHER_CTX* d, byte_t* restrict data, size_t len, byte_t* restrict out);
int cfb8_done(EVP_CIPHER_CTX* e, EVP_CIPHER_CTX* d);