#include <stdio.h>

int main()
{
    int i, j, k, l = 1, m = 1, n;

    n = 10;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= (n - i); j++)
        printf(" ");

        for (k = 1; k <= i; k++)
        {
            if (m == 10) m = 0;
            printf("%d", m++);
        }



        if (i >= 2)
        {
            m -= 2;
            for (k = 1; k < i; k++)
            {
                if(m == -1) m = 9;
                printf("%d", m--);
            }
            m += 2;
        }

        printf("\n");
    }
    return 0;
}
