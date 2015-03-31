#include <stdio.h>

int main()
{
    char ch;

    while((ch = getchar()) != EOF)
    {
        if(ch == 34)
        {
            printf("%c%c", '`', '`');
            while((ch = getchar()) != 34) putchar(ch);
            printf("%c%c", '\'', '\'');
        }
        else putchar(ch);
    }

    return 0;
}
