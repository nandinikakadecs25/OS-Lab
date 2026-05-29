#include<stdio.h>

int main()
{
    int b[20],p[20],allocation[20];
    int nb,np,i,j;

    printf("Enter number of memory blocks: ");
    scanf("%d",&nb);

    printf("Enter number of processes: ");
    scanf("%d",&np);

    printf("Enter block sizes:\n");
    for(i=0;i<nb;i++)
        scanf("%d",&b[i]);

    printf("Enter process sizes:\n");
    for(i=0;i<np;i++)
        scanf("%d",&p[i]);

    for(i=0;i<np;i++)
        allocation[i]=-1;

    for(i=0;i<np;i++)
    {
        for(j=0;j<nb;j++)
        {
            if(b[j]>=p[i])
            {
                allocation[i]=j;
                b[j]-=p[i];
                break;
            }
        }
    }

    printf("\nProcess No\tProcess Size\tBlock No\n");
    for(i=0;i<np;i++)
    {
        printf("%d\t\t%d\t\t",i+1,p[i]);
        if(allocation[i]!=-1)
            printf("%d\n",allocation[i]+1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
