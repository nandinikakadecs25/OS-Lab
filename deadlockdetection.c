
#include <stdio.h>

int main() {
    int n, m, i, j, k;
    int alloc[10][10], request[10][10];
    int available[10], finish[10], safeSeq[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    printf("Enter Allocation Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter Request Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &request[i][j]);
        }
    }

    printf("Enter Available Resources:\n");
    for(i = 0; i < m; i++) {
        scanf("%d", &available[i]);
    }

    for(i = 0; i < n; i++) {
        finish[i] = 0;

        int sum = 0;

        for(j = 0; j < m; j++) {
            sum += alloc[i][j];
        }

        if(sum == 0) {
            finish[i] = 1;
        }
    }

    int count = 0;

    while(count < n) {
        int found = 0;

        for(i = 0; i < n; i++) {
            if(finish[i] == 0) {

                int flag = 1;

                for(j = 0; j < m; j++) {
                    if(request[i][j] > available[j]) {
                        flag = 0;
                        break;
                    }
                }

                if(flag == 1) {
                    for(k = 0; k < m; k++) {
                        available[k] += alloc[i][k];
                    }

                    safeSeq[count] = i;
                    count++;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0) {
            break;
        }
    }

    int deadlock = 0;

    for(i = 0; i < n; i++) {
        if(finish[i] == 0) {
            deadlock = 1;
            printf("\nProcess P%d is in Deadlock", i);
        }
    }

    if(deadlock == 0) {
        printf("\nNo Deadlock Detected");

        printf("\nSafe Sequence: ");
        for(i = 0; i < count; i++) {
            printf("P%d ", safeSeq[i]);
        }

        printf("\n\nGantt Chart:\n\n|");

        for(i = 0; i < count; i++) {
            printf("  P%d  |", safeSeq[i]);
        }

        printf("\n");
    }

    return 0;
}
