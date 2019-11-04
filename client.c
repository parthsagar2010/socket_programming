#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>

//#ifdef __WIN32__
#include <sys/socket.h>
//#else
//#include<winsock2.h>
//#include<winsock.h>
#include <netinet/in.h>
//#endif // __WIN32__

int main()
{
    // Creating a socket
    int net_socket;
    net_socket = socket(AF_INET,SOCK_STREAM,0);

    // Specify an address for the socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    
    //server_address.sin_addr.s_addr = INADDR_ANY;
	server_address.sin_addr.s_addr = inet_addr("130.191.166.4");

    int connection_status = connect(net_socket,(struct sockaddr *) &server_address,sizeof(server_address));

    //check for error with the connection
    if(connection_status == -1)
    {
        printf("There was an error making a connection \n\n");
    }
    // recieve data from the server
    char server_response[256];
    recv(net_socket, &server_response,sizeof(server_response),0);

    // print out the server's response
    printf("The server sent the data: %s\n",server_response);

    //and then close the socket
    close(net_socket);

    return 0;
}

