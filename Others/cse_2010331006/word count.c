#include <stdio.h>
#include <conio.h>

int main()
{
    int count, flag;
    char word, test = ' ';

    count = 0;

    word = getchar();

    while (word != '\n')
    {
        flag = 0;

        if (((word >= 'A' && word <= 'Z') || (word >= 'a' && word <= 'z'))&&((test <= 'A' || test >= 'z') && (test >= 'Z' || test <= 'a')))
        flag = 1;

         test = word;

        if (flag == 1)
        count++;

        word = getchar();
    }

    printf("%d\n", count);

    return 0;
}
