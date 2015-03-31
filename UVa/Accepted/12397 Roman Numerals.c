#include <stdio.h>

int main()
{
    int a, a1, a2, a3, a4, a5, a6, m, c, x, i, j, k, l, count;

    while (scanf("%d", &a) == 1)
    {
        count = 0;
        if (a == 0) break;

        m = a / 1000;
        a1 = a - (1000 * m);

        for (i = 1; i <= m; i++)
            count += 4;

        a2 = a1;

        if ((a1 % 1000) >= 900)
        {
            count += 6;
            a2 = a1 - 900;
        }
        else if ((a % 1000) >= 400)
        {
            if ((a % 1000) < 500)
            {
                count += 5;
                a2 = a1 - 400;
            }
            else
            {
                count += 3;
                a2 = a1 - 500;
            }
        }

        c = a2 / 100;
        a3 = a2 - (100 * c);

        for (j = 1; j <= c; j++)
            count += 2;

        a4 = a3;

        if ((a1 % 100) >= 90)
        {
            count += 4;
            a4 = a3 - 90;
        }
        else if ((a % 100) >= 40)
        {
            if ((a % 100) < 50)
            {
                count += 4;
                a4 = a3 - 40;
            }
            else
            {
                count += 2;
                a4 = a3 - 50;
            }
        }

        x = a4 / 10;
        a5 = a4 - (10 * x);

        for (k = 1; k <= x; k++)
            count += 2;

        a6 = a5;

        if ((a1 % 10) >= 9)
        {
            count += 3;
            a6 = a5 - 9;
        }
        else if ((a % 10) >= 4)
        {
            if ((a % 10) == 4)
            {
                count += 3;
                a6 = a5 - 4;
            }
            else
            {
                count += 2;
                a6 = a5 - 5;
            }
        }

        for (l = 1; l <= a6; l++)
            count += 1;

        printf("%d\n", count);
    }

    return 0;
}
