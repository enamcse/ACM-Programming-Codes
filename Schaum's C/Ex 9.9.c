#include <stdio.h>

int n = 5;
float list[] = {3, -2, 12, 4.4, 3.5};

int main()
{
    int count;
    float avg, d, sum = 0;

    for (count = 0; count < n; ++count)
        sum += list[count];

    avg = sum / n;
    printf("\nThe average is %5.2f\n\n", avg);

    for (count = 0; count < n; ++count)
    {
        d = list[count] - avg;
        printf("i = %d  x = %5.2f   d = %5.2f\n", count + 1, list[count], d);
    }
    return 0;
}
