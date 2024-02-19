#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MESSAGE_LENGHTH 1024
#define PORT 8888
//macro for socketaddr as SA 
#define SA struct sockaddr

int socket_file_descriptor, connection;
struct sockaddr_in serveraddress, client;
char message[MESSAGE_LENGHTH];

int main(){

    //create socket
    socket_file_descriptor = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_file_descriptor == -1){
        printf("Creation of socket failed.\n");
        exit(1);
    }

    //erase memory
    bzero(&serveraddress, sizeof(serveraddress));
    //set the server properties
    serveraddress.sin_addr.s_addr = inet_addr("127.0.0.1");
    //portnumber
    serveraddress.sin_port = htons(PORT);
    //protocol family
    serveraddress.sin_family = AF_INET;

    //estabilish the connection with our server
    connection = connect(socket_file_descriptor, (SA*)&serveraddress, sizeof(serveraddress));

    if (connection == -1){
        printf("connection with the server failed. port: %d\n", PORT);
        exit(1);
    }

    //interact with server
    while(1){
        bzero(message, sizeof(message));
        if ((strncmp(message, "end", 3)) == 0){
            write(socket_file_descriptor, message, sizeof(message));
            printf("client exit.\n");
            break;
        }
        //sending data to server
        ssize_t bytes = write(socket_file_descriptor, message, sizeof(message));
        //if the number of bytes is >0 then the data was sent successfully
        if(bytes >= 0){
            printf("data was sent to the server successfully.\n");
        }

        bzero(message, sizeof(message));
        //read the response from the server
        read(socket_file_descriptor, message, sizeof(message));
        printf("data received from server: %s\n", message);

        //closing the socket 
        close(socket_file_descriptor);





    }


    return 0;
}