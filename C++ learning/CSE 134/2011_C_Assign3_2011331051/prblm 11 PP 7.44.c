#include <stdio.h>

int main()
{
    double x, res;
    int n, i, j, m;
    while(scanf("%lf %d", &x, &n) == 2)
    {
        res = 1;
        if (n == 0) res = 1;
        else if (n > 0)
            for (i = 0; i < n; i++)
                res *= x;
        else
        {
            m = - n;
            for (j = 0; j < m; j++)
                res *= x;
            res = 1 / res;
        }

        printf("Result = %lf\n", res);
    }
    return 0;
}
