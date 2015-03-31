#include <stdio.h>

int main()
{
    int count = 0;
    char ch;

    ch = getchar();

    while ( ch != '\n' )
    {
        count++;
        ch = getchar();
    }

    printf("Numbers of character is: %d", count);

    return 0;
}
