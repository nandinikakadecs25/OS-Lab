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

    int frame[f];

    for(i = 0; i < f; i++)
        frame[i] = -1;

    int front = 0;

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
            frame[front] = pages[i];
            front = (front + 1) % f;
            pageFaults++;
        }
    }

    printf("Page Faults = %d\n", pageFaults);

    return 0;
}
