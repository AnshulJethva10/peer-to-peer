// #include <libeom.h>
#include "Networking/Nodes/Client.h"
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <arpa/inet.h>

void * server_function(void *arg)
{
    printf("Server running...\n");
    struct Server server = server_constructor(AF_INET, SOCK_STREAM, 0, INADDR_ANY, 1248, 20);
    struct sockaddr *address = (struct sockaddr *)&server.address;
    socklen_t address_length = (socklen_t)sizeof(server.address);
    while(1)
    {
        int client = accept(server.socket, address, &address_length);
        char request[255];
        memset(request, 0, 255);
        read(client, request, 255);
        printf("\t\t\t%s says: %s\n",inet_ntoa(server.address.sin_addr), request);
        close(client);
    }
    return NULL;
}

void client_function(char *request)
{
    struct Client client = client_constructor(AF_INET, SOCK_STREAM, 0, 1248, INADDR_ANY);
    client.request(&client, "127.0.0.1", request);
}

int main()
{
    printf("Starting server...\n");
    pthread_t server_thread;
    pthread_create(&server_thread, NULL, server_function, NULL);

    while(1)
    {
        char request[255];
        memset(request, 0, 255);
        fgets(request, 255, stdin);
        client_function(request);
    }
}