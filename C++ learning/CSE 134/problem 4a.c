#include <stdio.h>

int main()
{
    int count = 0;
    char ch, chprev;

    chprev = ' ';
    ch = getchar();

    while (ch != '\n')
    {
        if (((ch >= 65 && ch <= 90) || (ch >= 'a' && ch <= 'z'))&&(chprev < 'A' || chprev > 'z' || (chprev > 'Z' && chprev < 'a')))
        count++;

        chprev = ch;

        ch = getchar();
    }

    printf("The number of word is %d", count);

    return 0;
}
