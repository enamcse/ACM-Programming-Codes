#include <stdio.h>
#include <math.h>

int main()
{
    int count = 0;
    double a[200], n;

    while(scanf(" %lf ", &n) == 1 && count != 3)
    {
        a[count++] = sqrt(n);
    }

    while(count+1)
    {
        printf("%.4lf\n", a[count--]);
    }

    return 0;
}
