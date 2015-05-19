#ifndef _CERTIFICAT
#define _CERTIFICAT

#include <time.h>
#include <unistd.h>

#include <openssl/rsa.h>
#include <openssl/sha.h>

typedef struct
{
	int tm_sec;       /* secondes (0,59) */
	int tm_min;       /* minutes (0,59) */
	int tm_hour;      /* heures depuis minuit (0,23) */
	int tm_mday;      /* jour du mois (0,31) */
	int tm_mon;       /* mois depuis janvier (0,11) */
	int tm_year;      /* années écoulées depuis 1900 */
	int tm_wday;      /* jour depuis dimanche (0,6) */
	int tm_tm_yday;   /* jour depuis le 1er janvier (0,365) */
	int tm_isdst;
}TIME;

int add_certificat(CLIENT* client);

void certificat_to_buffer(char* buffer, CLIENT* client);

void certificat_to_client(char name[],CLIENT* client);

#endif
