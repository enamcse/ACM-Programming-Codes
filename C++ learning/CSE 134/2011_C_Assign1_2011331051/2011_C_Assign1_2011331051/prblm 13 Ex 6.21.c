#include <stdio.h>
#include <math.h>

int main()
{
    float p, r, n, i, f;

    printf("Please enter a value for the principal (P) ");
    printf("\n(To end program, enter 0 for the principal): ");
    scanf("%f", &p);

    if (p < 0)
    {
        printf("\nERROR - Please try again: ");
        scanf("%f", &p);
    }

    while (p > 0)
    {
        printf("\nPlease enter a value for the interest rate (r): ");
        scanf("%f", &r);

        if (r < 0)
        {
            printf("\nERROR - Please try again: ");
            scanf("%f", &r);
        }

        printf("\nPlease enter a value for the number of years (n): ");
        scanf("%f", &n);

        if (n < 0)
        {
            printf("\nERROR - Please try again: ");
            scanf("%f", &n);
        }

        i = r/100;
        f = p * pow((1 + i), n);

        printf("\nThe final value (F) is: %.2f\n", f);
        printf("Please enter a value for the principal (P) ");
        printf("\n(To end program, enter 0 for the principal): ");
        scanf("%f", &p);

        if (p < 0)
        {
            printf("\nERROR - Please try again: ");
            scanf("%f", &p);
        }
    }
    return 0;
}
