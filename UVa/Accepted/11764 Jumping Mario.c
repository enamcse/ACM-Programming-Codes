#include <stdio.h>

int main()
{
    int t, n, up, down, now, then, i, j;

    scanf("%d", &t);

    for (i = 0; i < t; i++)
    {
        up = 0;
        down = 0;

        scanf("%d", &n);
        scanf("%d", &now);
        for (j = 1; j < n; j++)
        {
            then = now;
            scanf("%d", &now);
            if (now > then) up++;
            else if (then > now) down++;
        }
        printf("Case %d: %d %d\n", i + 1, up, down);
    }
    return 0;
}
