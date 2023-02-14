#include <stdio.h>
#include <stdlib.h>
#define max 100
int main()
{
    int p, f, pages[max], size;
    printf("Enter the number of pages and frames: \n");
    scanf("%d%d", &p, &f);
    printf("Enter the size of page/frame: \n");
    scanf("%d", &size);
    for (int i = 0; i < max; i++)
    {
        pages[i] = -1;
    }
    for (int i = 0; i < p; i++)
    {
        printf("Enter the frame no for pages[%d]: \n", i);
        scanf("%d", &pages[i]);
    }
    int state = 0;
    while (state == 0)
    {
        printf("1. Calculate logical address  2. exit: \n");
        int ch;
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            printf("Enter the page number: \n");
            int x;
            scanf("%d", &x);
            printf("Enter the offset value: \n");
            int offset;
            scanf("%d", &offset);
            if (pages[x] == -1)
            {
                printf("Unallocated..\n");
            }
            else
            {
                printf("Logical address: %d\t offset: %d\n", pages[x], offset);
            }
            break;
        }
        case 2:
        {
            state = 1;
        }
        }
    }
}
