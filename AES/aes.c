#include "../common.h"
#include "../ERROR/error.h"

#include <openssl/aes.h>

#include "aes.h"

STATUT_CODE aes_decrypt(P_USTR key,P_USTR plaintext, P_USTR ciphertext)
{
    return SUCCESS;
}

STATUT_CODE aes_crypt(P_USTR key,P_USTR plaintext, P_USTR ciphertext)
{
    AES_KEY aes;

    u_int plaintext_len = strlen((char*)plaintext)+1;
    u_int ciphertext_len = (plaintext_len % AES_BLOCK_SIZE == 0) ? plaintext_len : (plaintext_len / AES_BLOCK_SIZE +1) * AES_BLOCK_SIZE;

    ciphertext = malloc(sizeof(STR)*ciphertext_len);

    if( AES_set_encrypt_key(key,128,&aes) != SUCCESS)
    	return raise_error(FAILURE,"AES_set_encrypt_key()");

    unsigned char iv[AES_BLOCK_SIZE];
    memset(iv,0,AES_BLOCK_SIZE);

    AES_cbc_encrypt(plaintext, ciphertext, ciphertext_len, &aes, iv, AES_ENCRYPT);

    return SUCCESS;
}
