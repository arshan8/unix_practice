//inter process communication with message queue

//reciever

#include <iostream>
#include <mqueue.h>
#include <cstring>

#define QUEUE_NAME "/my_queue"
#define MAX_MSG_SIZE 1024

int main() {
    mqd_t mq;                        // Message queue descriptor
    char buffer[MAX_MSG_SIZE];        // Buffer to store received message

    // Open the message queue in read-only mode (O_RDONLY)
    mq = mq_open(QUEUE_NAME, O_RDONLY);
    if (mq == (mqd_t)-1) {
        perror("Receiver: mq_open");  // Print error message if opening fails
        return 1;
    }

    // Receive the message from the queue
    if (mq_receive(mq, buffer, MAX_MSG_SIZE, NULL) == -1) {
        perror("Receiver: mq_receive");  // Print error message if receiving fails
    } else {
        std::cout << "Received: " << buffer << std::endl;  // Print the received message
    }

    // Close the message queue
    mq_close(mq);
    return 0;
}




//sender
#include <iostream>     // For standard input/output
#include <mqueue.h>     // For POSIX message queue functions
#include <cstring>      // For strlen() to calculate the length of the message
#include <unistd.h>     // For POSIX standard functions (not used here but included for consistency)

#define QUEUE_NAME "/my_queue"  // Name of the message queue
#define MAX_MSG_SIZE 256        // Maximum message size allowed in the queue

int main() {
    mqd_t mq;  // Message queue descriptor

    // Create the message queue for writing (O_WRONLY) with create flag (O_CREAT) and permissions (0644)
    mq = mq_open(QUEUE_NAME, O_CREAT | O_WRONLY, 0644, NULL);
    if (mq == (mqd_t)-1) {  // Error checking for message queue creation
        perror("Sender: mq_open");  // Print error message if mq_open fails
        return 1;
    }

    // Create the message to send
    const char* message = "Hi, this is from sender";

    // Send the message to the message queue
    if (mq_send(mq, message, strlen(message) + 1, 0) == -1) {  // +1 to include null terminator
        perror("Sender: mq_send");  // Print error message if mq_send fails
    } else {
        std::cout << "Sent: " << message << std::endl;  // Print message sent confirmation
    }

    // Close the message queue
    mq_close(mq);
    return 0;
}

