#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

// program to implent two level directory

void main()
{
    while (1)
    {
        int choice;
        printf("1. Create a directory 2. create a file 3. Delete a file 4. Search a file 5. List files 6. Exit");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            char dirname[20];
            printf("Enter the directory name: ");
            scanf("%s", dirname);
            mkdir(dirname);
            printf("Directory created successfully");
            break;
        }
        case 2:
        {
            char filename[20];
            char dirname[20];
            printf("Enter the file name: ");
            scanf("%s", filename);
            printf("Enter the directory name: ");
            scanf("%s", dirname);
            create_file(filename, dirname);
            break;
        }
        case 3:
        {
            char filename[20];
            char dirname[20];
            printf("Enter the file name: ");
            scanf("%s", filename);
            printf("Enter the directory name: ");
            scanf("%s", dirname);
            delete_file(filename, dirname);
            break;
        }

        case 4:
        {
            char filename[20];
            char dirname[20];
            printf("Enter the file name: ");
            scanf("%s", filename);
            printf("Enter the directory name: ");
            scanf("%s", dirname);
            search_files(filename, dirname);
            break;
        }

        case 5:
        {
            char dirname[20];
            printf("Enter the directory name: ");
            scanf("%s", dirname);
            display_files(dirname);
        }

        case 6:
        {
            exit(0);
        }
        }
    }
}

void create_file(char *filename, char *dirname)
{
    char path[50];
    strcpy(path, dirname);
    strcat(path, "/");
    strcat(path, filename);
    FILE *fp;
    fp = fopen(path, "w");
    if (fp == NULL)
    {
        printf("File creation failed");
    }
    else
    {
        printf("File created successfully");
    }
    fclose(fp);
}

void delete_file(char *filename, char *dirname)
{
    char path[50];
    strcpy(path, dirname);
    strcat(path, "/");
    strcat(path, filename);
    int status;
    status = remove(path);
    if (status == 0)
    {
        printf("File deleted successfully");
    }
    else
    {
        printf("File deletion failed");
    }
}

void search_files(char *filename, char *dirname)
{
    char path[50];
    strcpy(path, dirname);
    strcat(path, "/");
    strcat(path, filename);
    FILE *fp;
    fp = fopen(path, "r");
    if (fp == NULL)
    {
        printf("File not found");
    }
    else
    {
        printf("File found");
    }
    fclose(fp);
}

void display_files(char *dirname)
{
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(dirname)) != NULL)
    {
        while ((ent = readdir(dir)) != NULL)
        {
            printf("%s, ", ent->d_name);
        }
        closedir(dir);
    }
    else
    {
        printf("Directory not found");
    }
}
