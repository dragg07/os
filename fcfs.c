#include<stdio.h>

int main(){
    int n, bt[30], at[30], ct[30], wt[30], tat[30], avwt = 0, avtat = 0, i, j;
    avwt = 0;
    avtat = 0;

    printf("Enter number of processes\n");
    scanf("%d", &n);

    printf("The burst time for processes\n");
    for(i = 0; i < n; i++){
        printf("P[%d]", i + 1);
        scanf("%d", &bt[i]);
    }

    printf("The Arrival time for processes\n");
    for(i = 0; i < n; i++){
        printf("P[%d]", i + 1);
        scanf("%d", &at[i]);
    }

    // Calculate completion time
    ct[0] = at[0] + bt[0];
    for (i = 1; i < n; i++) {
        if (at[i] > ct[i - 1]) {
            ct[i] = at[i] + bt[i];
        } else {
            ct[i] = ct[i - 1] + bt[i];
        }
    }

    for(i = 0; i < n; i++){
        tat[i] = ct[i] - at[i]; 
        wt[i] = tat[i] - bt[i];
        avwt = avwt + wt[i];
        avtat = avtat + tat[i];
    }

    printf("\n Process, arrival time, burst time, completion time, waiting time, turn around time");
    for(i = 0; i < n; i++){
        printf("\nP[%d] %d\t %d\t %d\t %d\t %d\t", i + 1, at[i], bt[i], ct[i], wt[i], tat[i]);
    }
    avwt = avwt / n;
    avtat = avtat / n;
    printf("\nAverage waiting time=%d", avwt);
    printf("\nAverage turn around time=%d", avtat);
    return 0;
}
