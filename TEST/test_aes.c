/*
 * test_aes.c
 *
 *  Created on: Apr 25, 2015
 *      Author: nasm
 */
#include "../common.h"

void ASSERT(int condition,P_STR message)
{
	condition ? puts(message) : puts("");
}

void test_aes()
{
	USTR key[] = "I_Am_An_AES_KEY";
	USTR plaintext[] = "I_am_a_secret";
	P_USTR ciphertext;

	aes_crypt(key, plaintext, ciphertext);

	printf("CIPHERTEXT: %s\n",ciphertext);
	printf("PLAINTEXT: %s\n",plaintext);

	aes_decrypt(&key, plaintext, ciphertext);

	printf("CIPHERTEXT: %s\n",ciphertext);
	printf("PLAINTEXT: %s\n",plaintext);

	//ASSERT(strcmp(&plaintext,&plaintext)==0,"failed aes...");
}
