#include "../common.h"

void print_client(CLIENT* client)
{
    printf("[CLIENT]\nname: %s\nPK: %s\n",client->name,client->public_key);
}
