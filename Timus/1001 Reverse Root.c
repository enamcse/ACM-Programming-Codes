#include <stdio.h>
#include <math.h>

int main()
{
    int count = 0;
    double a[500000], n;

    while(scanf("%lf", &n) == 1) a[count++] = sqrt(n);

    while(count--) printf("%.4lf\n", a[count]);

    return 0;
}
