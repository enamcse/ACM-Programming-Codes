#include <stdio.h>

int main()
{
    int n;
    long long cube;

    while (scanf("%d", &n) == 1)
    {
        cube = ((n * n) + n) * ((n * n) + n) / 4;
        printf("%lld\n", cube);
    }
    return 0;
}
