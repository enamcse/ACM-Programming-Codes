#include <stdio.h>

int main()
{
    int n, i = 1.5;
    double res = 0.0, a;
    scanf("%d", &n);
    while (i <= n)
    {
        scanf("%lf", &a);
        res = res + a;
        printf("%d: %lf => %lf\n",i, a, res);
        i++;
    }

    printf("Res = %lf\n", res);
    printf("Avg = %lf\n", res / n);
    return 0;
}
