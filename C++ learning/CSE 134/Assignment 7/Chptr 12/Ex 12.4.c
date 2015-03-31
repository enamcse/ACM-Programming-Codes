#include <stdio.h>

#define NULL 0

int main()
{
    FILE *fpt;

    char c;

    if((fpt = fopen("sample.dat", "r")) == NULL)
        printf("\n ERROR - Cannot open the designed read file.\n");
    else
        do
            putchar(c = getc(fpt));
        while (c != '\n');

    fclose(fpt);
    return 0;
}
