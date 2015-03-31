#include <stdio.h>

int main()
{
    int n, i, sum, dif, a, b, add;

    scanf("%d", &n);

    for (i = 0; i < n; ++i)
    {
        scanf("%d %d", &sum, &dif);
        add = sum + dif;

        if (sum >= dif && add % 2 == 0)
        {
            a = add / 2;
            b = sum - a;
            printf("%d %d\n", a, b);
        }
        else printf("impossible\n");
    }
    return 0;
}
