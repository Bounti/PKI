/*
 * common.h
 *
 *  Created on: Apr 25, 2015
 *      Author: nasm
 */

#ifndef COMMON_H_
#define COMMON_H_

#define MAX_NETWORK_SIZE 4096

typedef unsigned int u_int;

typedef unsigned char * P_USTR;

typedef unsigned char USTR;

typedef char* P_STR;

typedef char STR;

#define TRUE 1

#define FALSE 0

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> /* close */
#include <netdb.h> /* gethostbyname */
#include <sys/stat.h>
#include <netinet/in.h>
#include <openssl/rsa.h>
#include <openssl/engine.h>
#include <openssl/pem.h>
#include <openssl/bio.h>

#include "debug.h"
#include "CLIENT/client.h"
#include "ERROR/error.h"
#include "NET/socket.h"
#include "NET/query.h"
#include "SHA/sha.h"
#include "FILE/file.h"
#include "RSA/rsa.h"
#include "AES/aes.h"
#include "CERTIFICAT/certificat.h"

#endif /* COMMON_H_ */
