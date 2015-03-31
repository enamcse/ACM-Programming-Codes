#include <stdio.h>

int main()
{
    int n, count, navg = 0;
    float x, average, sum = 0;

    printf("How many numbers? ");
    scanf("%d", &n);

    for (count = 1; count <= n; ++count)
    {
        printf("x = ");
        scanf("%f", &x);
        if (x < 0) continue;
        sum += x;
        ++navg;
    }

    average = sum / navg;

    if (navg == 0) printf("No positive number found!");
    else printf("\nThe average is %f\n", average);

    return 0;
}
