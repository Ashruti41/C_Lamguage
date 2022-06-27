#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h> // for open
#include <unistd.h> // for close

#define TRUE            1
#define FALSE           0
#define BUFFER_SIZE 	256
#define PORT_NO         2000
#define SERVER_IP       "127.0.0.1"

int main(void)
{
	int socket_desc=0;
	struct sockaddr_in server_addr, client_addr;
	char server_message[BUFFER_SIZE]={0}, client_message[BUFFER_SIZE]={0};

	do
	{
		// Clear buffers
		memset(server_message,'\0',sizeof(server_message));
		memset(client_message,'\0',sizeof(client_message));

		// Create socket
		socket_desc = socket(AF_INET, SOCK_STREAM, 0);
		if(socket_desc == -1)
		{
			printf("Unable to create socket\n");
			break;
		}
		printf("Socket created successfully\n");

		// Set port and IP the same as server-side
		server_addr.sin_family = AF_INET;
		server_addr.sin_port = htons(PORT_NO);
		server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

		// Send connection request to server
		if(connect(socket_desc, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
		{
			printf("Unable to connect\n");
			break;
		}
		printf("Connected with server successfully\n");

		while(1)
		{
			// Get input from the user
			printf("Enter message: ");
			scanf("%[^\n]", client_message);
			if(send(socket_desc, client_message, strlen(client_message), 0) < 0)
			{
				printf("Unable to send message\n");
				break;
			}
			if(strcmp(client_message, "end")==0)
			{
				printf("Exiting the client process\n");
				break;
			}

			// Receive the server's response
			memset(server_message, 0x00, sizeof(server_message));
			if(recv(socket_desc, server_message, sizeof(server_message), 0) < 0)
			{
				printf("Error while receiving server's msg\n");
				break;
			}
			printf("Server's response: %s\n",server_message);
			if(strcmp(server_message, "end")==0)
			{
				send(socket_desc, server_message, strlen(server_message), 0);
				printf("Exiting the client process\n");
				break;
			}
			sleep(1);
		}
	}while(FALSE);

	// Close the socket
	if(socket_desc != 0)
	{
		close(socket_desc);
	}
	return 0;
}
