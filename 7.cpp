#include <iostream>
using namespace std;

int main() {
    int priority[10], arrive[10], burst[10], remain[10];
    int limit;
    cout << "enter total process" << endl;
    cin >> limit;

    for (int i = 1; i <= limit; i++) {
        cout << "enter process " << i << " details" << endl;
        cout << "enter arrive time:" << endl;
        cin >> arrive[i];
        cout << "enter burst time:" << endl;
        cin >> burst[i];
        remain[i] = burst[i];
        cout << "enter priotiy:" << endl;
        cin >> priority[i];
    }

    int complete = 0;
    int total = 0;
    int waiting_total = 0;

    while (complete < limit) {
        int idx = -1;
        int high = 999;

        for (int i = 1; i <= limit; i++) {
            if (remain[i] > 0 && arrive[i] <= total) {
                if (priority[i] < high) {
                    high = priority[i];
                    idx = i;
                }
            }
        }                                        //end of for loop

        if (idx != -1) {
            total += remain[idx];
            remain[idx] = 0;
            complete++;

            float total_turnaround = total - arrive[idx];
            float wait_time = total_turnaround - burst[idx];

            waiting_total += wait_time;
            cout << " turn around " << total_turnaround << " wait " << wait_time
                 << " arrived at " << arrive[idx] << " for process " << idx << endl;
        } else {
            total += 1;
        }
    }  //end of while

    cout << " average turnaround time " << total / limit << endl;
    cout << " average waiting time " << waiting_total / limit << endl;

    return 0;
}
