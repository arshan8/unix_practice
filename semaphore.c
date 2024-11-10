#include <iostream>
#include <semaphore.h>

using namespace std;

sem_t manager;  // Semaphore to manage access to the two resources (counter spots)
int buffer = 0; // Shared resource: the buffer (indicating number of filled spots)

void producer() {
    sem_wait(&manager);  // Wait for the manager (lock)
    if (buffer < 3) {    // If there is space in the buffer (0 or 1 items)
        buffer++;        // Produce an item (increment buffer count)
        cout << "Produced an item! Buffer now has " << buffer << " item(s)." << endl;
    }
    else{cout<<"no enough resources to keep the produce"<<endl;}
    sem_post(&manager);  // Release the manager (unlock)
}

void consumer() {
    sem_wait(&manager);  // Wait for the manager (lock)
    if (buffer > 0) {    // If the buffer has items (1 or 2 items)
        buffer--;        // Consume an item (decrement buffer count)
        cout << "Consumed an item! Buffer now has " << buffer << " item(s)." << endl;
    }
     else{cout<<"no enough resource to consume"<<endl;}
    sem_post(&manager);  // Release the manager (unlock)
}

int main() {
    // Initialize the semaphore
    sem_init(&manager, 0, 2);  // Semaphore to manage access to two spots (initial value is 2)

    // Run producer and consumer in a loop (simulating a few iterations)
     // Consumer consumes the item
    int choice;
   while(1)
   {cout<<" \t \t \t \n enter: 1: produce , 2: consume; 3: quit \n \n"<<endl;
   cin>>choice;
   if (choice == 1)
	{producer();}
   else if (choice == 2)
   	{consumer();}
   else
   {return -1;}
   	
   }
    // Clean up
    
    sem_destroy(&manager);

    return 0;
}
