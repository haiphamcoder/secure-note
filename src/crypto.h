#ifndef CRYPTO_H
#define CRYPTO_H

void encrypt_note(const char *plaintext, const char *password, char *ciphertext);
void decrypt_note(const char *ciphertext, const char *password, char *plaintext);

#endif
