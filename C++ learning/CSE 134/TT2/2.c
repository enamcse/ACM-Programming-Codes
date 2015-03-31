#include <stdio.h>

int main()
{
    int n;
    char ch[10];

    scanf(" %6s %x", ch, &n);
    printf("%-6.3s%d\n", ch, n);

    return 0;
}
