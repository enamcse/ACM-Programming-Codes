#include <stdio.h>

int main()
{
    int i, sum, n, d, flag, e;

    scanf("%d", &n);

    printf("PERFECTION OUTPUT\n");

    while(n)
    {
        sum = 0;
        flag = 0;
        e =n/2;
        for (i = 1; i <= n; ++i)
        {
            d = n/i;
            if(n == (d*i) && d <= e) sum+=d;
            if(sum>n)
            {
                flag = 2;
                break;
            }
        }
        if(sum == n) flag = 1;

        if(flag == 0) printf("%5d  DEFICIENT\n",n);
        else if(flag == 1) printf("%5d  PERFECT\n",n);
        else if(flag == 2) printf("%5d  ABUNDANT\n",n);
        scanf("%d", &n);
    }
    printf("END OF OUTPUT\n");
    return 0;
}
