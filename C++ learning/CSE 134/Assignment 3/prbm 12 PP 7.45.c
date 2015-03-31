/*As far I understood, I made a function for all positive value of x, and then
I included the function in the program written for PP 7.44 then represented here.*/
#include <stdio.h>
#include <math.h>

double f_of_x (double x, double n);

int main()
{
    double x, n;
    int m, res, i, j;
    while(scanf("%lf %lf", &x, &n) == 2)
    {
        if (x > 0) printf("Result = %lf\n", f_of_x(x, n));
        else if (x == 0 && n == 0) printf("Invalid Input\n");
        else
        {
            res = 1;
            m = n;
            if (m == 0) res = 1;
            else if (m > 0)
                for (i = 0; i < m; i++)
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
    }
    return 0;
}

double f_of_x (double x, double n)
{
    double y;
    y = n * log(x);
    return exp(y);
}
