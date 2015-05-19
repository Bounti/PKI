#include "../common.h"

int add_certificat(CLIENT* client)
{
    FILE * pFile ;
    P_USTR rsa_ascii_public_key,*now;
    time_t rawtime;
    struct tm * timeinfo;
    char filePath[40] = {0};
    P_STR base64_sigret;

    //Open file to save new certificat
    sprintf(filePath,"RESOURCES/%s.ini",client->name);
    pFile = fopen(filePath, "a+");
    if(pFile==NULL)
        return -1;

    //RSA struct to ASCII
    rsa_ascii_public_key = public_key_to_buffer(client->pRSA);

    //Get current time, to set deadline
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    now = asctime (timeinfo);

	unsigned char hash[SHA256_DIGEST_LENGTH];
	unsigned char sign[256];
	unsigned int signLen;
	int     ret;

	SHA256(client->public_key, strlen(client->public_key), hash);

	/* Sign */
	ret = RSA_sign(NID_sha256, hash, SHA256_DIGEST_LENGTH, sign, &signLen, client->pRSA);
	printf("Signature length = %d\n", signLen);
	printf("RSA_sign: %s\n", (ret == 1) ? "OK" : "NG");
    printf("\n\nHASH : %s\n",hash);

    //BEGIN LIST
    fprintf(pFile,"l");

    //Set begin on date
    fprintf(pFile,"4:name%d:%s",(int)strlen(client->name),client->name);

    //Set begin on date
    fprintf(pFile,"10:begin_date%d:%s",(int)strlen(now),now);

    //Set PKI public key
    fprintf(pFile,"14:PKI_PUBLIC_KEY%d:%s",(int)strlen(client->public_key),client->public_key);

    //Set public key
    fprintf(pFile,"10:PUBLIC_KEY%d:%s",(int)strlen(rsa_ascii_public_key),rsa_ascii_public_key);

    //Set signature
    fprintf(pFile,"4:SIGN%d:%s",(int)strlen(base64_sigret),base64_sigret);

    //END LIST
    fprintf(pFile,"e");

    fclose(pFile);
    free(base64_sigret);
    return 0;
}
