// shortest job first scheduling algorithm

#include <stdio.h>

struct process
{
	int pid;
	int bt;
	int wt;
	int tat;
} p[50];

int main()
{
	// initialize variables
	int n, temp, i, j;

	printf("Please Enter no of processes : ");
	scanf("%d", &n);

	printf("\nPlease Enter Burst Time of processes : \n");
	for (i = 0; i < n; i++)
	{
		printf("P%d : ", i + 1);
		p[i].pid = i + 1;
		scanf("%d", &p[i].bt);
	}

	// sort
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - 1; j++)
		{
			if (p[j].bt > p[j + 1].bt)
			{
				temp = p[j].pid;
				p[j].pid = p[j + 1].pid;
				p[j + 1].pid = temp;

				temp = p[j].bt;
				p[j].bt = p[j + 1].bt;
				p[j + 1].bt = temp;
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
