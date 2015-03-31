#include <stdio.h>
#include <math.h>

double value (int p)
{
    double a, b, y;
    a = exp(-0.1 * p);
    b = sin(0.5 * p);
    y = a * b;
    return y;
}

int main()
{
    int t, i, j, k, y1, space;
    //double a, b, y;
    for (t = 20; t >= 1; t--)
    {
        y1 = 20 * value (t);
        space = y1 - 1;
        if (space >= 0) space = 10 + space;
        else space = 10 - space;
        for (i = 1; i <= space; i++)
        {
            printf(" ");
            if (i == 20 )
            {
                printf("\b|");
            }
        }

        printf("*");

        if (space < 20)
        {
            space = 20 - (space + 1);
            for (i = 1; i <= space; i++)
            {
                printf(" ");
                if (i == space)
                {
                    printf("\b|");
                }
            }
        }
        printf("\n");
    }
    return 0;
}
