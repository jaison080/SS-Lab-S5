// Scheduling Algorithm

// Round robin scheduling algorithm

#include <stdio.h>

struct process
{
    int pid;
    int bt;
    int wt;
    int tat;
    int rt;
} p[50];

int main()
{
    // initialize variables
    int n, Q, temp, i, j, flag;

    printf("Please Enter Quanta of processes : ");
    scanf("%d", &Q);

    printf("Please Enter no of processes : ");
    scanf("%d", &n);

    printf("\nPlease Enter Burst Time of processes : \n");
    for (i = 0; i < n; i++)
    {
        printf("P%d : ", i + 1);
        p[i].pid = i + 1;
        scanf("%d", &p[i].bt);

        // remaining time
        p[i].rt = p[i].bt;
        p[i].wt = -Q;
    }

    flag = 1;
    temp = 0;

    while (1)
    {
        if (flag == 0)
        {
            break;
        }
        flag = 0;

        // wt
        for (i = 0; i < n; i++)
        {
            if (p[i].rt == 0)
            {
                continue;
            }

            if (p[i].rt < Q)
            {
                p[i].wt = p[temp].wt + p[i].rt % Q;
                p[i].rt = 0;
            }
            else
            {
                p[i].wt = p[temp].wt + Q;
                p[i].rt -= Q;
            }

            temp = i;
            flag = 1;
        }
    }

    // tat
    for (i = 0; i < n; i++)
    {
        p[i].tat = p[i].wt + p[i].bt;
    }

    // print
    printf("\nPid\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\n", p[i].pid, p[i].bt, p[i].wt, p[i].tat);
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
