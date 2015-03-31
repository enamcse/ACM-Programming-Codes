#include <stdio.h>

int main()
{
    int m, n, cut;

    while(scanf("%d %d", &m, &n) == 2)
    {
        cut = m - 1;
        cut += (n - 1) * m;
        printf("%d\n", cut);
    }
    return 0;
}
