#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>
#include <string.h>
#include "leitura.h"
#include "shar.h"
//função sha256 que usa a biblioteca openssl/sha.h 
void sha256(senha *pass, senhascrip *crip, int y) {
//iterando entre o número de senhas armazenados em pass.c e convertendo cada uma para sua string em SHA256,
   for (int i = 0; i < y; i++) {
        const char *password = pass[i].c;
        unsigned char hashResult[SHA256_DIGEST_LENGTH];

        SHA256((const unsigned char *)password, strlen(password), hashResult);
//armazenando cada uma das senhas no registro crip.senha
        for (int j = 0; j < SHA256_DIGEST_LENGTH; j++) {
            sprintf(&crip[i].senha[j * 2], "%02x", hashResult[j]);
        }

        crip[i].senha[2 * SHA256_DIGEST_LENGTH] = '\0';
    }
}