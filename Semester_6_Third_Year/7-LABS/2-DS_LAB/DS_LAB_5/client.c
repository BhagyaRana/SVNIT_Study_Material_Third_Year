#include <stdio.h>      /* for printf() and fprintf() */
#include <arpa/inet.h>  /* for sockaddr_in and inet_ntoa() */
#include <stdlib.h>     /* for atoi() and exit() */
#include <string.h>     /* for bzero() */
#include <sys/socket.h> /* for socket(), bind(), connect(), recv() and send() */
#include <netdb.h>
#include <fcntl.h> // for open
#include <unistd.h> // for close

// Maximum Size of Buffer
#define MAX 1000
// Port Used for Socket Communication
#define PORT 8080
// Short-Hand for structure
#define SA struct sockaddr
// Message to Disconnect the Connection
#define DISCONNECT_MESSAGE "EXIT"
// Message to Get CPU Load of System
#define SYSTEM_LOAD "CPU_LOAD"

// F(x) to Return the Total Load of System
float system_load();

// F(x) for Communication between Server and Client
void chat(int sockfd);

int main()
{
    int sockfd, connfd;
    struct sockaddr_in servaddr, cli;

    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("[+] Error : Socket Creation Failed!\n");
        exit(0);
    }
    else
    {
        printf("[+] Socket Successfully Created!\n");
    }
    bzero(&servaddr, sizeof(servaddr));

    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);

    // connect the client socket to server socket
    if (connect(sockfd, (SA *)&servaddr, sizeof(servaddr)) != 0)
    {
        printf("[+] Error : Connection with Server Failed!\n");
        exit(0);
    }
    else
    {
        printf("[+] Connected to Server Succesfully\n");
    }

    // function for chat
    chat(sockfd);

    // Close the socket
    close(sockfd);

    return 0;
}

// F(x) to Return the Total Load of System
float system_load()
{
    char command[MAX], output_of_top_cmd[MAX];

    // It Stores the Output in String Buffer
    sprintf(command, "top -n1 | grep \"Cpu(s)\"");

    // Copy the Contents to "output_of_top_cmd" char Array
    FILE *fp = popen(command, "r");
    fgets(output_of_top_cmd, sizeof(output_of_top_cmd), fp);
    pclose(fp);

    int token_id = 0, i = 0;
    float Total_Load = 0;

    // Until End of String
    while (output_of_top_cmd[i] != '\0')
    {
        char token[MAX];
        int j = 0;

        // Until Space of EOL Character is encountered
        while (output_of_top_cmd[i] != '\0' && output_of_top_cmd[i] != ' ')
        {
            token[j] = output_of_top_cmd[i], j++, i++;
        }
        token[j] = '\0';

        if ((token_id == 2) || (token_id == 5))
        {
            // 2 - User CPU Usage, 5 - System Usage
            // Convert Character Array to Float and Add
            Total_Load += atof(token);
        }

        token_id++;
        i++;
    }

    return Total_Load;
}

// F(x) for Communication between Server and Client
void chat(int sockfd)
{
    int n;
    char buff[MAX];
    // Infinite loop for chat
    while (1)
    {
        if (strncmp(SYSTEM_LOAD, buff, 8) == 0)
        {
            bzero(buff, MAX);
            float Total_Load = system_load();
            if (Total_Load > 70)
                sprintf(buff, "CPU Load : %.2f [Overloaded]", Total_Load);
            else if (Total_Load > 40)
                sprintf(buff, "CPU Load : %.2f [Moderate]", Total_Load);
            else
                sprintf(buff, "CPU Load : %.2f [Lightly]", Total_Load);

            printf("\n Client : %s", buff);
            write(sockfd, buff, strlen(buff));
        }
        else if (strncmp(DISCONNECT_MESSAGE, buff, 4) == 0)
        {
            printf("\n[+] Server Disconnected!\n");
            break;
        }
        else
        {
            bzero(buff, MAX);
            printf("\n Enter Client Message : ");
            fgets(buff, MAX, stdin);
            write(sockfd, buff, strlen(buff));
            if (strncmp(buff, DISCONNECT_MESSAGE, 4) == 0)
            {
                printf("\n[+] Client Disconnected!\n");
                break;
            }
        }

        bzero(buff, MAX);
        read(sockfd, buff, MAX);
        printf("\n Server : %s", buff);
    }
}
