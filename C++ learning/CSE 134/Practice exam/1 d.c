#include <stdio.h>

int main()
{
    char colors[2][4] = { {'B', 'L', 'U', 'E'},
                          {'R', 'E', 'D', '\0'} };
    printf("%s\n", colors[0]);
    return 0;
}
