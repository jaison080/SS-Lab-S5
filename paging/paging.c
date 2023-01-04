#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int page_no;
    int frame_no;
} page_table;

int pages, page_size, mem_size;
page_table pg_tab[100];

void input() // To input the data regarding pages, memory size and the page table
{
    printf("Enter the size of the Physical memory(kB): ");
    scanf("%d", &mem_size);

    printf("Enter the size of one page(kB): ");
    scanf("%d", &page_size);

    int frames = mem_size / page_size;
    printf("\nNumber of available frames: %d", frames);

    printf("\nEnter the number of pages: ");
    scanf("%d", &pages);

    if (pages > frames)
    {
        printf("Number of pages cannot exceed the number of frames. Terminating...\n");
        exit(0);
    }

    printf("\nInput the page table. Enter frame no as -1 for unallocated pages.\n");
    printf("Page No.\tFrame No.\n");
    for (int i = 0; i < pages; ++i)
    {
        scanf("%d\t\t%d", &pg_tab[i].page_no, &pg_tab[i].frame_no);
    }
    printf("-------------------------\n");
}

void getPhysicalAddress() // To calculate the physical address
{
    int pg, offset, phy_add, log_add, flag = 0;
    // printf("\nEnter the page number to be used for calculating the logical address: ");
    // scanf("%d", &pg);
    // printf("Enter the offset: ");
    // scanf("%d", &offset);

    printf("\nEnter the Logical Address: ");
    scanf("%d", &log_add);

    pg = log_add / page_size;
    offset = log_add % page_size;
    printf("Page No: %d\t\tOffset: %d", pg, offset);

    if (log_add > mem_size)
    {
        printf("\nLogical Address cannot exceed memory size. Terminating...\n");
        exit(0);
    }

    if (pg > pages)
    {
        printf("\nPage No cannot exceed total number of pages. Terminating...\n");
        exit(0);
    }

    for (int i = 0; i < pages; ++i)
    {
        if (pg_tab[i].page_no == pg)
        {
            if (pg_tab[i].frame_no == -1)
            {
                flag = 1;
                break;
            }
            else
            {
                phy_add = pg_tab[pg].frame_no * page_size + offset;
                break;
            }
        }
    }

    if (flag == 0)
        printf("\nThe Physical Address corresponding to the given logical address is: %d\n", phy_add);
    else
        printf("\nThe page hasn't yet been allocated in memory yet.\n");
}

void main()
{
    input();
    getPhysicalAddress();
}