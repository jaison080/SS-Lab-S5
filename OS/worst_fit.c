#include <stdio.h>
int block[20], process[20], isAllocated[20] = {0}, allocated[20], b, p, choice, flag = 0;
void worstFit();
int bwFinder(int startIndex, int pSize, int curValue);
void display();
void worstFit()
{
    for (int i = 0; i < b; i++)
    {
        isAllocated[i] = 0;
    }
    for (int i = 0; i < p; i++)
    {
        int big = 0;
        for (int j = 0; j < b; j++)
        {
            if (process[i] <= block[j] && isAllocated[j] != 1)
            {
                big = block[j];
                isAllocated[j] = 1;
                big = bwFinder(j, process[i], big);
                allocated[i] = big;
                break;
            }
        }
        if (big == 0)
        {
            allocated[i] = -999;
        }
    }
    display();
}
int bwFinder(int startIndex, int pSize, int curValue)
{
    int lastBlock = startIndex;
    for (int i = startIndex + 1; i < b; i++)
    {
        if (pSize <= block[i] && block[i] > curValue && isAllocated[i] != 1)
        {
            isAllocated[lastBlock] = 0;
            lastBlock = i;
            curValue = block[i];
            isAllocated[i] = 1;
        }
    }
    return curValue;
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
    worstFit();
}