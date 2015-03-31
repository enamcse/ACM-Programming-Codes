#include <stdio.h>

int main()
{
    int i, j, k, p, n, t, hartal[100][3650], hp[100], wd = 0, flag;

    scanf("%d", &t);
    for (i = 0; i < t; i++)
    {
        for (j = 0; j < 100; ++j)
            for (k = 0; k < 3650; ++k)
                hartal[j][k] = 0;

        scanf("%d %d", &n, &p);
        for (j = 0; j < p; ++j)
        {
            scanf("%d", &hp[j]);
            for (k = hp[j] - 1; k < n; k += hp[j])
                hartal[j][k] = 1;
        }

        /*for (j = 0; j < p; ++j)
        {
            for (k = 0; k < n; ++k)
                printf("%d ", hartal[j][k]);
            printf("\n");
        }*/

        wd = 0;
        for (j = 0; j < n; ++j)
        {
            flag = 0;
            if((j+1)%7 != 0 && (j+1)%7 != 6)
            {
                for (k = 0; k < p; ++k)
                    if (hartal[k][j] == 1) flag = 1;
            }

            if(flag) wd++;
        }
        printf("%d\n", wd);
    }
    return 0;
}
