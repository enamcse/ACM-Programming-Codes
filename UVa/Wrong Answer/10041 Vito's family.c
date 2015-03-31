#include <stdio.h>
#include <stdlib.h>
#define SZ 550

int comp(const void *p, const void *q)
{
    int *a=(int *)p;
    int *b=(int *)q;
    return ((*a)-(*b));
}

int main()
{
    int i, n, test, sum, min, max, rela[SZ], num, cnt, diff, mid;

    scanf("%d", &test);

    while(test--)
    {
        sum = max = cnt = 0;
        min =  90000;
        scanf("%d", &n);
        while (n--)
        {
            scanf("%d", &rela[cnt]);
//            max = max < rela[cnt] ? rela[cnt] : max;
//            min = min > rela[cnt] ? rela[cnt] : min;
            cnt++;
        }
        qsort(rela,cnt,sizeof(int),comp);
        max = rela[0];
        min = rela[cnt-1];
        mid = min+((max - min) >> 1);
//        printf("mid=%d\n", mid);
        i = 0;
        max = mid < rela[i] ? rela[i] : mid;
        min = mid > rela[i] ? rela[i] : mid;
        sum+=(max-min);
        for (i = 1; i < cnt; ++i)
        {
            if(rela[i] != rela[i-1])
            {
                max = mid < rela[i] ? rela[i] : mid;
                min = mid > rela[i] ? rela[i] : mid;
                sum+=(max-min);
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
