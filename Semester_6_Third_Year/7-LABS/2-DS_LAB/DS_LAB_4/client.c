// TCP CLIENT {Connects with the server program knowing IP address and port number.}

// For printf
#include <stdio.h>
// For strlen
#include <string.h>
// For socket
#include <sys/socket.h>
// For inet_addr
#include <arpa/inet.h>
// For write
#include <unistd.h>

#define MAX_SIZE 2000

// [U19CS012] BHAGYA VINOD RANA

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in server;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        printf("Could Not Create Socket!\n");
    }
    printf("Socket Created Successfully!\n");

    // IP Address
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    // Port Number
    server.sin_port = htons(8888);

    // Connect to remote server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        perror("Connection Failed! Error Occured!");
        return 1;
    }

    printf("Client Connected!\n");

    // keep communicating with server
    while (1)
    {
        char message[MAX_SIZE], server_reply[MAX_SIZE];
        printf("Enter Message [to be Echoed by Server] : ");
        scanf("%s", message);

        // Send Message to the Server
        if (send(sock, message, strlen(message), 0) < 0)
        {
            printf("Send Failed\n");
            return 1;
        }

        // Receive Reply from Server
        if (recv(sock, server_reply, MAX_SIZE, 0) < 0)
        {
            printf("recv() Failed!\n");
            break;
        }
        printf("Server Reply [Echo] : %s \n\n", server_reply);
    }

    close(sock);
    return 0;
}