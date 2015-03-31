#include <stdio.h>

int main()
{
    int t, k, n, p, i, j, ball;
    scanf("%d", &t);

    for (i = 0; i < t; ++i)
    {
        scanf("%d %d %d", &n, &k, &p);
        if (n >= 2 && k >= 1 && n >= k && p >= 1)
        {
            ball = k;
            for (j = 0; j < p; ++j)
            {
                ++ball;
                if (ball == n + 1) ball = 1;
            }
            printf("Case %d: %d\n", i + 1, ball);
        }
    }
    return 0;
}
