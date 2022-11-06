#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

void main()
{

    char dirname[20];
    printf("Enter the directory name: ");
    scanf("%s", dirname);
    mkdir(dirname);
    printf("Directory created successfully");

    while (1)
    {
        int choice;
        printf("1. Create a file 2. Delete a file 3. Search a file 4. List files 5. Exit");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            char filename[20];
            printf("Enter the file name: ");
            scanf("%s", filename);
            create_file(filename, dirname);
            break;
        }
        case 2:
        {
            char filename[20];
            printf("Enter the file name: ");
            scanf("%s", filename);
            delete_file(filename, dirname);
            break;
        }
        case 3:
        {
            char filename[20];
            printf("Enter the file name: ");
            scanf("%s", filename);
            search_files(filename, dirname);
            break;
        }
        case 4:
        {
            display_files(dirname);
            break;
        }
        case 5:
        {
            exit(0);
        }
        }
    }
}

// function to create file in the directory
void create_file(char *filename, char *dirname)
{

    FILE *fp;
    char path[100];
    sprintf(path, "%s/%s", dirname, filename);
    fp = fopen(path, "w");

    if (fp == NULL)
    {
        printf("Error in creating file");
        exit(1);
    }
    printf("File created successfully");
    fclose(fp);
}

// fucnction to delete file from the directory
void delete_file(char *filename, char *dirname)
{
    char path[100];
    sprintf(path, "%s/%s", dirname, filename);
    if (remove(path) == 0)
    {
        printf("File deleted successfully");
    }
    else
    {
        printf("Error in deleting file");
    }
}

// display all files in the directory
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
}

void search_files(char *filename, char *dirname)
{
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir(dirname)) != NULL)
    {
        while ((ent = readdir(dir)) != NULL)
        {
            if (strcmp(ent->d_name, filename) == 0)
            {
                printf("File exists");
                return;
            }
        }
        printf(" shedaFile does not exist");
        closedir(dir);
    }
}
