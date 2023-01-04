/*Credits : Achyuth Mohan (https;??github.com/AchyuthMohan)*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    FILE *fp, *fp1;
    fp = fopen("input.txt", "r");
    fp1 = fopen("output.txt", "w");
    char name[20], line[30];
    fscanf(fp, "%s", line);
    int k = 0;
    if (line[0] == 'H')
    {
        for (int i = 2; line[i] != '^'; i++)
        {
            name[k++] = line[i];
        }
    }
    char startaddr[20];
    int sta;
    int i, j;
    printf("The name of the program is %s", name);
    fscanf(fp, "%s", line);
    while (!feof(fp))
    {
        while (line[0] == 'T')
        {
            for (i = 2, j = 0; line[i] != '^'; i++, j++)
            {
                startaddr[j] = line[i];
            }
            sta = atoi(startaddr);
            i = 12;
            while (line[i] != '$')
            {
                if (line[i] != '^')
                {
                    fprintf(fp1, "%d\t%c\t%c\n", sta, line[i], line[i + 1]);
                    i = i + 2;
                    sta++;
                }
                else
                {
                    i++;
                }
            }
            fscanf(fp, "%s", line);
        }
    }
}