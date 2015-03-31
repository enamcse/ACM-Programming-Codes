#include <stdio.h>

int main()
{
    int a, b, c, min, max;

    scanf("%d %d %d", &a, &b, &c);

    min = a < b ? (a < c ? a : c) : (b < c ? b : c);
    max = a > b ? (a > c ? a : c) : (b > c ? b : c);

    if (a == b && b == c) printf("All are same numbers: %d", a);
    else printf("The minimum value is: %d\nThe maximum value is: %d\n", min, max);

    return 0;
}
