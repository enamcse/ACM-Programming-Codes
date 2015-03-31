#include <stdio.h>

int main()
{
    char c1 = 'A', c2 = 'B', c3 = 'C';

    printf("%c %c %c\n", c1, c2, c3);
    printf("%c%c%c\n", c1, c2, c3);
    printf("%3c %3c %3c\n", c1, c2, c3);
    printf("%3c%3c%3c\n", c1, c2, c3);
    printf("c1=%c c2=%c c3=%c\n", c1, c2, c3);

    return 0;
}
