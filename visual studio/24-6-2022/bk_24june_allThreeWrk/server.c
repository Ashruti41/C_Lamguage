#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <wait.h>
#include <signal.h>
#include <errno.h>
#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define TRUE  		1
#define FALSE 		0
#define MAX_CLIENT 	3
#define MAX_QUEUE 	5
#define MAXBUF 		256
#define PORT_NO 	2000
#define SERVER_IP 	"127.0.0.1"

int main()
{
	int addrlen=0, n=0, i=0, max=0, sockfd=0, commfd=0, upSocket=0, fds[5], ret=0,count;
	char buffer[MAXBUF]={0},server_message[MAXBUF]={0};
	struct sockaddr_in addr, client;

	fd_set master, copy;
	memset(&addr, 0x00, sizeof(addr));
	memset(&client, 0x00, sizeof(client));

	do
	{
		//create the socket for server
		sockfd = socket(AF_INET, SOCK_STREAM, 0);
		if(sockfd == -1)
		{
			printf("Error, while creating socket inside server\n");
			break;
		}

		//add the socket creadentials
		addr.sin_family = AF_INET;
		addr.sin_port = htons(PORT_NO);
		addr.sin_addr.s_addr = inet_addr(SERVER_IP);

		//to bind the socket to a well-known address
		ret = bind(sockfd,(struct sockaddr*)&addr ,sizeof(addr));
		if(ret == -1)
		{
			printf("Error, while binding the socket to an addess\n");
			break;
		}
	
		//to notify the kernel of its willingness to accept incoming connections	
		ret = listen(sockfd, MAX_QUEUE);
		if(ret == -1)
		{
			printf("Error, while notifying the kernel of its willingness\n");
			break;
		}

		while(TRUE){

			//Waiting to connect with clients
			printf("Waiting to connect with clients\n");
			for (i=0; i<MAX_CLIENT; i++) 
			{
				memset(&client, 0, sizeof (client));
				addrlen = sizeof(client);
				fds[i] = accept(sockfd,(struct sockaddr*)&client, &addrlen);
				if(fds[i] == -1)
				{
					printf("Error, while binding the socket to an addess\n");
					break;
				}
				if(fds[i] > max)
					max = fds[i];
			}

			//clears a set
			FD_ZERO(&master);
			for (i=0; i<MAX_CLIENT; i++ ) 
			{
				FD_SET(fds[i],&master);
			}

			while(1)
			{
				copy = master;

				//allows a program to monitor multiple file descriptors
				select(max+1, &copy, NULL, NULL, NULL);
				for(i=0; i<MAX_CLIENT; i++) 
				{
					//used to test if a file descriptor
              			//is still present in a set
					if(FD_ISSET(fds[i], &copy))
					{
						memset(buffer,0,MAXBUF);
						ret = read(fds[i], buffer, MAXBUF);
						if(ret == -1)
						{
							printf("Error, while reading the data\n");
							break;
						}
						printf("Received: %s\n", buffer);

						if(fds[i]>0){
							for(i=1; i<MAX_CLIENT; i++){
								}
						}
						else{
							if(strcmp(buffer, "end")==0){
								send(sockfd, buffer, strlen(buffer),0);
								printf("Existing the client process\n");
								break;
							}
								upSocket = fds[i+1];	
						}
							ret = send(upSocket, buffer, strlen(buffer), 0);
							if(ret == -1)
							{
								printf("Error, while writing the data\n");
								break;
							}
						}
					}
				}
			}
	}while(FALSE);
	if(sockfd != 0)
	{
		close(sockfd);
	}
	return 0;
}
