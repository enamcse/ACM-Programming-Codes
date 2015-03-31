#include <stdio.h>

int main()
{
    int a, b, c, d, e, f, g;

    a = 50000U;
    b = 123456789L;
    c = 123456789UL;
    d = 0123456L;
    e = 0777777U;
    f = 0X50000U;
    g = 0XFFFFFUL;

    printf("a = %d\nb = %d\nc = %d\nd = %d\ne = %d\nf = %d\ng = %d\n", a, b, c, d, e, f, g);

    return 0;
}
