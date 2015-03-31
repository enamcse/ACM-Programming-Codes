#include <stdio.h>
#include <math.h>

int main()
{
    int n[30], j, yr;
    double factor[30][16], value, i[] = {4, 4.5, 5, 5.5, 6, 6.5, 7, 7.5, 8, 8.5, 9, 9.5, 10, 11, 12, 15};

    for (j = 0; j < 16; j++)
    {
        value = (1 + i[j]) / 100;
        for (yr = 0; yr < 30; yr++)
            factor[yr][j] = pow(value, yr + 1);
    }

    printf("\t\t\tTABLE OF COMPOUND INTEREST FACTORS\n");
    printf("YEAR    |");

    for (j = 0; j < 16; j++)
        printf(" i = %.1lf  |", i[j]);

    printf("\n");

    for (j = 0; j < 185; j++)
        printf("-");

    printf("\n");

    for (yr = 0; yr < 30; yr++)
    {
        printf("%d\t|", yr + 1);

        for (j = 0; j < 16; j++)
            printf(" %.1e |", factor[yr][j]);

        printf("\n");
    }

    return 0;
}
