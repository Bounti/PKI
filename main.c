/*
*   @author : Corteggiani
*   @date : 13/12/2014
*/

#include "common.h"


//nasm@StrawberryCake:~/workspace/PKI_SERVER/RESOURCES$ openssl dgst -sha256 dummy.public_pem > dummy.hash
//nasm@StrawberryCake:~/workspace/PKI_SERVER/RESOURCES$ openssl rsautl -sign -inkey private.key -keyform PEM -in dummy.hash > signature
//nasm@StrawberryCake:~/workspace/PKI_SERVER/RESOURCES$ openssl rsautl -verify -inkey private.key -keyform PEM -in signature
//SHA256(dummy.public_pem)= 3bb874812985669f17f684e053daf4d2cbf18a85d6b8da6b5ac98c812d8c9816

//gcc -o Launcher main.c -lcrypto -L. -liniparser
int main(int argc, char* argv[])
{

printf("\n\n\n\
        ██╗     ██╗ ██████╗ ██╗  ██╗████████╗    ██████╗ ██╗  ██╗██╗\n\
        ██║     ██║██╔════╝ ██║  ██║╚══██╔══╝    ██╔══██╗██║ ██╔╝██║\n\
        ██║     ██║██║  ███╗███████║   ██║       ██████╔╝█████╔╝ ██║\n\
        ██║     ██║██║   ██║██╔══██║   ██║       ██╔═══╝ ██╔═██╗ ██║\n\
        ███████╗██║╚██████╔╝██║  ██║   ██║       ██║     ██║  ██╗██║\n\
        ╚══════╝╚═╝ ╚═════╝ ╚═╝  ╚═╝   ╚═╝       ╚═╝     ╚═╝  ╚═╝╚═╝\n\n\n");

    //RSA *pRSA;

    ERR_load_crypto_strings();

    //freopen("error.log","a+", stdout);

    /*First check if a public key already exist in, else generate it*/
	/*if((pRSA = load_pubkey()) == NULL || (pRSA = load_privkey()) == NULL )
	{
	    fputs("Unable to find RSA keys",stderr);
        return 0;
	}*/

	/*SERVER PROPERTIES*/
    SERVER server;
	server.net.callback = &(process_request);
	server.max_connection = 5000;
	server.mode = PER_PAQUET;
	server.net.port = 8080;
	server.running = FALSE;
	server.net.socket = INVALID_SOCKET;
	server.net.sockadd_in_size = sizeof(server.net.sockaddr_in);

    return init_connection(&server) & run_server(&server);

    NEW_INFO("Shutdown server");

    ERR_free_strings();
}
