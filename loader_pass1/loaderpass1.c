/*Credits : Achyuth Mohan (https;??github.com/AchyuthMohan)*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 40

struct estab
{
    char csname[20], extsymbol[20];
    int address, length;
} es[max];
FILE *fp, *fpo;
char input[20];
char name[max];
int add;
int count = 0, csaddr, len;
int main()
{

    fp = fopen("input.txt", "r");
    fpo = fopen("output.txt", "w");
    fscanf(fp, "%s", input);
    printf("Enter the staring address: \n");
    scanf("%d", &csaddr);
    while (strcmp(input, "END") != 0)
    {
        if (strcmp(input, "H") == 0)
        {

            fscanf(fp, "%s", name);
            strcpy(es[count].csname, name);
            fscanf(fp, "%d", &add);
            es[count].address = csaddr + add;
            strcpy(es[count].extsymbol, "***");
            fscanf(fp, "%d", &len);
            es[count].length = len;
            count++;
        }
        else if (strcmp(input, "D") == 0)
        {
            while (strcmp(input, "R") != 0 && strcmp(input, "T") != 0)
            {
                fscanf(fp, "%s", name);
                strcpy(es[count].extsymbol, name);
                strcpy(es[count].csname, "***");
                fscanf(fp, "%d", &add);
                es[count].address = csaddr + add;
                es[count].length = 0;
                count++;
                fscanf(fp, "%s", input);
            }
            csaddr = csaddr + len;
        }
        fscanf(fp, "%s", input);
    }
    for (int i = 0; i < count; i++)
    {
        fprintf(fpo, "%s\t%s\t%d\t%d\n", es[i].csname, es[i].extsymbol, es[i].address, es[i].length);
    }
    return 0;
}