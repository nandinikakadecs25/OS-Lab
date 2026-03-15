
#include <stdio.h>

int main() {

    int n,i,choice;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    int pid[n],at[n],bt[n];

    for(i=0;i<n;i++){
        pid[i]=i+1;

        printf("P%d Arrival Time: ",i+1);
        scanf("%d",&at[i]);

        printf("P%d Burst Time: ",i+1);
        scanf("%d",&bt[i]);
    }

    printf("\n1. SJF Non Preemptive\n2. SJF Preemptive\nEnter choice: ");
    scanf("%d",&choice);

    switch(choice){



    case 1:{

        int ct[n],tat[n],wt[n],rt[n];
        int completed[n];
        int time=0,done=0,min,idx;

        for(i=0;i<n;i++)
            completed[i]=0;

        printf("\nGantt Chart:\n|");

        while(done<n){

            min=9999;
            idx=-1;

            for(i=0;i<n;i++){
                if(at[i]<=time && completed[i]==0){
                    if(bt[i]<min){
                        min=bt[i];
                        idx=i;
                    }
                }
            }

            if(idx!=-1){

                printf(" P%d |",pid[idx]);

                rt[idx]=time-at[idx];
                time+=bt[idx];

                ct[idx]=time;

                completed[idx]=1;

                done++;
            }

            else
                time++;
        }

        float avgwt=0,avgtat=0,avgrt=0;

        printf("\n\nPID AT BT CT TAT WT RT\n");

        for(i=0;i<n;i++){

            tat[i]=ct[i]-at[i];
            wt[i]=tat[i]-bt[i];

            avgwt+=wt[i];
            avgtat+=tat[i];
            avgrt+=rt[i];

            printf("P%d  %d  %d  %d  %d  %d  %d\n",
            pid[i],at[i],bt[i],ct[i],tat[i],wt[i],rt[i]);
        }

        printf("\nAverage WT = %.2f",avgwt/n);
        printf("\nAverage TAT = %.2f",avgtat/n);
        printf("\nAverage RT = %.2f\n",avgrt/n);

        break;
    }



    case 2:{

        int rt_bt[n],ct[n],tat[n],wt[n],rt[n];
        int time=0,complete=0,min,idx;
        int started[n];

        for(i=0;i<n;i++){
            rt_bt[i]=bt[i];
            started[i]=0;
        }

        printf("\nGantt Chart:\n|");

        while(complete<n){

            min=9999;
            idx=-1;

            for(i=0;i<n;i++){
                if(at[i]<=time && rt_bt[i]>0){
                    if(rt_bt[i]<min){
                        min=rt_bt[i];
                        idx=i;
                    }
                }
            }

            if(idx!=-1){

                printf(" P%d |",pid[idx]);

                if(started[idx]==0){
                    rt[idx]=time-at[idx];
                    started[idx]=1;
                }

                rt_bt[idx]--;
                time++;

                if(rt_bt[idx]==0){
                    ct[idx]=time;
                    complete++;
                }
            }

            else
                time++;
        }

        float avgwt=0,avgtat=0,avgrt=0;

        printf("\n\nPID AT BT CT TAT WT RT\n");

        for(i=0;i<n;i++){

            tat[i]=ct[i]-at[i];
            wt[i]=tat[i]-bt[i];

            avgwt+=wt[i];
            avgtat+=tat[i];
            avgrt+=rt[i];

            printf("P%d  %d  %d  %d  %d  %d  %d\n",
            pid[i],at[i],bt[i],ct[i],tat[i],wt[i],rt[i]);
        }

        printf("\nAverage WT = %.2f",avgwt/n);
        printf("\nAverage TAT = %.2f",avgtat/n);
        printf("\nAverage RT = %.2f\n",avgrt/n);

        break;
    }

    default:
        printf("Invalid Choice");
    }

    return 0;
}
