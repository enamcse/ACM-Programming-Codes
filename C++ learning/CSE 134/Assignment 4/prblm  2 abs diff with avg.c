#include <stdio.h>
#include <math.h>

void abs_diff(int n);

int main()
{
    int n;
    while (scanf("%d", &n) == 1)
    {
        abs_diff(n);
    }
}

void abs_diff(int n)
{
    float numb[1000], sum = 0, avg, diff[1000];
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%f", &numb[i]);
        sum += numb[i];
    }

    avg = sum / n;
    printf("Average =   %f\n", avg);
    printf("The difference between numbers and average:\n\n", avg);

    for (i = 0; i < n; i++)
    {
        diff[i] = fabs (numb[i] - avg);
        printf("Difference with number %d is:   %f\n", i+1, diff[i]);
    }
    return;
}
