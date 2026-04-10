#include <stdio.h>

int main() {
    int n, tq;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n];
    int ct[n], tat[n], wt[n], response[n];
    int visited[n];

    printf("Enter Arrival Time:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }

    printf("Enter Burst Time:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
        visited[i] = 0;
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int time = 0, completed = 0;

    printf("\nGantt Chart:\n");

    while(completed < n) {
        int done = 1;

        for(int i = 0; i < n; i++) {
            if(rt[i] > 0 && at[i] <= time) {
                done = 0;

                if(visited[i] == 0) {
                    response[i] = time - at[i];
                    visited[i] = 1;
                }

                printf("| P%d ", i+1);

                if(rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    rt[i] = 0;
                    ct[i] = time;
                    completed++;
                }
            }
        }

        if(done == 1) {
            time++;
        }
    }
    printf("|\n");

    float total_wt = 0, total_tat = 0;

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    for(int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        total_tat += tat[i];
        total_wt += wt[i];

        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], ct[i], tat[i], wt[i], response[i]);
    }

    printf("\nAverage Turnaround Time = %.2f", total_tat / n);
    printf("\nAverage Waiting Time = %.2f\n", total_wt / n);

    return 0;
}
