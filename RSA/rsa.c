#include "../common.h"
#include "../ERROR/error.h"

#include "rsa.h"

P_USTR rsa_crypt (char *plaintext,  RSA *cli_pub_key, long *buffer_size)
{
	unsigned char *ciphertext =  (unsigned char *)malloc(RSA_size(cli_pub_key));
	*buffer_size = RSA_public_encrypt(strlen(plaintext), (unsigned char *) plaintext, ciphertext, cli_pub_key, RSA_PKCS1_PADDING);

	if(*buffer_size == -1)
	{
		fputs("\n Impossible de chiffrer. \n",stderr);
	}
	return ciphertext;
}

P_USTR rsa_decrypt (unsigned char *ciphertext, RSA *priv_key, long enc_plaintext_length, long original_length)
{
	unsigned char *decrypted = (unsigned char *)malloc(original_length);
    int n = RSA_private_decrypt(enc_plaintext_length, ciphertext, decrypted, priv_key, RSA_PKCS1_PADDING);

	if(n == -1)
	{
		fputs("\n.Impossible de dechiffrer\n",stderr);
	}

	return decrypted;
}

P_USTR public_key_to_buffer(RSA* pRSA)
{
	P_USTR public_key;

	BIO *pub = BIO_new(BIO_s_mem());

    PEM_write_bio_RSAPublicKey(pub, pRSA);

    size_t pub_len = BIO_pending(pub);

    public_key = malloc(pub_len + 1);

    BIO_read(pub, public_key, pub_len);

    public_key[pub_len] = '\0';

    return public_key;
}

P_USTR private_key_to_buffer(RSA* pRSA)
{
	P_USTR private_key;

	BIO *pri = BIO_new(BIO_s_mem());

    PEM_write_bio_RSAPrivateKey(pri, pRSA, NULL, NULL, 0, NULL, NULL);

    size_t pri_len = BIO_pending(pri);

   private_key = malloc(pri_len + 1);

    BIO_read(pri, private_key, pri_len);

    private_key[pri_len] = '\0';

    return private_key;
}
