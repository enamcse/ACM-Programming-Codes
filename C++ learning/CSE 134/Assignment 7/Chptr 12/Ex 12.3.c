#include <stdio.h>
#include <ctype.h>

int main()
{
    FILE *fpt;

    char c;

    fpt = fopen("sample.dat", "w");
    do
        putc(toupper(c = getchar()), fpt);
    while (c != '\n');

    fclose(fpt);
    return 0;
}
