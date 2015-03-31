#include <stdio.h>

int n, f, stat, area, sum;

int main()
{
    scanf("%d", &n);

    while(n-- && scanf("%d", &f) == 1)
    {
        sum = 0;
        while(f-- && scanf("%d %*d %d", &area, &stat) == 2)
        {
            sum += (area * stat);
        }
        printf("%d\n", sum);
    }
    return 0;
}
