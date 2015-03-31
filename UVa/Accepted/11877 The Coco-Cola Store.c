#include <stdio.h>

int main()
{
    int n, count;

    scanf("%d", &n);
    while ( n != 0)
    {
        count = n / 2;

        printf("%d\n", count);
        scanf("%d", &n);
    }
    return 0;
}
