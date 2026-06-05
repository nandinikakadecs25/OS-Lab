#include <stdio.h>

int main()
{
    int n, f, i, j, pageFaults = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    int pages[n];

    printf("Enter page reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    int frame[f], time[f];

    for(i = 0; i < f; i++)
    {
        frame[i] = -1;
        time[i] = 0;
    }

    int counter = 0;

    for(i = 0; i < n; i++)
    {
        counter++;
        int found = 0;

        for(j = 0; j < f; j++)
        {
            if(frame[j] == pages[i])
            {
                time[j] = counter;
                found = 1;
                break;
            }
        }

        if(!found)
        {
            int pos = 0;

            for(j = 1; j < f; j++)
            {
                if(time[j] < time[pos])
                    pos = j;
            }

            frame[pos] = pages[i];
            time[pos] = counter;
            pageFaults++;
        }
    }

    printf("Page Faults = %d\n", pageFaults);

    return 0;
}
