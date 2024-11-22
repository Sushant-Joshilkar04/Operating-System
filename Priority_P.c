
#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
    printf("Enter the number of processes:\n");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], priority[n], rt[n], st[n], ct[n], wt[n], tat[n];
    bool arrived[n], completed[n];

    for (int i = 0; i < n; i++) {
        printf("Enter process id:\n");
        scanf("%d", &pid[i]);
        printf("Enter the arrival time:\n");
        scanf("%d", &at[i]);
        printf("Enter the burst time:\n");
        scanf("%d", &bt[i]);
        printf("Enter the priority:\n");
        scanf("%d", &priority[i]);
        rt[i] = bt[i];
        arrived[i] = false;
        completed[i] = false;
    }

    bool flag = false, processFound;
    int ptenIndex, highestPriority; // Lower number indicates higher priority

    int currentTime = 999;

    for (int i = 0; i < n; i++) {
        if (at[i] < currentTime) {
            currentTime = at[i];
        }
    }

    while (!flag) {
        flag = true;
        processFound = false;
        highestPriority = 999;

        for (int i = 0; i < n; i++) {
            if (completed[i]) {
                continue;
            }

            flag = false;

            if (at[i] <= currentTime) {
                arrived[i] = true;
            }

            if (arrived[i] && priority[i] < highestPriority) {
                highestPriority = priority[i];
                ptenIndex = i;
                processFound = true;
            }

            if (priority[i] == highestPriority && at[i] < at[ptenIndex]) {
                highestPriority = priority[i];
                ptenIndex = i;
                processFound = true;
            }
        }

        if (processFound) {
            if (bt[ptenIndex] == rt[ptenIndex]) {
                st[ptenIndex] = currentTime;
            }

            currentTime++;
            rt[ptenIndex]--;
            if (rt[ptenIndex] == 0) {
                ct[ptenIndex] = currentTime;
                completed[ptenIndex] = true;
                tat[ptenIndex] = ct[ptenIndex] - at[ptenIndex];
                wt[ptenIndex] = tat[ptenIndex] - bt[ptenIndex];
            }
        } else {
            currentTime++;
        }
    }

    printf("Printing the table:\n");
    printf("ProcessId\tAT\tBT\tST\tCT\tWT\tTAT\n");
    int total_WT = 0, total_TAT = 0;
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], st[i], ct[i], wt[i], tat[i]);
        total_WT += wt[i];
        total_TAT += tat[i];
    }

    printf("Average waiting time: %f\nAverage Turn Around Time: %f\n",
           (float)total_WT / n, (float)total_TAT / n);

    return 0;
}
