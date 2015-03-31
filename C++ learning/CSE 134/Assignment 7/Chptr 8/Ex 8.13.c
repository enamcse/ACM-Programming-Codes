#include <stdio.h>
#include <math.h>

int main()
{
    float p, r, n, i, f;

    printf("Please enter a value fo r the principal (P): ");
    scanf("%f", &p);

    printf("Please enter a value fo r the interest rate (r): ");
    scanf("%f", &r);

    printf("Please enter a value fo r number of years (n): ");
    scanf("%f", &n);

    i = r / 100;
    f = p * pow((i+1), n);

    printf("\nThe final value (F) is: %.2f\n", f);

    return 0;
}
