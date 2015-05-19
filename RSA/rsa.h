#ifndef H_RSA
#define H_RSA

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <sys/stat.h>
    #include <netinet/in.h>
    #include <openssl/rsa.h>
    #include <openssl/engine.h>
    #include <openssl/pem.h>
    #include <openssl/bio.h>
    #include <openssl/evp.h>

    unsigned char* encrypt (char *message,  RSA *cli_pub_key, long *buffer_size);

    unsigned char* decrypt (unsigned char *encrypted, RSA *priv_key, long enc_message_length, long original_length);

    unsigned char* public_key_to_buffer(RSA* pRSA);

    unsigned char* private_key_to_buffer(RSA* pRSA);
#endif
