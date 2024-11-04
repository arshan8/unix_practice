#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

const int PORT = 8080;

int main() {
    // Create socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    // Define server address
    sockaddr_in server_address{};
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    
    // Bind socket
    bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address));
    
    // Listen for connections
    listen(server_socket, 10);
    std::cout << "Server is listening on port " << PORT << std::endl;

    while (true) {
        // Accept a connection
        int client_socket = accept(server_socket, nullptr, nullptr);
        
        // Send response
        const char* response = 
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/html\r\n"
            "\r\n"
            "<html><body><h1>Hello from C++ Web Server!</h1></body></html>";
        send(client_socket, response, strlen(response), 0);
        
        // Close the client socket
        close(client_socket);
    }

    // Close the server socket (not reachable in this code)
    close(server_socket);
    return 0;
}
