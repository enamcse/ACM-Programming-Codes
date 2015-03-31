#include <stdio.h>

int main()
{
    int time[100000], i, j, n, min;
    while(scanf("%d", &n)==1)
    {
        scanf("%d", &time[0]);
        min = time[0];
        for (i = 1; i < n; ++i)
        {
            scanf("%d", &time[i]);
            if(time[i]<min) min = time[i];
        }
        j = 0;
        for (i = 0; i < n; ++i)
            if(time[i] == min)
            {
                ++j;
                time[0] = i+1;
            }
        if(j == 1) printf("%d\n", time[0]);
        else printf("Still Rozdil\n");
    }
    return 0;
}
