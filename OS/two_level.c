#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100

struct directory
{
    char dname[max];
    int fcount;
    char fname[max][max];
} dir[max];
int main()
{
    int n = 0, state = 0, ch;
    char name[max], file_name[max];
    while (state == 0)
    {
        printf("1.Create a directory 2. insert file 3.delete directory 4.exit: \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            printf("Enter the name of the diretory: \n");
            scanf("%s", name);
            strcpy(dir[n].dname, name);
            n++;
            break;
        }
        case 2:
        {
            printf("Enter the name of the directory:  \n");
            scanf("%s", name);
            printf("Enter the name of the file: \n");
            scanf("%s", file_name);
            int flag = 0;
            for (int i = 0; i < n; i++)
            {
                if (strcmp(dir[i].dname, name) == 0)
                {
                    strcpy(dir[i].fname[dir[i].fcount], file_name);
                    dir[i].fcount++;
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                printf("Error");
            }
            break;
        }
        case 3:
        {
            printf("Enter the name of the directory: \n");
            scanf("%s", name);
            for (int i = 0; i < n; i++)
            {
                if (strcmp(dir[i].dname, name) == 0)
                {
                    strcpy(dir[i].dname, dir[n - 1].dname);
                    n--;
                    break;
                }
            }
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