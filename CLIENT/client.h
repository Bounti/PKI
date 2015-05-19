#ifndef _CLIENT
#define _CLIENT

    #include <openssl/rsa.h>
	#include "../common.h"
	#include "../ERROR/error.h"

	#define MAX_CLIENT_NAME_LEN 25
    #define MAX_CLIENT_PKEY_LEN 2048

    typedef struct
    {
        USTR name[25];
        USTR public_key[2048];
        USTR sha_256[2048];
        USTR sha_1[2048];
        RSA *pRSA;
        int socket;
    }CLIENT,*PCLIENT;

    void print_client(CLIENT* client);

    void to_string(CLIENT* client,char* buffer);

#endif
