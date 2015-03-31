/* i took at most first 7 terms to get the best result. */
#include <stdio.h>
#include <math.h>

int main()
{
    int i, j, n, p = 1, a, b, diff;
    double x, y, y1, q, u, v, k, r;

    printf("x (radian) = ?");
    scanf("%lf", &x);

    /*printf("How many terms? : ");
    scanf("%d", &n);*/
    n = 7;
    r = x;
    if (r >= 0)
    {
        for (k = r; k >= 3.14159; k -= 3.14159)
            ;
        r = k;
        printf("x (radian) = %lf\n", r);
    }
    else
    {
        r = -x;
        for (k = r; k >= 3.14159; k -= 3.14159)
            ;
        r = k;
        printf("x (radian) = %lf\n", r);
    }

    y = r / p;

    if (n >= 1 && x >= 0) printf("n = 1, sin (x) = %lf\n", y);
    else if (n >= 1 && x < 0) printf("n = 1, sin (x) = %lf\n", -y);

    for ( i = 2, j = 3; i <= n; i++, j += 2)
    {
        if (i <= 6)
        {
            p = p * j * (j - 1);
            y1 = y;
            u = pow(r, j);
            v = pow((-1), (i-1));
            y = y + ((u * v) / p);

            if(x >= 0) printf("n = %d, sin (x) = %lf\n", i, y);
            else printf("n = %d, sin (x) = %lf\n", i, -y);
        }

        if (i > 6)
        {
            q = p;

            q = q * j * (j - 1);
            y1 = y;
            u = pow(x, j);
            v = pow((-1), (i-1));
            y = y + ((u * v) / q);

            if(x >= 0) printf("n = %d, sin (x) = %lf\n", i, y);
            else printf("n = %d, sin (x) = %lf\n", i, -y);
        }

        a = 100000 * y;
        b = 100000 * y1;
        diff = abs(a - b);

        if (diff <= 1) break;
    }
    return 0;
}
