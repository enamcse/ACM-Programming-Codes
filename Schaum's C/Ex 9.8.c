#include <stdio.h>

int main()
{
    int n, count;
    float avg, d, sum = 0;
    float list[100];

    printf("\nHow many numbers will be avereged? ");
    scanf("%d", &n);
    printf("\n");

    for (count = 0; count < n; ++count)
    {
        printf("i = %d  x= ", count + 1);
        scanf("%f", &list[count]);
        sum += list[count];
    }

    avg = sum / n;
    printf("\nThe average is %5.2f\n\n", avg);

    for (count = 0; count < n; ++count)
    {
        d = list[count] - avg;
        printf("i = %d  x = %5.2f   d = %5.2f\n", count + 1, list[count], d);
    }
    return 0;
}
