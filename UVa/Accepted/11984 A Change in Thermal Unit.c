#include <stdio.h>

int main()
{
    int t, i;
    float celc, fern, initial;

    scanf("%d", &t);

    for (i = 1; i <= t; ++i)
    {
        scanf("%f %f", &initial, &fern);
        celc = fern / 1.8;
        celc += initial;
        printf("Case %d: %.2f\n", i, celc);
    }
    return 0;
}
