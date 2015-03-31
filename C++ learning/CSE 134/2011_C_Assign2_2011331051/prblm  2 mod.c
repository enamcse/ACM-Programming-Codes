#include <stdio.h>

int main()
{
    int a, b, a1, b1, q, r, q1, r1;

    printf("Enter the value of divided and divider (separated by space) : ");

    while (scanf("%d %d", &a, &b) == 2)
    {
        /*absolute*/
        if (a < 0 && b < 0)
        {
            a1 = -a;
            b1 = -b;
        }
        else if (a < 0)
        {
            a1 = -a;
            b1 = b;
        }
        else if (b < 0)
        {
            a1 = a;
            b1 = -b;
        }
        else
        {
            a1 = a;
            b1 = b;
        }

        /*reminder & quotient*/
        if (b == 0) printf("Can't divided by 0!\n");
        else if (a == b)
        {
            q = 1;
            r = 0;
        }
        else if (a == 0)
        {
            q = 0;
            r = 0;
        }
        else if (a > 0 && b > 0)
        {
            q = a1 / b1;
            r = a1 % b1;
        }
        else if(a1 == b1)
        {
            q = -1;
            r = 0;
        }
        else if ((a < 0 && b > 0) && (a1 < b1))
        {
            q = -1;
            r = a + b;
        }
        else if ((a < 0 && b > 0) && (a1 > b1))
        {
            q1 = a1 / b1;
            r1 = a1 % b1;
            q = -q1 - 1;

            if (r1 == 0) r = 0;
            else r = b - r1;

            if (r1 == 0) q = -q1;
            else q = -q1 - 1;
        }
        else if ((a > 0 && b < 0) && (a1 < b1))
        {
            r = a;
            q = 0;
        }
        else if ((a > 0 && b < 0) && (a1 > b1))
        {
            q1 = a1 / b1;
            r = a1 % b1;
            q = -q1;
        }
        else if ((a < 0 && b < 0) && (a1 > b1))
        {
            q1 = a1 / b1;
            r1 = a1 % b1;

            if (r1 == 0) q = q1;
            else q = q1 + 1;

            if (r1 == 0) r = 0;
            else r = b1 - r1;
        }
        else if ((a < 0 && b < 0) && (a1 < b1))
        {
            q = 1;
            r = a - b;
        }
        if (b != 0) printf("Qoutiant : %d and reminder : %d\n", q, r);
        printf("Enter the value of divided and divider (separated by space) : ");
        }
    return 0;
}
