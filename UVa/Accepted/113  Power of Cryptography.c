#include <stdio.h>
#include <math.h>

int main()
{
    double n, p, x, k;

    while (scanf("%lf %lf", &n, &p) == 2)
    {
        x = 1 / n;
        k = pow(p, x);

        printf("%.0lf\n", k);
    }

    return 0;
}
