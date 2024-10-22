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
            if (remaining_time[i] > 0 && arrival_time[i] <= total_time) {
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
            }
        }
        // If no process was found to execute, increment the total time to avoid an infinite loop
        if (!process_found) {
            total_time++;
        }
    }

    // Calculate averages
    float average_wait_time = wait_time / limit;
    float average_turnaround_time = total_time / limit;

    cout << "\nAverage Waiting Time: " << average_wait_time;
    cout << "\nAvg Turnaround Time: " << average_turnaround_time << endl;

    return 0;
}
