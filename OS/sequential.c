#include <stdio.h>
#include <stdlib.h>
#define max 100

int main()
{
    int n, f[max], bno, state = 0, sta, length;
    for (int i = 0; i < max; i++)
    {
        f[i] = 0;
    }
    printf("Enter the number of blocks which are already allocated: \n");
    scanf("%d", &n);
    printf("Enter the blocks which are already allocated: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &bno);
        f[bno] = 1;
    }
    while (state == 0)
    {
    a:
        printf("Enter the start address and length of the file: \n");
        scanf("%d%d", &sta, &length);
        if (f[sta] == 0)
        {
            for (int k = sta; k < (length + sta); k++)
            {
                if (f[k] == 1)
                {
                    printf("Already allocated...");
                    goto b;
                    break;
                }
                else
                {
                    f[k] = 1;
                    printf("%d--->%d", k, f[k]);
                }
            }
        }
        else
        {
            printf("cannot allocate..\n");
            goto b;
        }

    b:
        printf("1. countinue add files 2. exit\n");
        int ch;
        scanf("%d", &ch);
        if (ch == 1)
        {
            goto a;
            continue;
        }
        else if (ch == 2)
        {
            break;
            state = 1;
        }
        else
        {
            printf("Enter valid choice..");
            goto b;
        }
    }
}