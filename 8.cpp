//sender
#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <cstring>

struct Message {
    long msg_type;
    char text[100];
};

int main() {
    key_t key = ftok("sssfile", 67);
    int msgid = msgget(key, 0666 | IPC_CREAT);

    Message msg;
    msg.msg_type = 1;
    strcpy(msg.text, "Hello from the sender!");

    msgsnd(msgid, &msg, sizeof(msg.text), 0);
    std::cout << "Sender sent: " << msg.text << std::endl;

    return 0;
}



//recievr

#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <cstring>

struct Message {
    long msg_type;
    char text[100];
};

int main() {
    key_t key = ftok("sssfile", 67);
    int msgid = msgget(key, 0666 | IPC_CREAT);

    Message msg;
    msgrcv(msgid, &msg, sizeof(msg.text), 1, 0);
    std::cout << "Receiver received: " << msg.text << std::endl;

    msgctl(msgid, IPC_RMID, nullptr); // Cleanup message queue
    return 0;
}












