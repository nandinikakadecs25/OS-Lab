
#include <stdio.h>

struct process {
    int pid;
    int at;   // Arrival Time
    int bt;   // Burst Time
    int pr;   // Priority
    int ct;   // Completion Time
    int wt;   // Waiting Time
    int tat;  // Turnaround Time
    int done; // Process completed or not
};

int main() {
    int n, i, completed = 0, time = 0, highest;
    struct process p[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input
    for(i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter AT, BT, Priority for Process %d: ", p[i].pid);
        scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].pr);
        p[i].done = 0;
    }

    while(completed < n) {
        highest = -1;

        // Find highest priority process among arrived
        for(i = 0; i < n; i++) {
            if(p[i].at <= time && p[i].done == 0) {
                if(highest == -1 || p[i].pr < p[highest].pr) {
                    highest = i;
                }
            }
        }

        if(highest != -1) {
            time += p[highest].bt;
            p[highest].ct = time;
            p[highest].tat = p[highest].ct - p[highest].at;
            p[highest].wt = p[highest].tat - p[highest].bt;
            p[highest].done = 1;
            completed++;
        } else {
            time++; // CPU idle
        }
    }

    // Output
    printf("\nPID\tAT\tBT\tPR\tCT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt, p[i].pr,
               p[i].ct, p[i].wt, p[i].tat);
    }

    return 0;
}
