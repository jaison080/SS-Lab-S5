#include <stdio.h>
int block[20], process[20], isAllocated[20] = {0}, allocated[20], b, p, choice, flag = 0;
void firstFit();
void display();
int main()
{
    printf("Enter the number of blocks : ");
    scanf("%d", &b);
    printf("Enter the size of each block\n");
    for (int i = 0; i < b; i++)
    {
        printf("B%d : ", i);
        scanf("%d", &block[i]);
    }
    printf("Enter the number of process : ");
    scanf("%d", &p);
    printf("Enter the size of each process\n");
    for (int i = 0; i < p; i++)
    {
        printf("P%d : ", i);
        scanf("%d", &process[i]);
    }
    firstFit();
}
void display()
{
    printf("\nProcess\t\tProcess size\t\tBlock Allocated\n");
    for (int i = 0; i < p; i++)
    {
        if (allocated[i] == -999)
        {
            printf("%d\t\t%d\t\t\tNot allocated", i, process[i]);
            printf("\n");
        }
        else
        {
            printf("%d\t\t%d\t\t\t%d", i, process[i], allocated[i]);
            printf("\n");
        }
    }
}
void firstFit()
{
    for (int i = 0; i < b; i++)
    {
        isAllocated[i] = 0;
    }
    for (int i = 0; i < p; i++)
    {
        flag = 0;
        for (int j = 0; j < b; j++)
        {
            if (process[i] <= block[j] && isAllocated[j] == 0)
            {
                allocated[i] = block[j];
                isAllocated[j] = 1;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            allocated[i] = -999;
        }
    }
    display();
}