#include <stdio.h>

int main()
{
    int count = 0;
    char ch;

    ch = getchar();

    while (ch != 65) {printf("The number of word is %d", count); count=count+1;}

    printf("The number of word is %d", count);
    while (ch != '\n')
    {
        putchar(toupper(ch));
        ch = getchar();
    }
}
