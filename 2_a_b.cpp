/// copy from source to dest file using system calls


#include <fcntl.h>     // For open()
#include <unistd.h>    // For read(), write(), close()

#define BUFFER_SIZE 1024

int main() {
    const char* sourceFile = "source.txt";           // Source file name
    const char* destinationFile = "destination.txt"; // Destination file name

    int source_fd = open(sourceFile, O_RDONLY);       // Open source file
    int destination_fd = open(destinationFile, O_WRONLY | O_CREAT | O_TRUNC, 0644); // Open/Create destination file

    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;

    // Read from source and write to destination
    while ((bytesRead = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        write(destination_fd, buffer, bytesRead);
    }

    close(source_fd);    // Close source file
    close(destination_fd); // Close destination file

    return 0;
}


//environ

// #Why char** environ?
// Array of Strings: The environment variables are stored as an array of strings. Each environment variable is a char*, and the entire collection of environment variables is represented as an array of these pointers. Thus, char** is used.

// Dynamic Size: The number of environment variables is not fixed; hence, using a pointer to a pointer allows the program to dynamically access each variable until it reaches a terminating null pointer (nullptr).



 #include <iostream>
 extern char** environ;
 int main() {
 char** env = environ;
 while (*env != nullptr) {
 std::cout << *env << std::endl;
 env++;
 }
 return 0;
 }
