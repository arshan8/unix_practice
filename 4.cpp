//Illustrate two processes communicating using shared memory


#include <iostream>  // For std::cout
#include <sys/ipc.h> // For key_t and ftok()
#include <sys/shm.h> // For shmget(), shmat(), shmdt(), shmctl()
#include <cstring>   // For strcpy()
#include <unistd.h>  // For fork() and sleep()

#define SHM_SIZE 1024 // Size of shared memory

int main() {
    key_t key = ftok("shmfile", 65); // Create a unique key
    int shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT); // Create shared memory
    char* str = (char*) shmat(shmid, (void*)0, 0); // Attach shared memory

    pid_t child_pid = fork(); // Create child process

    if (child_pid == 0) {
        // Child process writes to shared memory
        const char* child_message = "Hello from child!";
        strcpy(str, child_message);
    } else {
        // Parent process sleeps briefly
        sleep(1);
        // Parent process writes to shared memory
        const char* parent_message = "Hello from parent!";
        strcpy(str, parent_message);
    }

    // Display the message from shared memory
    std::cout << "Message from shared memory: " << str << std::endl;

    // Detach from and remove shared memory
    shmdt(str);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
