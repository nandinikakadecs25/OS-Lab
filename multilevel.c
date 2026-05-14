#include <stdio.h>

struct process {
    int pid;
    int bt;
    int wt;
    int tat;
};

int main() {
    int n, i, sys_n = 0, user_n = 0;

    struct process sys[10], user[10];

    printf("Enter total number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        int type;
        printf("\nProcess %d\n", i + 1);
        printf("Enter Burst Time: ");
        int bt;
        scanf("%d", &bt);

        printf("Enter Type (1 = System, 2 = User): ");
        scanf("%d", &type);

        if(type == 1) {
            sys[sys_n].pid = i + 1;
            sys[sys_n].bt = bt;
            sys_n++;
        } else {
            user[user_n].pid = i + 1;
            user[user_n].bt = bt;
            user_n++;
        }
    }

    int time = 0;
    for(i = 0; i < sys_n; i++) {
        sys[i].wt = time;
        time += sys[i].bt;
        sys[i].tat = sys[i].wt + sys[i].bt;
    }

    for(i = 0; i < user_n; i++) {
        user[i].wt = time;
        time += user[i].bt;
        user[i].tat = user[i].wt + user[i].bt;
    }

    printf("\n--- System Processes (Higher Priority) ---\n");
    printf("PID\tBT\tWT\tTAT\n");
    for(i = 0; i < sys_n; i++) {
        printf("%d\t%d\t%d\t%d\n",
               sys[i].pid, sys[i].bt, sys[i].wt, sys[i].tat);
    }

    printf("\n--- User Processes (Lower Priority) ---\n");
    printf("PID\tBT\tWT\tTAT\n");
    for(i = 0; i < user_n; i++) {
        printf("%d\t%d\t%d\t%d\n",
               user[i].pid, user[i].bt, user[i].wt, user[i].tat);
    }
}
