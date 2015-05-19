/*
 * query.c
 *
 *  Created on: Apr 25, 2015
 *      Author: Corteggiani Nassim
 */
#include "../common.h"

STATUT_CODE decode_query(P_USTR data,P_QUERY query)
{
	STR code = data[0];
	if(code == '0')
		query->code = QUERY_ADD;
	else if(code == '1')
		query->code = QUERY_GET;

	strncpy(query->name,&data[1],MAX_CLIENT_NAME_LEN);

	if(query->name[strlen(query->name)-1] == '\n')
		query->name[strlen(query->name)-1] = '\0';

	return SUCCESS;
}

STATUT_CODE process_request(P_SOCKET_DATA data)
{
	QUERY query;
	if( decode_query(data->receipt,&query) != SUCCESS)
		return FAILURE;

	NEW_INFO("RECEPTION DE : %s",data->receipt);

	switch(query.code)
	{
	case QUERY_GET:
		NEW_INFO("GET REQUEST %s",query.name);
		return process_get_query(data,&query);
		break;
	default :
		return raise_error(FAILURE,"bad request");
	}

	return SUCCESS;
}

STATUT_CODE process_get_query(P_SOCKET_DATA data, P_QUERY query)
{
	char filePath[14+MAX_CLIENT_NAME_LEN] = {0};
	char* certificat;

	sprintf(filePath,"RESOURCES/%s.ini",query->name);

	if( file_to_buff(filePath,certificat) != SUCCESS )
		return raise_error(FAILURE,"Unable to get certificat");

	strncpy(data->sending,certificat,strlen(certificat));

	return SUCCESS;
}

STATUT_CODE process_add_query(P_SOCKET_DATA data, P_QUERY query)
{
	//strcpy(client->name,ben.val.l[1]->val.s);
	//strcpy(client->public_key,ben.val.l[2]->val.s);

	//printf("DATA : %s %s \n",client->name,client->public_key);
	//add_certificat(client);

	return SUCCESS;
}
