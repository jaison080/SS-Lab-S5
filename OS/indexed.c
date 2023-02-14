#include <stdio.h>
#include <stdlib.h>
#define max 100
struct file
{
    int no_of_blocks, length, start_address;
    int blocks[max];
} f[max];
int main()
{
    int n;
    printf("Enter the number of files to be added: \n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the start address of file[%d]: \n", i);
        scanf("%d", &f[i].start_address);
        printf("Enter the length of the file[%d]: \n", i);
        scanf("%d", &f[i].length);
        printf("Enter the number of blocks of file[%d]: \n", i);
        scanf("%d", &f[i].no_of_blocks);
        printf("Enter the blocks allocated: \n");
        for (int j = 0; j < f[i].no_of_blocks; j++)
        {
            scanf("%d", &f[i].blocks[j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("file no: %d\tno of blocks: %d\tlength:%d\tstart addr:%d\n", i, f[i].no_of_blocks, f[i].length, f[i].start_address);
    }
    int state = 0;
    while (state == 0)
    {
        int ch;
        printf("1.Get the blocks 2. exit");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            printf("Enter the file number: \n");
            int m;
            scanf("%d", &m);
            printf("Blocks allocated: ");
            for (int i = 0; i < f[m].no_of_blocks; i++)
            {
                printf("%d\t", f[m].blocks[i]);
            }
            break;
        }
        case 2:
        {
            state = 1;
            break;
        }
        }
    }
}
