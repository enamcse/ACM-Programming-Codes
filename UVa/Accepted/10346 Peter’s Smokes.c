#include <stdio.h>

int main()
{
    int n, n1, k, i, m, count;

    while (scanf("%d %d", &n, &k) == 2)
    {
        count = n;
        n1 = n;
        while (n1 >= k)
        {
            count += n1 / k;
            n1 = n1 / k + n1 % k;
        }

        printf("%d\n", count);
    }
    return 0;
}
