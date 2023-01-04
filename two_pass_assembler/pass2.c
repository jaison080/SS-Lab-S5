// Program to implement Pass 2 of a Two Pass Assembler
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void display()
{
    char ch;
    FILE *fp1, *fp2, *fp3, *fp4;

    printf("The contents of Intermediate file:\n");
    fp3 = fopen("intermediate.txt", "r");
    ch = fgetc(fp3);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = fgetc(fp3);
    }
    fclose(fp3);

    printf("\n\nThe contents of Symbol Table :\n");
    fp2 = fopen("symtab.txt", "r");
    ch = fgetc(fp2);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = fgetc(fp2);
    }
    fclose(fp2);

    printf("\n\nThe contents of Output file :\n");
    fp1 = fopen("output.txt", "r");
    ch = fgetc(fp1);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = fgetc(fp1);
    }
    fclose(fp1);

    printf("\n\nThe contents of Object code file :\n");
    fp4 = fopen("objcode.txt", "r");
    ch = fgetc(fp4);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = fgetc(fp4);
    }
    fclose(fp4);
}

void main()
{
    char a[10], ad[10], label[10], opcode[10], operand[10], symbol[10], code[10], mneumonic[10];
    int start, end, address, prev, finadd, len, symadd, proglen;

    FILE *f1, *f2, *f3, *f4, *f5;
    f1 = fopen("intermediate.txt", "r");
    f2 = fopen("optab.txt", "r");
    f3 = fopen("symtab.txt", "r");
    f4 = fopen("output.txt", "w");
    f5 = fopen("objcode.txt", "w");

    fscanf(f1, "%s\t%s\t%s\t%s", a, label, opcode, operand);

    address = 0;
    while (strcmp(opcode, "END") != 0) // Finding the length of program
    {
        prev = address;
        fscanf(f1, "%d\t%s\t%s\t%s", &address, label, opcode, operand);
    }
    finadd = address;

    rewind(f1);

    fscanf(f1, "%s\t%s\t%s\t%s", a, label, opcode, operand);
    if (strcmp(opcode, "START") == 0)
    {
        fprintf(f4, "%s\t%s\t%s\t%s\n", a, label, opcode, operand);
        fprintf(f5, "H^%s^00%s^0000%d\n", label, operand, (finadd - atoi(operand)));
        fscanf(f1, "%d\t%s\t%s\t%s", &address, label, opcode, operand);
        start = address;
        proglen = prev - start;
        fprintf(f5, "T^00%d^%d", address, proglen);
    }

    while (strcmp(opcode, "END") != 0)
    {
        if (strcmp(opcode, "BYTE") == 0)
        {
            fprintf(f4, "%d\t%s\t%s\t%s\t", address, label, opcode, operand);
            len = strlen(operand) - 2;
            fprintf(f5, "^");

            for (int i = 2; i < (len + 2); i++)
            {
                // itoa((int)operand[i], ad, 16);
                sprintf(ad, "%x", operand[i]);
                fprintf(f4, "%s", ad);
                fprintf(f5, "%s", ad);
            }
            fprintf(f4, "\n");
        }

        else if (strcmp(opcode, "WORD") == 0)
        {
            len = strlen(operand);
            fprintf(f4, "%d\t%s\t%s\t%s\t", address, label, opcode, operand);
            fprintf(f5, "^");
            for (int i = 0; i < 6 - len; i++)
            {
                fprintf(f4, "0");
                fprintf(f5, "0");
            }
            // itoa(atoi(operand), a, 16);
            sprintf(a, "%x", atoi(operand));
            fprintf(f4, "%s\n", a);
            fprintf(f5, "%s", a);
        }

        else if ((strcmp(opcode, "RESB") == 0) || (strcmp(opcode, "RESW") == 0))
        {
            fprintf(f4, "%d\t%s\t%s\t%s\n", address, label, opcode, operand);
        }

        else
        {
            rewind(f2);
            rewind(f3);
            while (fscanf(f2, "%s\t%s", code, mneumonic) != EOF)
            {
                if (strcmp(opcode, code) == 0)
                    break;
            }
            while (fscanf(f3, "%s\t%d", symbol, &symadd) != EOF)
            {
                if (strcmp(operand, symbol) == 0)
                    break;
            }
            fprintf(f4, "%d\t%s\t%s\t%s\t%s%d\n", address, label, opcode, operand, mneumonic, symadd);
            fprintf(f5, "^%s%d", mneumonic, symadd);
        }

        fscanf(f1, "%d\t%s\t%s\t%s", &address, label, opcode, operand);
    }

    fprintf(f4, "%d\t%s\t%s\t%s\n", address, label, opcode, operand);
    fprintf(f5, "\nE^00%d\n", start);

    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
    fclose(f5);

    display();
}