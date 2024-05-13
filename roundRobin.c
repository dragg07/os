#include<stdio.h>

void findWaitingTime(int processes[], int n, int bt[], int wt[], int quantum, int execution_order[]) {
    int rem_bt[n];
    for (int i = 0; i < n; i++)
        rem_bt[i] = bt[i];

    int t = 0;
    int index = 0; // Index for execution order
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = 0;

                if (rem_bt[i] > quantum) {
                    t += quantum;

                    rem_bt[i] -= quantum;
                } else {
                    t = t + rem_bt[i];

                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;

                    // Store the process number in the execution order array
                    execution_order[index++] = processes[i];
                }
            }
        }

        if (done == 1)
            break;
    }
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

void findavgTime(int processes[], int n, int bt[], int quantum) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    int execution_order[n]; // Array to store the execution order

    findWaitingTime(processes, n, bt, wt, quantum, execution_order);

    findTurnAroundTime(processes, n, bt, wt, tat);

    printf("PN\tBT\tWT\tTAT\n");

    for (int i = 0; i < n; i++) {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("%d\t%d\t%d\t%d\n", processes[i], bt[i], wt[i], tat[i]);
    }

    printf("Average waiting time = %.2f\n", (float)total_wt / (float)n);
    printf("Average turn around time = %.2f\n", (float)total_tat / (float)n);

    // Print the execution order
    printf("Execution order: ");
    for (int i = 0; i < n; i++) {
        printf("%d", execution_order[i]);
        if (i < n - 1)
            printf(" -> ");
    }
}

// Driver code
int main() {
    int processes[] = {1, 2, 3, 4, 5};
    int n = sizeof processes / sizeof processes[0];

    int burst_time[] = {20, 6, 18, 40, 30};

    int quantum = 4;
    findavgTime(processes, n, burst_time, quantum);
    return 0;
}
