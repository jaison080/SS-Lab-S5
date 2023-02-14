// Scheduling Algorithm

// priority scheduling algorithm

#include <stdio.h>

struct process
{
    int pid;
    int bt;
    int pt;
    int wt;
    int tat;
} p[50];

int main()
{
    // initialize variables
    int n, temp, i, j;

    printf("Please Enter no of processes : ");
    scanf("%d", &n);

    // burst time
    printf("\nPlease Enter Burst Time of processes : \n");
    for (i = 0; i < n; i++)
    {
        printf("P%d : ", i + 1);
        p[i].pid = i + 1;
        scanf("%d", &p[i].bt);
    }

    // priority
    printf("\nPlease Enter Priority of processes : \n");
    for (i = 0; i < n; i++)
    {
        printf("P%d : ", i + 1);
        p[i].pid = i + 1;
        scanf("%d", &p[i].pt);
    }

    // sort
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (p[j].pt > p[j + 1].pt)
            {
                temp = p[j].pid;
                p[j].pid = p[j + 1].pid;
                p[j + 1].pid = temp;

                temp = p[j].bt;
                p[j].bt = p[j + 1].bt;
                p[j + 1].bt = temp;

                temp = p[j].pt;
                p[j].pt = p[j + 1].pt;
                p[j + 1].pt = temp;
            }
        }
    }

    // wt&tat
    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            p[i].wt = 0;
            p[i].tat = p[i].wt + p[i].bt;
            continue;
        }

        p[i].wt = p[i - 1].bt + p[i - 1].wt;
        p[i].tat = p[i].wt + p[i].bt;
    }

    // print
    printf("\nPid\tBT\tPT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].bt, p[i].pt, p[i].wt, p[i].tat);
    }

    // Avg wt
    temp = 0;
    for (i = 0; i < n; i++)
        temp += p[i].wt;
    printf("\ntotal waiting time\t\t:%d\n", temp);
    printf("average waiting time\t\t:%f\n", (float)temp / n);

    // Avg tat
    temp = 0;
    for (i = 0; i < n; i++)
        temp += p[i].tat;
    printf("total turn around time\t\t:%d\n", temp);
    printf("average turn around time\t:%f\n", (float)temp / n);
}