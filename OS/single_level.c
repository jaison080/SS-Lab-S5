#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 100
struct directory
{
    int fcount;
    char fname[max][max];
    char dname[max];
} dir;
int main()
{
    char name[max];
    printf("Enter the name of the directory: \n");
    gets(name);
    strcpy(dir.dname, name);
    int state = 0;
    int ch;
    dir.fcount = 0;
    while (state == 0)
    {
        printf("1. add file  2.display files 3.delete 4.exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            printf("Enter the name of the file : \n");
            scanf("%s", name);
            strcpy(dir.fname[dir.fcount], name);
            dir.fcount++;
            printf("File Added..");
            break;
        }
        case 2:
        {
            printf("Files: \n");
            for (int i = 0; i < dir.fcount; i++)
            {
                printf("%s\n", dir.fname[i]);
            }
            break;
        }
        case 3:
        {
            printf("Enter the name of the file to be deleted: \n");
            scanf("%s", name);
            for (int i = 0; i < dir.fcount; i++)
            {
                if (strcmp(name, dir.fname[i]) == 0)
                {
                    strcpy(dir.fname[i], dir.fname[dir.fcount - 1]);
                    break;
                }
            }
            dir.fcount--;
            break;
        }
        case 4:
        {
            state = 1;
            break;
        }
        }
    }
}
