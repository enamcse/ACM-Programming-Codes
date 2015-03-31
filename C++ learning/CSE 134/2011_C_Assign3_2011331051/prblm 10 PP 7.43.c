#include <stdio.h>

double f_of_x (double x, int n);

int main()
{
    double x;
    int n;
    while(scanf("%lf %d", &x, &n) == 2)
    {
        printf("Result = %lf\n", f_of_x(x, n));
    }
    return 0;
}

double f_of_x (double x, int n)
{
    double y;
    if (n == 1) return x;
    if (n > 0)y = f_of_x (x, n - 1) * x;
    else if (n == 0) return 1;
    else y = f_of_x (x, (n + 1)) / x;
    return y;
}
