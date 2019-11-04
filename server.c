#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>

int main(){
	char server_msg[256] = "You've reached the server";

	// Create the server socket
	int server_socket;
	server_socket = socket(AF_INET, SOCK_STREAM, 0);

	// Define the server address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr = inet_addr("130.191.166.4");

	//server_address.sin_addr.s_addr = INADDR_ANY;

	// Bind the socket to our specified IP & port
	bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));

	listen(server_socket, 5);

	int client_socket;
	client_socket = accept(server_socket, NULL, NULL);

	// Send the message
	send(client_socket, server_msg, sizeof(server_msg), 0);

	// Close the socket
	close(server_socket);

	return 0;
}