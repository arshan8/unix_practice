//ommunication using pipe()

#include<iostream>   // Provides standard input/output stream objects (cout, cin)
#include<unistd.h>   // Provides access to the POSIX operating system API, including fork(), pipe(), and read()/write()
#include<sys/types.h> // Defines data types used in system calls (like pid_t for process IDs)
#include<sys/wait.h>  // Provides declarations for wait() and related macros for managing child processes

using namespace std;

int main()
{
    int fd[2], n;
    char buffer[100];
    pid_t p;

    pipe(fd); // Creates a unidirectional pipe with two ends: fd[0] (read end) and fd[1] (write end)
    
    p = fork(); // Forks the process. Parent gets child's PID, child gets 0.

    if(p > 0) // Parent process
    {
        cout << "Parent Passing value to child" << endl;
        write(fd[1], "hello\n", 6); // Write 6 bytes ("hello\n") to the pipe (fd[1] is the write end)
        wait(NULL); // Waits for the child process to finish
    }
    else // Child process
    {
        cout << "Child printing received value" << endl;
        // n = read(fd[0], buffer, 100); // Read up to 100 bytes from the pipe (fd[0] is the read end)
        // write(1, buffer, n); // Write the received data to the terminal (file descriptor 1 is standard output)
        read([09],buffer,100);
        buffer[99] = '\0';
        cout<<"buffer"
   
   
    }

    return 0;
}
