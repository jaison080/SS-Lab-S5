#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100
void swap(char *x, char *y)
{
    char t = *x;
    *x = *y;
    *y = t;
}

// Function to reverse `buffer[i…j]`
char *reverse(char *buffer, int i, int j)
{
    while (i < j)
    {
        swap(&buffer[i++], &buffer[j--]);
    }

    return buffer;
}

// Iterative function to implement `itoa()` function in C
char *itoa(int value, char *buffer, int base)
{
    // invalid input
    if (base < 2 || base > 32)
    {
        return buffer;
    }

    // consider the absolute value of the number
    int n = abs(value);

    int i = 0;
    while (n)
    {
        int r = n % base;

        if (r >= 10)
        {
            buffer[i++] = 65 + (r - 10);
        }
        else
        {
            buffer[i++] = 48 + r;
        }

        n = n / base;
    }

    // if the number is 0
    if (i == 0)
    {
        buffer[i++] = '0';
    }

    // If the base is 10 and the value is negative, the resulting string
    // is preceded with a minus sign (-)
    // With any other base, value is always considered unsigned
    if (value < 0 && base == 10)
    {
        buffer[i++] = '-';
    }

    buffer[i] = '\0'; // null terminate string

    // reverse the string and return it
    return reverse(buffer, 0, i - 1);
}
// end of itoa block

int main()
{
    FILE *f1, *f2, *f3, *f4, *f5;
    char label[max], opcode[max], operand[max], name[max], opcode1[max], operand1[max], arg[max];
    int pos = 1, len;
    char pos1[max], pos2[max];
    f1 = fopen("input.txt", "r");
    f2 = fopen("namtab.txt", "w+");
    f3 = fopen("deftab.txt", "w+");
    f4 = fopen("argtab.txt", "w+");
    f5 = fopen("output.txt", "w+");
    fscanf(f1, "%s%s%s", label, opcode, operand);
    while (strcmp(opcode, "END") != 0)
    {
        if (strcmp(opcode, "MACRO") == 0)
        {
            fprintf(f2, "%s", label);
            fseek(f2, SEEK_SET, 0);
            fprintf(f3, "%s\t%s\n", label, operand);
            fscanf(f1, "%s%s%s", label, opcode, operand);
            while (strcmp(opcode, "MEND") != 0)
            {
                if (operand[0] == '&')
                {
                    itoa(pos, pos1, 5);
                    strcpy(pos2, "?");
                    strcpy(operand, strcat(pos2, pos1));
                    pos = pos + 1;
                }
                fprintf(f3, "%s\t%s\n", opcode, operand);
                fscanf(f1, "%s%s%s", label, opcode, operand);
            }
            fprintf(f3, "%s", opcode);
        }
        else
        {
            fscanf(f2, "%s", name);
            if (strcmp(name, opcode) == 0)
            {
                len = strlen(operand);
                for (int i = 0; i < len; i++)
                {
                    if (operand[i] != ',')
                    {
                        fprintf(f4, "%c", operand[i]);
                    }
                    else
                    {
                        fprintf(f4, "\n");
                    }
                }
                fseek(f3, SEEK_SET, 0);
                fseek(f4, SEEK_SET, 0);
                fscanf(f3, "%s%s", opcode1, operand1);
                fprintf(f5, ".\t%s\t%s\n", opcode1, operand1);
                fscanf(f3, "%s%s", opcode1, operand1);
                while (strcmp(opcode1, "MEND") != 0)
                {
                    if (operand1[0] == '?')
                    {
                        fscanf(f4, "%s", arg);
                        fprintf(f5, "-\t%s\t%s", opcode1, arg);
                    }
                    else
                    {
                        fprintf(f5, "-\t%s\t%s", opcode1, operand1);
                    }
                    fscanf(f3, "%s%s", opcode1, operand1);
                }
            }
            else
            {
                fprintf(f5, "%s\t%s\t%s\n", label, opcode, operand);
            }
        }
        fscanf(f1, "%s%s%s", label, opcode, operand);
    }
    fprintf(f5, "%s\t%s\t%s\n", label, opcode, operand);
}