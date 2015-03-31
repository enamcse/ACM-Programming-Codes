#include <stdio.h>

int main()
{
    char c, d;
    float x, y;
    int i, j, k;

    c = getchar();
    scanf("%f", &x);
    scanf("%d %d", &i, &j);
    d = c - 'A' + 66;
    y = 3.14 * x;
    k = (i + j) % j;
    putchar(d);
    printf("%3d %7.4f", k, y);

    return 0;
}
