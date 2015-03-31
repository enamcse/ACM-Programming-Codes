#include <stdio.h>

int main()
{
    int a[20], product, n, no = 1, i, ve;

    while (scanf("%d", &n) == 1)
    {
        ve = 0;
        product = 1;
        for (i = 0; i < n; ++i)
        {
            scanf("%d", &a[i]);
            if (a[i] > 0)
            {
                product *= a[i];
                ++ve;
            }
        }

        if (ve == 0) printf("Case #%d: The maximum product is 0.\n\n", no++);
        else printf("Case #%d: The maximum product is %d.\n\n", no++, product);
    }
    return 0;
}
