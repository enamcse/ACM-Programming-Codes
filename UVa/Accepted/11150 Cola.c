#include <stdio.h>

int main()
{
    int n, count;

    while (scanf("%d", &n) == 1)
    {
        count = n + n / 2;

        printf("%d\n", count);
    }
    return 0;
}
