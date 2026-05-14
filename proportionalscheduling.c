#include <stdio.h>

int main() {
    int n, i;
    int burst[10], priority[10];
    int total = 0, time = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter burst time and priority of process %d: ", i + 1);
        scanf("%d%d", &burst[i], &priority[i]);
        total += priority[i];
    }

    printf("\nProcess\tBurst Time\tPriority\tCPU Share\n");

    for(i = 0; i < n; i++) {
        float share = ((float)priority[i] / total) * 100;
        printf("P%d\t%d\t\t%d\t\t%.2f%%\n",
               i + 1, burst[i], priority[i], share);
    }

    printf("\nGantt Chart:\n\n|");

    for(i = 0; i < n; i++) {
        printf("  P%d  |", i + 1);
    }

    printf("\n0");

    for(i = 0; i < n; i++) {
        time += burst[i];
        printf("\t%d", time);
    }

    return 0;
}
