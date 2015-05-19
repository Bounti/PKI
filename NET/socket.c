#include "../common.h"

/*-------------------------------------------------------------------------*/
/**
  @brief    Init server
  @return   STATUT_CODE CRITICAL_FAILURE || SUCCESS
 */
/*--------------------------------------------------------------------------*/
STATUT_CODE init_connection(P_SERVER server)
{
	int option_val = 1;

	server->net.socket = socket(AF_INET, SOCK_DGRAM, 0);
	if(server->net.socket == INVALID_SOCKET)
		return 0;

	server->net.sockaddr_in.sin_addr.s_addr = htonl(INADDR_ANY);
	server->net.sockaddr_in.sin_port = htons(server->net.port);
	server->net.sockaddr_in.sin_family = AF_INET;

	if(setsockopt(server->net.socket, SOL_SOCKET, SO_REUSEADDR, &option_val, sizeof(int)) == -1)
	{
		return raise_error(CRITICAL_FAILURE,"setsockopt()");
	}

	if(bind(server->net.socket,(struct sockaddr*)&server->net.sockaddr_in,server->net.sockadd_in_size) == SOCKET_ERROR)
	{
		return raise_error(CRITICAL_FAILURE,"bind()");
	}

	server->running = TRUE;

	return SUCCESS;
}

STATUT_CODE run_server(P_SERVER server)
{
	server->net.data.receipt = (P_STR)malloc(sizeof(STR)*MAX_NETWORK_SIZE);
	server->net.data.sending = (P_STR)malloc(sizeof(STR)*MAX_NETWORK_SIZE);

	while (server->running)
	{
		if(server->net.data.sending == NULL || server->net.data.receipt == NULL)
		{
			close(server->net.socket);
			return raise_error(CRITICAL_FAILURE,"run_server : allocation server->data failed");
		}

		if(recvfrom(server->net.socket, server->net.data.receipt, MAX_NETWORK_SIZE,
				0,(struct sockaddr*)&server->net.sockaddr_in, &server->net.sockadd_in_size) < 0)
			raise_error(FAILURE,"recvfrom()");

		if(server->net.callback(&server->net.data) != SUCCESS)
			raise_error(FAILURE,"callback()");

		if(sendto(server->net.socket, server->net.data.sending, strlen(server->net.data.sending),
				0,(struct sockaddr*)&server->net.sockaddr_in, server->net.sockadd_in_size) < 0)
			raise_error(FAILURE,"sendto()");
	}

	return SUCCESS;
}
