#ifndef H_AES
#define H_AES

	STATUT_CODE aes_crypt(P_USTR key,P_USTR plaintext, P_USTR ciphertext);

	STATUT_CODE aes_decrypt(P_USTR key,P_USTR plaintext, P_USTR ciphertext);

#endif
