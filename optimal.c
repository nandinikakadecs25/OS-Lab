#include <stdio.h>

int main()
{
    int n, f, i, j, k, pageFaults = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    int pages[n];

    printf("Enter page reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    int frame[f];

    for(i = 0; i < f; i++)
        frame[i] = -1;

    for(i = 0; i < n; i++)
    {
        int found = 0;

        for(j = 0; j < f; j++)
        {
            if(frame[j] == pages[i])
            {
                found = 1;
                break;
            }
        }

        if(!found)
        {
            int pos = -1;

            for(j = 0; j < f; j++)
            {
                if(frame[j] == -1)
                {
                    pos = j;
                    break;
                }
            }

            if(pos == -1)
            {
                int farthest = -1;

                for(j = 0; j < f; j++)
                {
                    int nextUse = n;

                    for(k = i + 1; k < n; k++)
                    {
                        if(frame[j] == pages[k])
                        {
                            nextUse = k;
                            break;
                        }
                    }

                    if(nextUse > farthest)
                    {
                        farthest = nextUse;
                        pos = j;
                    }
                }
            }

            frame[pos] = pages[i];
            pageFaults++;
        }
    }

    printf("Page Faults = %d\n", pageFaults);

    return 0;
}
