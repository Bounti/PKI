#ifndef _SHA
#define _SHA

    #include "openssl/sha.h"

    void sha256(char *string, char outputBuffer[65]);

    int sha256_file(char *path, char outputBuffer[65]);
    
#endif
