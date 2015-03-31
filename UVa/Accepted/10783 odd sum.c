#include <stdio.h>

int main()
{
    int a, b, i = 0, n, c, d = 0, sum, temp;

    scanf("%d", &n);

    while (i < n)
    {
        sum = 0;

        scanf("%d %d", &a, &b);

        temp = a;

        c = a % 2;

        while (c == 1)
        {
            sum = sum + temp;
            temp = temp + 2;

            if ((temp == (b + 1)) || (temp == (b + 2))) c = 2;
        }

        if (c == 0)
        {
            d = 1;
            temp = a + 1;
        }

        while (d == 1)
        {

            sum = sum + temp;
            temp = temp + 2;

            if ((temp == (b + 1)) || (temp == (b + 2))) d = 2;
        }

        printf("Case %d: %d\n", i + 1, sum);

        i++;
    }
    return 0;
}
