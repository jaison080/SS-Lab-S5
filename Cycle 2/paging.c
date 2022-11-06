#include <stdio.h>
int main()
{
    int mem_size, pag_size, pages, process, rempages, i, j, x, y, phy_add, offset;
    int s[10], frame_no[10][20];
    printf("\nEnter the memory size : ");
    scanf("%d", &mem_size);
    printf("\nEnter the page size : ");
    scanf("%d", &pag_size);
    pages = mem_size / pag_size;
    printf("\nNo: of pages in Memory : %d ", pages);
    printf("\nEnter number of processes : ");
    scanf("%d", &process);
    rempages = pages;
    for (i = 1; i <= process; i++)
    {
        printf("\nEnter no. of pages required for p[%d] : ", i);
        scanf("%d", &s[i]);
        if (s[i] > rempages)
        {
            printf("\nMemory is Full");
            break;
        }
        rempages = rempages - s[i];
        printf("\nEnter pagetable for p[%d]\n", i);
        for (j = 0; j < s[i]; j++)
            scanf("%d", &frame_no[i][j]);
    }
    printf("\n\nEnter Logical Address to find Physical Address.\n");
    printf("\nEnter Process No. : ");
    scanf("%d", &x);
    printf("\nEnter Page Number : ");
    scanf("%d", &y);
    printf("\nEnter Offset : ");
    scanf("%d", &offset);
    if (x > process || y >= s[i] || offset >= pag_size)
        printf("\nInvalid Process or Page Number or offset");
    else
    {
        phy_add = frame_no[x][y] * pag_size + offset;
        printf("\nPhysical Address : %d\n", phy_add);
    }
    return 0;
}