#include <stdio.h>

int main()
{
    int a, b, c, d, e, f, g, i, n, m, p, q, sum;

    while (scanf("%d", &n) == 1)
    {
        for (i = 1; i <= n; ++i)
        {
            scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g);
            p = (e > f) ? ((g > e) ? g : e) : ((g > f) ? g : f);
            q = (p == e) ? ((f > g) ? f : g) : ((p == f) ? ((e > g) ? e : g) : ((e > f) ? e : f));
            m = (p + q) / 2;
            sum = a + b + c + d + m;

            if (sum >= 90) printf("Case %d: A\n", i);
            else if (sum >= 80) printf("Case %d: B\n", i);
            else if (sum >= 70) printf("Case %d: C\n", i);
            else if (sum >= 60) printf("Case %d: D\n", i);
            else printf("Case %d: F\n", i);
        }
    }
    return 0;
}
