//.Createachildfromparentprocessusingfork()andcountercountstill5inbothprocessesanddisplays

#include <iostream>
#include <unistd.h> // For fork() and sleep()

int main() {
    // Create a child process using fork()
    pid_t child_pid = fork();

    // Check if fork() failed
    if (child_pid == -1) {
        std::cerr << "Fork failed." << std::endl; // Error message if fork fails
        return 1; // Exit with an error code
    }

    // Loop to count from 1 to 5
    for (int i = 1; i <= 5; i++) {
        if (child_pid == 0) {
            // This block is executed by the child process
            std::cout << "Child Count: " << i << std::endl; // Output child's count
        } else {
            // This block is executed by the parent process
            std::cout << "Parent Count: " << i << std::endl; // Output parent's count
        }
        sleep(1); // Sleep for 1 second to make output readable
    }

    return 0; // Exit the program
}

