#ifndef _BASE64
#define _BASE64

    #include <string.h>

    #include <openssl/sha.h>
    #include <openssl/hmac.h>
    #include <openssl/evp.h>
    #include <openssl/bio.h>
    #include <openssl/buffer.h>

    char *base64(const unsigned char *input, int length);

#endif
