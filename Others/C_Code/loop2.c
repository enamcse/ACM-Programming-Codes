#include <stdio.h>

int main()
{
    long long unsigned int n, i = 1, res = 0,a;
    scanf("%d", &n);
    while (i <= n)
    {
        scanf("%d", &a);
        res = res + a;
        printf("%d: %d => %d\n", i, a, res);
        i++;
    }

    printf("Res = %d\n", res);
    return 0;
}
