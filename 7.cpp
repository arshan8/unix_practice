//priority 


#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int limit, completed_processes = 0;
    float total_time = 0, wait_time = 0, arrival_time[10], burst_time[10], remaining_time[10], turnaround_time[10], priority[10];

    cout << "Enter Total Number of Processes: ";
    cin >> limit;

    for (int i = 0; i < limit; i++) {
        cout << "\nEnter Arrival Time for Process[" << i + 1 << "]: ";
        cin >> arrival_time[i];
        cout << "Enter Burst Time for Process[" << i + 1 << "]: ";
        cin >> burst_time[i];
        cout << "Enter Priority for Process[" << i + 1 << "]: ";
        cin >> priority[i];
        remaining_time[i] = burst_time[i]; // Initialize remaining time
    }

    cout << "\nProcess ID\tBurst Time\tPriority\tTurnaround Time\tWaiting Time\n";

    // Priority Scheduling
    while (completed_processes < limit) {
        int idx = -1;
        float highest_priority = 9999; // Initialize with a large number

        // Find the highest priority process that has arrived and is remaining
        for (int i = 0; i < limit; i++) {
            if (remaining_time[i] > 0 && arrival_time[i] <= total_time) {
                if (priority[i] < highest_priority) { // Lower number means higher priority
                    highest_priority = priority[i];
                    idx = i; // Track the index of the highest priority process
                }
            }
        }

        // If we found a process to execute
        if (idx != -1) {
            total_time += remaining_time[idx]; // Increment total time by the burst time
            remaining_time[idx] = 0; // Mark process as completed
            completed_processes++;

            turnaround_time[idx] = total_time - arrival_time[idx]; // Calculate turnaround time
            float waiting_time = turnaround_time[idx] - burst_time[idx]; // Calculate waiting time

            cout << "Process[" << idx + 1 << "]\t\t" 
                 << burst_time[idx] << "\t\t" 
                 << priority[idx] << "\t\t" 
                 << turnaround_time[idx] << "\t\t\t" 
                 << waiting_time << endl;

            wait_time += waiting_time; // Accumulate total waiting time
        } else {
            // If no process is found, increment total time
            total_time++;
        }
    }

    // Calculate averages
    float average_wait_time = wait_time / limit;
    float average_turnaround_time = total_time / limit; // Use total_time for TAT

    cout << "\nAverage Waiting Time: " << average_wait_time;
    cout << "\nAvg Turnaround Time: " << average_turnaround_time << endl;

    return 0;
}
