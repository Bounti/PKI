#include "../common.h"

STATUT_CODE file_to_buff(P_STR file_path, P_STR file_buffer)
{
	FILE *file;
	struct stat file_status;

	file = fopen(file_path, "r");
	if(file == NULL)
	    return raise_error(FAILURE,"Unable to find client");

	//Get information about a file
	stat(file_path, &file_status);
	file_buffer = (char *)malloc(file_status.st_size);

    //Copy file in memory
	if(fread(file_buffer,1,file_status.st_size,file) <=0 )
	    return raise_error(FAILURE,"Fichier vide");

	fclose(file);

    return SUCCESS;
}

STATUT_CODE create_rsa_keys_files(P_STR input_file_private_key, P_STR input_file_public_key, RSA* pRSA)
{
    int ret = 0;
    FILE* file = NULL;
    
    pRSA = RSA_generate_key(4096,RSA_3,NULL,NULL);

    file = fopen(input_file_private_key,"w+");
    ret = PEM_write_RSAPrivateKey(file, pRSA, NULL/*EVP_des_ede3_cbc()*/, NULL, 0, NULL,NULL);
    if( file == NULL || ret != 1 )
	    return raise_error(CRITICAL_FAILURE,"Unable to write public key");

    fclose(file);
    
    file = fopen(input_file_public_key,"w+");
    ret = PEM_write_RSAPublicKey(file, pRSA);
    if( file == NULL || ret != 1 )
	    return raise_error(CRITICAL_FAILURE,"Unable to write public key");

    fclose(file);

    return SUCCESS;
}

STATUT_CODE load_pubkey(P_STR input_file_private_key, P_STR input_file_public_key, RSA* pRSA)
{
	FILE *file;
	struct stat file_status;
	char *file_buffer = NULL;

	file = fopen(input_file_private_key, "r");
	if(file == NULL)
        return create_rsa_keys_files(input_file_private_key,input_file_public_key,pRSA);

    //Get information about a file
	stat(input_file_public_key, &file_status);
	file_buffer = (char *)malloc(file_status.st_size);

    //Copy file in memory
	if( fread(file_buffer,1,file_status.st_size,file) <=0 )
		return raise_error(FAILURE,"fread()");

	fclose(file);

    BIO *bp = BIO_new_mem_buf(file_buffer,-1);
    pRSA = PEM_read_bio_RSAPublicKey(bp, NULL, NULL, NULL);
    if( !pRSA)
        return raise_error(CRITICAL_FAILURE,ERR_error_string( ERR_get_error(),NULL));

    BIO_free(bp);

	free(file_buffer);
	return SUCCESS;
}

RSA* load_privkey(P_STR input_file_private_key)
{
    FILE *file = fopen(input_file_private_key,"r");
    if( file == NULL )
    {
	    fputs("Unable to write public key ...\n",stderr);
        return NULL;
    }

    RSA *pRSA = PEM_read_RSAPrivateKey(file,NULL,NULL,NULL);
    if( !pRSA)
        printf("ERROR: Could not load PUBLIC_KEY! PEM_read_bio_RSA_PUBKEY_FAILED: %s\n", ERR_error_string( ERR_get_error(),NULL));

	return pRSA;
}

