#include <stdio.h>

int main()
{
    int a, a1, a2, a3, a4, a5, a6, m, c, x, i, j, k, l;

    printf("Please enter a number : ");

    while (scanf("%d", &a) == 1)
    {
        if (a == 0) break;

        m = a / 1000;
        a1 = a - (1000 * m);

        for (i = 1; i <= m; i++)
            printf("M");

        a2 = a1;

        if ((a1 % 1000) >= 900)
        {
            printf("CM");
            a2 = a1 - 900;
        }
        else if ((a % 1000) >= 400)
        {
            if ((a % 1000) < 500)
            {
                printf("CD");
                a2 = a1 - 400;
            }
            else
            {
                printf("D");
                a2 = a1 - 500;
            }
        }

        c = a2 / 100;
        a3 = a2 - (100 * c);

        for (j = 1; j <= c; j++)
            printf("C");

        a4 = a3;

        if ((a1 % 100) >= 90)
        {
            printf("XC");
            a4 = a3 - 90;
        }
        else if ((a % 100) >= 40)
        {
            if ((a % 100) < 50)
            {
                printf("XL");
                a4 = a3 - 40;
            }
            else
            {
                printf("L");
                a4 = a3 - 50;
            }
        }

        x = a4 / 10;
        a5 = a4 - (10 * x);

        for (k = 1; k <= x; k++)
            printf("X");

        a6 = a5;

        if ((a1 % 10) >= 9)
        {
            printf("IX");
            a6 = a5 - 9;
        }
        else if ((a % 10) >= 4)
        {
            if ((a % 10) == 4)
            {
                printf("IV");
                a6 = a5 - 4;
            }
            else
            {
                printf("V");
                a6 = a5 - 5;
            }
        }

        for (l = 1; l <= a6; l++)
            printf("I");

        printf("\n");
        if (a < 0) printf("Invalid number!\n");
        printf("Please enter a number : ");
    }
    printf("\n");
    return 0;
}
