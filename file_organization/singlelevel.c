#include<stdio.h>
#include<string.h>
#include <stdlib.h>
struct 
{
	char dname[10];
	char fname[10][10];
	int fcnt;
}dir;
void main()
{
	int i,ch;
	char f[30];
	dir.fcnt=0;
	printf("Enter Directory Name : ");
	scanf("%s",dir.dname);
	while(1)
	{
		printf("\n\n1.Create File\n");
		printf("2.Delete File\n");
		printf("3.Search File\n");
		printf("4.Display File\n");
		printf("5.Exit\n");
		printf("Enter Your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 :
			{
				printf("Enter the name of the file : ");
				scanf("%s",f);
				for(i=0;i<dir.fcnt;i++)
				{
					if(strcmp(f,dir.fname[i])==0)
					{
						printf("File %s already exists at %s/%s.\n",f,dir.dname,f);
						break;
					}
				}
				if(i==dir.fcnt)
				{
					strcpy(dir.fname[dir.fcnt],f);
					dir.fcnt++;
				}
				break;			
			}
			case 2 :
			{
				printf("Enter the name of the file : ");
				scanf("%s",&f);
				for(i=0;i<dir.fcnt;i++)
				{
					if(strcmp(f,dir.fname[i])==0)
					{
						printf("File %s has been deleted.\n",f);
						strcpy(dir.fname[i],dir.fname[dir.fcnt-1]);
						break;
					}
				}
				if(i==dir.fcnt)
				{
					printf("File not found.\n");
				}
				else
				{
					dir.fcnt--;
				}
				break;			
			}
			case 3 :
			{
				printf("Enter the name of the file : ");
				scanf("%s",f);
				for(i=0;i<dir.fcnt;i++)
				{
					if(strcmp(f,dir.fname[i])==0)
					{
						printf("File %s found at %s/%s.\n",f,dir.dname,f);
						break;
					}
				}
				if(i==dir.fcnt)
				{
					printf("File not found.\n");
				}
				break;			
			}
			case 4 :
			{
				if(dir.fcnt==0)
				{
					printf("Directory is empty.\n");
				}
				else
				{
					printf("Files present are :\n");
					for(i=0;i<dir.fcnt;i++)
					{
						printf("%s\t",dir.fname[i]);
					}
					printf("\n");
				}
				break;			
			}
			default :
			{
				exit(0);
			}
		}
	}
}
