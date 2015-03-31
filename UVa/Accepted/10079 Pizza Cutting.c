#include <stdio.h>

long long int pizza (long long int n, long long int sum);

int main()
{
    long long int n, sum = 0;
    scanf("%lld", &n);
    while (n >= 0)
    {
        printf("%lld\n", pizza(n, sum));
        scanf("%lld", &n);
    }

    return 0;
}

long long int pizza (long long int n, long long int sum)
{
    if (n == 0) return 1;
    sum = n + pizza(n - 1, sum);
    return sum;
}
