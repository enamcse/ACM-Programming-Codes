#include <stdio.h>
#include <math.h>

int main()
{
    int i, n, g, r, arr[] = {27, 6, 1, 4, 113, 3, 128};
    for (i = 0; i < 7; i++)
    {
        n = arr[i]; g = log10(n); r = sqrt(n);
        if((n%2==0 || r%5==0)&&((n+5)%3==1 || g < 5))
            printf("%d %d %d %d\n", i, g, r, n%(g+r));
    }
    return 0;
}
