#include <stdio.h>

float average (float sum, int count);
float deviation (int count, float avg);

int n = 5;
float list[] = {3, -2, 12, 4.4, 3.5};

int main()
{
    int count;
    float avg, d, sum = 0;

    avg = average(sum, n - 1);

    deviation(n - 1, avg);

    return 0;
}

float average (float sum, int count)
{

    if(count == -1) return 0;

    sum = average (sum, count - 1);

    sum += list[count];

    if (count == (n - 1))
    {
        float avg;
        avg = sum / n;
        printf("\nThe average is %5.2f\n\n", avg);
        return avg;
    }
    return sum;
}

float deviation (int count, float avg)
{
    float d;
    if(count == -1) return avg;

    avg = deviation (count - 1, avg);

        d = list[count] - avg;
        printf("i = %d  x = %5.2f   d = %5.2f\n", count + 1, list[count], d);
        return avg;
}
