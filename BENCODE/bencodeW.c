#include "bencodeW.h"

int bencode_write_integer(char* bencode_str, int value)
{
    bencode_str[0] = 'i';
    bencode_str[1] = value;
    bencode_str[2] = 'e';

    return 3;
}

int bencode_write_string(char* bencode_str, int length, char* value)
{
    char length_str[10] = {'0'};
    //int n = integer_to_ascii(length,length_str);
    itoa(length, length_str, 10);

    strncpy(&bencode_str[0],length_str,strlen(length_str));
    bencode_str[strlen(length_str)] = ':';
    strncpy(&bencode_str[1+strlen(length_str)],value,length);

    return 1+length+strlen(length_str);
}


#define ALPHANUMS "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz"

/** converts an integer to a string, using a base of 10 by default.
*
* if you NULL out the output buffer it will return the expected
* output string length anyway.
*/
int itoa(int number, char* out, int base) {
    int t, count;
    char *p, *q;
    char c;

    p = q = out;
    if (base < 2 || base > 36) base = 10;

    do {
        t = number;
        number /= base;
        if (out) *p = ALPHANUMS[t+35 - number*base];
        p++;
    } while (number);

    if (t < 0) {
        if (out) *p = '-';
        p++;
    }
    count = p-out;
    if (out) {
        *p-- = '\0';
        while(q < p) {
            c = *p;
            *p-- = *q;
            *q++ = c;
        }
    }
    return count;
}
