#ifndef H_BENCODEW
#define H_BENCODEW
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    int bencode_write_string(char* bencode_str, int length, char* value);

    int bencode_write_integer(char* bencode_str, int value);

    int itoa(int number, char* out, int base);

#endif
