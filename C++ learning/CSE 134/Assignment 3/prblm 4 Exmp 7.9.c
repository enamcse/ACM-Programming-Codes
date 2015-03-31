#include <stdio.h>

int maximum (int x, int y);

int main()
{
    int a, b, c;

    printf("\na = ");
    scanf("%d", &a);

    printf("\nb = ");
    scanf("%d", &b);

    printf("\nc = ");
    scanf("%d", &c);

    printf("\n\nmaximum = %d", maximum (c, maximum (a, b)));

    return 0;
}

int maximum (int x, int y)
{
    int z;
    z = (x >= y) ? x : y;
    return z;
}
