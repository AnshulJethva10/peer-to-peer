#include "Client.h"

#include <stdlib.h>
#include <arap/inet.h>
#include <string.h>
#include <unistd.h>

char * request(struct Client *client, char *server_ip, void *request, unsigned long size);

struct Client client_constructor(int domain, int service, int protocol, int port, unsigned long interface)
{
    // instantiate a client object
    struct Client client;
    client.domain = domain;
    client.port = port;
    client.interface = interface;
    // establish a socket connecion
    client.socket = socket(domain, service, protocol);
    client.request = request;
    // return the constructed socket 
    return client;
}

char * request(struct Client *client, char *server_ip, void *request, unsigned long size)
{
    // create an address struct for the server
    struct sockaddr_in server_address;
    // copy the client's parameters to this address
    server_address.sin_family = client->domain;
    server_address.sin_port = htons(client->port);
    server_address.sin_addr.s_addr = (int)client->interface;
    // make the connection
    inet_pton(client->domain, server_ip, &server_address.sin_addr);
    connect(client->socket, (struct sockaddr*)&server_address, sizeof(server_address));
    // send the request
    send(client->socket, request, size, 0);
    // read the response
    char *response = malloc(30000);
    read(client->socket, response, 30000);
    return response;
}