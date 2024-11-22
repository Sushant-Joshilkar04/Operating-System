#include<stdio.h>
#include<stdbool.h>

// Function to display the process details
void display(int n, int pid[], int at[], int bt[], int st[], int et[], int wt[], int tat[], int remaining_bt[]) {
    printf("PID   Arrival  Burst  Remaining  Start    End   Waiting  Turnaround\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t %d\t %d\t %d\t %d\t %d\t %d\t %d\n", 
               pid[i], at[i], bt[i], remaining_bt[i], st[i], et[i], wt[i], tat[i]);
    }
}

// Function to calculate Round Robin scheduling
void answer(int n, int pid[], int at[], int bt[], int quantum) {
    int remaining_bt[n], st[n], et[n], wt[n], tat[n];
    bool is_completed[n]; 

    // Initialize arrays
    for (int i = 0; i < n; i++) {
        remaining_bt[i] = bt[i];
        st[i] = -1; // Indicates not started yet
        et[i] = 0;
        wt[i] = 0;
        tat[i] = 0;
        is_completed[i] = false;
    }

    int current_time = 0, completed = 0;
    float avgWt = 0, avgTat = 0;

    // Main Round Robin loop
    while (completed < n) {
        bool process_found = false;
        for (int i = 0; i < n; i++) {
            if (remaining_bt[i] > 0 && at[i] <= current_time) {
                process_found = true;
                
                // Start time is set when the process starts executing for the first time
                if (st[i] == -1) {
                    st[i] = current_time;
                }

                if (remaining_bt[i] <= quantum) {
                    current_time += remaining_bt[i];
                    remaining_bt[i] = 0;
                    et[i] = current_time;

                    // Calculate Turnaround and Waiting Times
                    tat[i] = et[i] - at[i];
                    wt[i] = tat[i] - bt[i];
                    avgWt += wt[i];
                    avgTat += tat[i];
                    completed++;
                } else {
                    current_time += quantum;
                    remaining_bt[i] -= quantum;
                }
            }
        }

        if (!process_found) {
            current_time++; // If no process is available, increment time
        }
    }

    // Display results
    display(n, pid, at, bt, st, et, wt, tat, remaining_bt);
    printf("\nAverage Waiting Time -> %.2f\n", avgWt / n);
    printf("Average Turnaround Time -> %.2f\n", avgTat / n);
}

int main() {
    int n, quantum;

    printf("Enter number of processors: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n];

    printf("Enter PID, Arrival Time, and Burst Time\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &pid[i], &at[i], &bt[i]);
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &quantum);

    answer(n, pid, at, bt, quantum);

    return 0;
}
