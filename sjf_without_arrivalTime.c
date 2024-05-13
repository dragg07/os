// SJF

#include <stdio.h>
#define max 30

int main() {
    int i, j, n, bt[max], wt[max], tat[max], p[max], t;
    float awt = 0, atat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst time of the processes:\n");
    for (i = 0; i < n; i++) {
        printf("Burst time of P%d: ", i + 1);
        scanf("%d", &bt[i]);
        p[i] = i + 1; 
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (bt[i] > bt[j]) {
                t = bt[i];
                bt[i] = bt[j];
                bt[j] = t;
                t = p[i];
                p[i] = p[j];
                p[j] = t;
            }
        }
    }

    wt[0] = 0;
    tat[0] = bt[0];
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
        awt += wt[i];
        atat += tat[i];
    }

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }



    awt /= n;
    atat /= n;
    printf("Average waiting time: %f\n", awt);
    printf("Average turnaround time: %f\n", atat);

    return 0;
}
