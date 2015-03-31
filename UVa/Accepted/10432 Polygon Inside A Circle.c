#include <stdio.h>
#include <math.h>

int main()
{
    double n, r, area;

    while (scanf("%lf %lf", &r, &n) == 2)
    {
        area = n * r * r * sin(2 * 3.141592653589793238462643383279 / n) / 2;
        printf("%.3lf\n", area);
    }
    return 0;
}
