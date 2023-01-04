// Program to implement Pass 1 of a Two Pass Assembler
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void display()
{

    char str;
    FILE *fp1, *fp2, *fp3, *fp4;

    printf("\nThe contents of Input Table :\n\n");
    fp1 = fopen("input.txt", "r");
    str = fgetc(fp1);
    while (str != EOF)
    {
        printf("%c", str);
        str = fgetc(fp1);
    }
    fclose(fp1);

    printf("\n\nThe contents of Intermediate Table :\n\n");
    fp2 = fopen("intermediate.txt", "r");
    str = fgetc(fp2);
    while (str != EOF)
    {
        printf("%c", str);
        str = fgetc(fp2);
    }
    fclose(fp2);

    printf("\n\nThe contents of Symbol Table :\n\n");
    fp3 = fopen("symtab.txt", "r");
    str = fgetc(fp3);
    while (str != EOF)
    {
        printf("%c", str);
        str = fgetc(fp3);
    }
    fclose(fp3);
}

void main()
{
    FILE *f1, *f2, *f3, *f4;
    int locctr, start, length;
    char label[10], opcode[10], operand[10], mneumonic[10], code[10];
    f1 = fopen("input.txt", "r");
    f3 = fopen("symtab.txt", "w");
    f4 = fopen("intermediate.txt", "w");

    fscanf(f1, "%s\t%s\t%s", label, opcode, operand);
    if (strcmp(opcode, "START") == 0)
    {
        start = atoi(operand);
        locctr = start;
        fprintf(f4, "----\t%s\t%s\t%s\n", label, opcode, operand);
        fscanf(f1, "%s\t%s\t%s", label, opcode, operand);
    }
    else
        locctr = 0;

    while (strcmp(opcode, "END") != 0)
    {
        fprintf(f4, "%d\t%s\t%s\t%s\n", locctr, label, opcode, operand);
        if (strcmp(label, "----") != 0)
        {
            fprintf(f3, "%s\t%d\n", label, locctr);
        }

        f2 = fopen("optab.txt", "r");
        fscanf(f2, "%s\t%s", code, mneumonic);

        while (strcmp(code, "END") != 0)
        {
            if (strcmp(code, opcode) == 0)
            {
                locctr += 3;
                break;
            }
            fscanf(f2, "%s\t%s", code, mneumonic);
        }

        if (strcmp(opcode, "WORD") == 0)
            locctr += 3;

        else if (strcmp(opcode, "RESW") == 0)
            locctr = locctr + 3 * atoi(operand);

        else if (strcmp(opcode, "RESB") == 0)
            locctr += atoi(operand);

        else if (strcmp(opcode, "BYTE") == 0)
        {
            locctr = locctr + strlen(operand) - 2;
        }

        fscanf(f1, "%s\t%s\t%s", label, opcode, operand);
    }

    fprintf(f4, "%d\t%s\t%s\t%s\n", locctr, label, opcode, operand);
    length = locctr - start;
    printf("Size of program = %d\n", length);

    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);

    display();
}