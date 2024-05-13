#include<stdio.h>

struct Process {
    int id;
    int burst_time;
    int priority;
};

void priorityScheduling(struct Process proc[], int n) {
    int waiting_time[n], turnaround_time[n], total_waiting_time = 0, total_turnaround_time = 0;
    float average_waiting_time, average_turnaround_time;

    waiting_time[0] = 0;

    for (int i = 1; i < n; i++) {
        waiting_time[i] = waiting_time[i - 1] + proc[i - 1].burst_time;
        total_waiting_time += waiting_time[i];
    }

    for (int i = 0; i < n; i++) {
        turnaround_time[i] = waiting_time[i] + proc[i].burst_time;
        total_turnaround_time += turnaround_time[i];
    }

    average_waiting_time = (float)total_waiting_time / n;
    average_turnaround_time = (float)total_turnaround_time / n;

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", proc[i].id, proc[i].burst_time, waiting_time[i], turnaround_time[i]);
    }

    printf("\nAverage Waiting Time: %.2f", average_waiting_time);
    printf("\nAverage Turnaround Time: %.2f\n", average_turnaround_time);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];
    printf("Enter burst time and priority for each process:\n");
    for (int i = 0; i < n; i++) {
        proc[i].id = i + 1;
        printf("Process %d: ", i + 1);
        scanf("%d %d", &proc[i].burst_time, &proc[i].priority);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (proc[i].priority < proc[j].priority) {
                struct Process temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }

    priorityScheduling(proc, n);

    return 0;
}
