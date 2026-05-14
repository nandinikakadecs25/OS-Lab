#include <stdio.h>

int main() {
    int i, j, k, n, m;
    int alloc[10][10], max[10][10], need[10][10];
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

    printf("Enter Max Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter Available Resources:\n");
    for(i = 0; i < m; i++) {
        scanf("%d", &available[i]);
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    for(i = 0; i < n; i++) {
        finish[i] = 0;
    }

    int count = 0;

    while(count < n) {
        int found = 0;

        for(i = 0; i < n; i++) {
            if(finish[i] == 0) {

                int flag = 1;

                for(j = 0; j < m; j++) {
                    if(need[i][j] > available[j]) {
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
            printf("\nSystem is not in safe state");
            return 0;
        }
    }

    printf("\nSystem is in safe state");
    printf("\nSafe Sequence: ");

    for(i = 0; i < n; i++) {
        printf("P%d ", safeSeq[i]);
    }

    printf("\n\nGantt Chart:\n\n|");

    for(i = 0; i < n; i++) {
        printf("  P%d  |", safeSeq[i]);
    }

    printf("\n");

    return 0;
}
