/*
 * query.h
 *
 *  Created on: Apr 25, 2015
 *      Author: nasm
 */

#ifndef NET_QUERY_H_
#define NET_QUERY_H_

typedef enum QUERY_TYPE QType;

enum QUERY_TYPE
{
	QUERY_ADD,
	QUERY_GET
};

typedef struct{
	QType code;
	STR name[MAX_CLIENT_NAME_LEN];
}QUERY,*P_QUERY;

STATUT_CODE process_request(P_SOCKET_DATA data);

STATUT_CODE decode_query(P_USTR data,P_QUERY query);

STATUT_CODE process_get_query(P_SOCKET_DATA data, P_QUERY query);

STATUT_CODE process_add_query(P_SOCKET_DATA data, P_QUERY query);

#endif /* NET_QUERY_H_ */
