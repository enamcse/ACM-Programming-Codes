#include <stdio.h>

int main()
{
    int i, n, h[105], avg, count, t = 1;
    long long sum;
    scanf("%d", &n);

    while(n != 0)
    {
        sum = 0;
        for (i = 0; i < n; ++i)
        {
            scanf("%d", &h[i]);
            sum += h[i];
        }

        avg = sum / n;

        count = 0;

        for (i = 0; i < n; ++i)
        	if(h[i] < avg) count += avg - h[i];

        printf("Set #%d\n", t++);
        printf("The minimum number of moves is %d.\n\n", count);
        scanf("%d", &n);
    }
    return 0;
}
