#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct DirNode;

struct DirNode
{
    char dirName[10], fileNames[10][10];
    int fileCount, dirCount;
    struct DirNode *subDirs;
    struct DirNode *nextSiblingDir;
    struct DirNode *parent;
} rootDir;

void createSubDirectory(struct DirNode *parent, char name[])
{

    struct DirNode *newNode = (struct DirNode *)malloc((sizeof(struct DirNode)));
    if (newNode == NULL)
    {
        printf("Sorry there was an error\n Aborting\n");
        exit(0);
    }
    newNode->subDirs = NULL;
    newNode->nextSiblingDir = NULL;
    newNode->parent = parent;
    strcpy(newNode->dirName, name);

    struct DirNode *temp = parent->subDirs;
    if (temp)
    {
        while (temp->nextSiblingDir)
        {
            temp = temp->nextSiblingDir;
        }
        temp->nextSiblingDir = newNode;
    }
    else
    {
        parent->subDirs = newNode;
    }
    printf("\nSub Directory: %s created under %s", newNode->dirName, parent->dirName);

    parent->dirCount++;
}

void createSubFile(struct DirNode *parent, char name[])
{
    strcpy(parent->fileNames[parent->fileCount], name);
    parent->fileCount++;
}

void gotoDir(struct DirNode **currDir, char name[])
{

    if (strcmp(name, "..") == 0)
    {
        if ((*currDir)->parent)
        {
            *currDir = (*currDir)->parent;
        }
        printf("Already at root directory");
        return;
    }

    struct DirNode *temp = *currDir;
    while (temp->subDirs)
    {
        temp = temp->subDirs;
        printf(" SubDirs:  %s", temp->dirName);

        if (strcmp(temp->dirName, name) == 0)
        {
            *currDir = temp;
            return;
        }
    }

    printf("Sub Directory not found");
}

void main()
{
    strcpy(rootDir.dirName, "root");
    rootDir.parent = NULL;

    struct DirNode *currDir = &rootDir;

    // createSubDirectory(&rootDir, "SubDir1");

    char tempDirName[100];
    int choice;

    while (1)
    {
        printf("\n\n\nCurrent Directory: %s", currDir->dirName);
        printf("\nFiles here:");
        if (currDir->fileCount == 0)
        {
            printf("No Files");
        }
        else
        {
            for (int i = 0; i < currDir->fileCount; i++)
            {
                printf("\t%s", currDir->fileNames[i]);
            }
        }

        printf("\nDirectories here:");
        if (currDir->dirCount == 0)
        {
            printf("No Directories");
        }
        else
        {
            struct DirNode *temp = currDir->subDirs;
            if (temp)
                printf("\t%s", temp->dirName);
            while (temp->nextSiblingDir)
            {
                temp = temp->nextSiblingDir;
                printf("\t%s", temp->dirName);
            }
        }

        printf("\n\n1. Create Directory\n2. Traverse Directory\n3. Create File\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {

        case 1:
            printf("Enter Subdirectory name: ");
            scanf("%s", tempDirName);
            createSubDirectory(currDir, tempDirName);
            break;
        case 2:
            printf("Enter Directory to traverse to: ");
            scanf("%s", tempDirName);
            gotoDir(&currDir, tempDirName);
            printf("\n");
            break;
        case 3:
            printf("Enter File name: ");
            scanf("%s", tempDirName);
            createSubFile(currDir, tempDirName);
            break;
        }
    }
}