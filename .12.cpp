/***programs from gfg:

use man socket, man bind, man etc etc to help usereself n code



10)
        s,b,l,a,s,c
12)
sender: s,b,l,a,r,c
recievr:s,c,c



server.cpp:

socket()
bind()
listen()
accept()
recv()
close(clientSocket);


client.cpp

socket()
connet()
send()
close(clientSocket);**/


// SERVER
//
#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;

int main()
{
    
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

 
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    bind(serverSocket, (struct sockaddr*)&serverAddress,sizeof(serverAddress));

   
    listen(serverSocket, 5);

    int clientSocket  = accept(serverSocket, nullptr, nullptr);

 
    char buffer[1024] = { 0 };
    recv(clientSocket, buffer, sizeof(buffer), 0);
    cout << "Message from client: " << buffer<< endl;

    
    close(serverSocket);

    return 0;
}




-------------------------------------------------------------------------------------

RECIEVER


#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

int main()
{
  
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    
    connect(clientSocket, (struct sockaddr*)&serverAddress,
            sizeof(serverAddress));

    const char* message = "Hello, server!";
    send(clientSocket, message, strlen(message), 0);

    close(clientSocket);

    return 0;
}