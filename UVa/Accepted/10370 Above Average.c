#include <stdio.h>

int main()
{
    int C, N, num[1000], i, j, count;
    double sum, percent[1000], avg;

    while(scanf("%d", &C) == 1)
    {
        for (i = 0; i < C; ++i)
        {
            sum = 0;
            count = 0;
            scanf("%d", &N);
            for (j = 0; j < N; ++j)
            {
                scanf("%d", &num[j]);
                sum+= num[j];
            }

            avg = sum / N;

            for (j = 0; j < N; ++j)
            	if (num[j] > avg) ++count;

            percent[i] = 100 * (double)count / N;
        }

        for (i = 0; i < C; ++i)
        	printf("%.3lf\%c\n", percent[i], '%');
    }
    return 0;
}
