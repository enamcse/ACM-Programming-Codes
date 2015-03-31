#include <stdio.h>

int main()
{
    int i, j;
    while(scanf("%d", &i) == 1)
    {
        j = i/(1/i);//code juma!!
        printf("y = %d\n", j);
    }
    return 0;
}
