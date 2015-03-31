#include <stdio.h>

int main()
{
    int a, b, c, max, min, n, i;

    scanf("%d", &n);

    for (i = 0; i < n; ++i)
    {
        scanf("%d %d %d", &a, &b, &c);
        min = a < b ? (c < a ? c : a) : (c < b ? c : b);
        max = a > b ? (c > a ? c : a) : (c > b ? c : b);

        if ((a == min || a == max) && (b == min || b == max)) printf("Case %d: %d\n", i + 1, c);
        else if ((a == min || a == max) && (c == min || c == max)) printf("Case %d: %d\n", i + 1, b);
        else if ((c == min || c == max) && (b == min || b == max)) printf("Case %d: %d\n", i + 1, a);
    }
    return 0;
}
