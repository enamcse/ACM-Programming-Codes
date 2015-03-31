#include <stdio.h>
#include <ctype.h>

int main()
{
    char ch;
    ch = getchar();

    while ((ch = getchar()) != '\n')
    {
        putchar(toupper(ch));
        putchar('\n');
    }
    return 0;
}
