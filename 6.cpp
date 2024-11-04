//round ribbin

#include <iostream>
using namespace std;

int main() {
    int limit;
    float time_quantum;
    cout << "Enter Total Number of Processes: ";
    cin >> limit;

    // Arrays to store arrival time, burst time, and remaining burst time for each process
    float arrival_time[10], burst_time[10], remaining_time[10];
    float wait_time = 0, total_time = 0, completed_processes = 0;

    // Input for arrival and burst times
    for (int i = 0; i < limit; i++) {
        cout << "\nEnter Details of Process[" << i + 1 << "]\n";
        cout << "Arrival Time: ";
        cin >> arrival_time[i];
        cout << "Burst Time: ";
        cin >> burst_time[i];
        remaining_time[i] = burst_time[i]; // Initialize remaining time with burst time
    }

    cout << "\nEnter Time Quantum: ";
    cin >> time_quantum;

    cout << "\nProcess ID\tBurst Time\tTurnaround Time\tWaiting Time\n";

    // Round Robin Scheduling
    while (completed_processes < limit) {
        bool process_found = false; // Track if any process can be executed
        for (int i = 0; i < limit; i++) {
            // Check if the process is ready to execute
            if (remaining_time[i] > 0 && arrival_time[i] <= total_time) {   //this if checks is any process is excutabel , means its availabe to be executed
                process_found = true; // A process is ready to execute
                if (remaining_time[i] <= time_quantum) {
                    total_time += remaining_time[i];
                    remaining_time[i] = 0;
                    completed_processes++;

                    // Calculate turnaround time and waiting time
                    float turnaround_time = total_time - arrival_time[i];
                    float waiting_time = turnaround_time - burst_time[i];

                    cout << "Process[" << i + 1 << "]\t\t" 
                         << burst_time[i] << "\t\t" 
                         << turnaround_time << "\t\t\t" 
                         << waiting_time << endl;

                    wait_time += waiting_time; // Accumulate total waiting time
                } else {
                    remaining_time[i] -= time_quantum;
                    total_time += time_quantum;
                }
            }// end of big if { that searches if there is any process exxecuatbale)
        }    //end of for that iterates through process


        // If no process was found to execute, increment the total time to avoid an infinite loop
        if (!process_found) {
            total_time++;
        }
    }  //end of while

    // Calculate averages
    float average_wait_time = wait_time / limit;
    float average_turnaround_time = total_time / limit;

    cout << "\nAverage Waiting Time: " << average_wait_time;
    cout << "\nAvg Turnaround Time: " << average_turnaround_time << endl;

    return 0;
}



Yes, you are absolutely correct in distinguishing the placement of the turnaround and waiting time calculations in both scheduling algorithms:

Priority Scheduling:

In Priority Scheduling, the turnaround and waiting time calculations happen outside both the for loop and the if statement that check for ready processes.
    
The for loop and if statement are only used to find the highest priority process that’s ready to execute. Once this process is identified and completes its execution, the turnaround and waiting times are calculated only after it has finished, outside the loop and the if condition.
Round Robin Scheduling:



In Round Robin, the turnaround and waiting time calculations occur inside both the for loop and the if condition that checks if a process is ready to execute.
    
Here, each process is allowed to execute only for a fixed time quantum, so these calculations are done immediately after each process’s time slice completes, or when the process finishes entirely. This means the calculations are directly part of the inner for loop, inside the if block that checks if a process can execute in the current cycle.
So, in summary:

Priority Scheduling: Calculations happen outside the for loop and if block.
Round Robin: Calculations happen inside the for loop and if block for each eligible process during each time slice.
