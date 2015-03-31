#include <stdio.h>
#include <math.h>

void root (double a, double b, double c);

int main()
{
    double a, b, c;
    while (scanf("%lf %lf %lf", &a, &b, &c) == 3)
    {
        if (a == 0) ("Invalid Input");
        else
        {
            printf("The roots of the equation are ");
        root(a, b, c);
        }
    }
}

void root (double a, double b, double c)
{
    double D, b_square, real, image, part1, part2;
    b_square = b * b;
    D = 4 * a * c;

    if (b_square < D)
    {
        real = -b / (2 * a);
        image = (pow((D - b_square), .5)/ (2 * a));
        printf("%lf + %lfi and %lf - %lfi\n", real, image, real, image);
    }
    else
    {
        real = pow((b_square - D), .5);
        part1 = (-b + real) / (2 * a);
        part2 = (-b - real) / (2 * a);
        printf("%lf and %lf\n", part1, part2);
    }
    return;
}
