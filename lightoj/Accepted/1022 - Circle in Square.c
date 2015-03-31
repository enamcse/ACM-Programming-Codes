#include <stdio.h>
#include <math.h>

int main()
{
    double r, area, pi = 2 * acos(0.0);
    int n, i = 0;

    scanf("%d", &n);

    while(n--)
    {
        scanf("%lf", &r);
        area = (4 - pi) * r * r;
        printf("Case %d: %.2lf\n", ++i, area);
    }

    return 0;
}
