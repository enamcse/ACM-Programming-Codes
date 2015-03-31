#include <stdio.h>
#include <math.h>

int main()
{
    int t , amplitude;
    double value[65];

    for (t = 0; t < 61; t++)
        	value[t] = 2 * exp(-t / 10) * sin(t / 2);

    while (scanf("%d", &amplitude) == 1)
    {
        printf("Value of t\tValue of y\n");

        for (t = 0; t < 61; t += amplitude)
        	printf("    %d\t\t%6lf\n", t, value[t]);
    }

    return 0;
}
