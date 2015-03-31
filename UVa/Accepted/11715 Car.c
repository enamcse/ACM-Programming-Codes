#include <stdio.h>
#include <math.h>

int main()
{
    double u, v, a, t, s;
    int n, i = 1;

    scanf("%d", &n);
    while (n != 0)
    {
        switch (n)
        {
        case 1:
            scanf("%lf %lf %lf", &u, &v, &t);
            a = (v - u) / t;
            s = (u * t) + (a * t * t / 2);
            printf("Case %d: %.3lf %.3lf\n", i++, s, a);
            break;

        case 2:
            scanf("%lf %lf %lf", &u, &v, &a);
            t = (v - u) / a;
            s = (u * t) + (a * t * t / 2);
            printf("Case %d: %.3lf %.3lf\n", i++, s, t);
            break;

        case 3:
            scanf("%lf %lf %lf", &u, &a, &s);
            v = sqrt((u * u) + (2 * a * s));
            t = (v - u) / a;
            printf("Case %d: %.3lf %.3lf\n", i++, v, t);
            break;

        case 4:
            scanf("%lf %lf %lf", &v, &a, &s);
            u = sqrt((v * v) - (2 * a * s));
            t = (v - u) / a;
            printf("Case %d: %.3lf %.3lf\n", i++, u, t);
            break;
        }
        scanf("%d", &n);
    }
    return 0;
}
