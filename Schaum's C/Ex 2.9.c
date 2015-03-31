/* 3 * 10 to the power 5 can be represent as */
#include <stdio.h>

int main()
{
    float a, b, c, d, e, f, g, h, i, j, k, l, m, n;

/* 3 * 10 to the power 5 can be represent as */
    a = 300000.;
    b = 3e5;
    c = 3e+5;
    d = 3E5;
    e = 3.0e+5;
    f = .3e6;
    g = 0.3E6;
    h = 30E4;
    i = 30.E+4;
    j = 300e3;

/* 5.026 * 10 to the power -17 can be represent as */

    k = 5.026E-17;
    l = .5026e-16;
    m = 50.26e-18;
    n = .0005026E-13;

    printf("a = %f\nb = %f\nc = %f\nd = %f\ne = %f\nf = %f\ng = %f\nh = %f\ni = %f\nj = %f\nk = %.20f\nl = %.20f\nm = %.20f\nn = %.20f\n", a, b, c, d, e, f, g, h, i, j, k, l, m, n);
}
