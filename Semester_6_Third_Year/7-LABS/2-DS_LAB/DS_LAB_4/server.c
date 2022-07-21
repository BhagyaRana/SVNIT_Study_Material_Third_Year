// TCP SERVER {Opens a Listening Socket and Waits for Client}

#include <stdio.h>
// For strlen
#include <string.h>
// For sockets
#include <sys/socket.h>
// For inet_addr
#include <arpa/inet.h>
// For write
#include <unistd.h>

#define MAX_SIZE 2000

// [U19CS012] BHAGYA VINOD RANA

int main(int argc, char *argv[])
{
    int socket_desc, client_sock, c, read_size;
    struct sockaddr_in server, client;
    char client_message[MAX_SIZE];

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1)
    {
        printf("Could Not Create Socket!\n");
    }
    printf("Socket Created!\n");

    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);

    // Bind
    if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        // print the error message
        perror("Bind Failed! Error Occured!");
        return 1;
    }
    printf("Bind Done!\n");

    // Listen
    listen(socket_desc, 3);

    // Accept and incoming connection
    puts("Waiting for Incoming Clients Connections ...");
    c = sizeof(struct sockaddr_in);

    // Accept connection from an incoming client
    client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&c);

    if (client_sock < 0)
    {
        perror("Accept Failed");
        return 1;
    }
    printf("Connection Accepted!\n");

    // Receive a Message from client
    while ((read_size = recv(client_sock, client_message, MAX_SIZE, 0)) > 0)
    {
        // Send the message Back to client [Echo]
        write(client_sock, client_message, strlen(client_message));
    }

    if (read_size == 0)
    {
        printf("Client Disconnected!\n");
        fflush(stdout);
    }
    else if (read_size == -1)
    {
        perror("recv() failed");
    }

    return 0;
}