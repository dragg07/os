#include <stdio.h>

void findWaitingTime(int process[], int n, int bt[], int wt[], int quantum) {
    int remaining_burst_time[n];
    for (int i = 0; i < n; i++)
        remaining_burst_time[i] = bt[i];

    int t = 0;
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (remaining_burst_time[i] > 0) {
                done = 0; 

                if (remaining_burst_time[i] > quantum) {
                    t += quantum;
                    remaining_burst_time[i] -= quantum;
                } else {
                    t += remaining_burst_time[i];
                    wt[i] = t - bt[i];
                    remaining_burst_time[i] = 0;
                }
            }
        }
        if (done == 1)
            break;
    }
}

void findTurnAroundTime(int process[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

void findAverageTime(int process[], int n, int bt[], int quantum) {
    int wt[n], tat[n];
    int total_wt = 0, total_tat = 0;

    findWaitingTime(process, n, bt, wt, quantum);
    findTurnAroundTime(process, n, bt, wt, tat);
    printf("process   Burst time   Waiting time   Turnaround time\n");

    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("   %d ", i + 1);
        printf("         %d ", bt[i]);
        printf("          %d ", wt[i]);
        printf("            %d\n", tat[i]);
    }

    printf("\nAverage waiting time = %.2f", (float)total_wt / (float)n);
    printf("\nAverage turnaround time = %.2f\n", (float)total_tat / (float)n);
}

int main() {
    int n;
    printf("Enter no. of process : ");
    scanf("%d", &n);
    int process[n];

    for(int i=0; i<n; i++){
        process[i] = i+1;
    }

    int burst_time[n];
    printf("Enter burst time for the processes: \n");
    for(int i=0; i<n; i++){
        printf("P[%d] : ", i+1);
        scanf("%d",&burst_time[i]);
    }
    int quantum = 2;

    findAverageTime(process, n, burst_time, quantum);
    return 0;
}
