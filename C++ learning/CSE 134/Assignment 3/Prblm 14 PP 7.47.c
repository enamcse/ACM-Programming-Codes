#include <stdio.h>

void average (int n);

int main()
{
    int n;
    printf("How many numbers?\n");

    while (scanf("%d", &n) == 1)
    {
        average(n);
        printf("How many numbers?\n");
    }
    return 0;
}


void average (int n)
{
    int i;
    double sum = 0, numb, average;
    for(i = 0; i < n; i++)
    {
        scanf("%lf", &numb);
        sum += numb;
    }
    average = sum / n;
    printf("Average = %lf\n\n", average);
}
