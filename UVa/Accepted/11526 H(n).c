#include <stdio.h>
#include <math.h>

long long H(int n);

int main()
{
    int n, t, i;
    long long res;

    scanf("%d", &n);

    while(n--)
    {
        scanf("%d", &t);
        res = H(t);
        printf("%lld\n", res);
    }
    return 0;
}

long long H(int n)
{
    long long res = 0;
    int i, n2 = sqrt(n);
    for(i = 1; i <= n2; i++)
    {
        res += n/i;
    }
    return (2 * res - n2 * n2);
}
