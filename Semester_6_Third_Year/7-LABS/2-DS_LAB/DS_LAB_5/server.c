#include <stdio.h>  /* for printf() and fprintf() */
#include <stdlib.h> /* for atoi() and exit() */
#include <string.h> /* for bzero() */
#include <sys/types.h>
#include <sys/socket.h> /* for socket(), bind(), connect(), recv() and send() */
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <fcntl.h>  // for open
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
void chat(int client_id);

int main()
{
    int sockfd, client_id, len;
    struct sockaddr_in servaddr, cli;

    // socket create
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

    // Assign IP, PORT
    servaddr.sin_family = AF_INET;                /* Internet address family */
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); /* Any incoming interface */
    servaddr.sin_port = htons(PORT);              /* Local port */

    // Binding newly created socket to given IP
    if ((bind(sockfd, (SA *)&servaddr, sizeof(servaddr))) != 0)
    {
        printf("[+] Error : Socket Bind Failed!\n");
        exit(0);
    }
    else
    {
        printf("[+] Socket Successfully Binded!\n");
    }

    // Now server is ready to listen
    if ((listen(sockfd, 5)) != 0)
    {
        printf("[+] Error : Listen Failed!\n");
        exit(0);
    }
    else
    {
        printf("[+] Server Listening ... \n");
    }

    len = sizeof(cli);

    // Accept the data packet from client
    client_id = accept(sockfd, (SA *)&cli, &len);

    if (client_id < 0)
    {
        printf("[+] Server Acception from Client Failed!\n");
        exit(0);
    }
    else
    {
        printf("[+] Server Accepts the Client\n");
    }

    // Function for chatting between client and server
    chat(client_id);

    // Close the Socket
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
void chat(int client_id)
{
    int n;
    char buff[MAX];

    // Infinite loop for chat
    while (1)
    {
        // Clear the Buffer
        bzero(buff, MAX);
        // Read the message from client and copy it in buffer
        read(client_id, buff, MAX);
        // Print buffer which contains the Client contents
        printf("\n Client : %s", buff);

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

            printf("\n Server : %s\n", buff);
            write(client_id, buff, strlen(buff));
        }
        else if (strncmp(DISCONNECT_MESSAGE, buff, 4) == 0)
        {
            printf("\n[+] Client Disconnected!\n");
            break;
        }
        else
        {
            bzero(buff, MAX);
            printf("\n Enter Server Message : ");

            // Copy Server message in the buffer
            fgets(buff, MAX, stdin);

            write(client_id, buff, strlen(buff));
            if (strncmp(buff, DISCONNECT_MESSAGE, 4) == 0)
            {
                printf("\n[+] Client Disconnected!\n");
                break;
            }
        }
    }
}
