#ifndef _SOCKET
#define _SOCKET

typedef enum MODE
{
	PER_CONNECTION,
	PER_OBJECT,
	PER_PAQUET
}MODE;

typedef struct{
	P_STR receipt;
	P_STR sending;
}SOCKET_DATA,*P_SOCKET_DATA;

typedef STATUT_CODE (*P_CALLBACK) (P_SOCKET_DATA);

typedef struct{
	int socket;
	int port;
	P_CALLBACK callback;
	struct sockaddr_in sockaddr_in;
	socklen_t sockadd_in_size;
	SOCKET_DATA data;
}NET,*P_NET;

typedef struct{
	NET net;
	int max_connection;
	MODE mode;
	int running;
}SERVER,*P_SERVER;

#define INVALID_SOCKET -1
#define SOCKET_ERROR -1

STATUT_CODE run_server(P_SERVER server);

STATUT_CODE init_connection(P_SERVER server);

void stop_server(int signal);

#endif
