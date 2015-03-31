/* floating-points*/
#include <stdio.h>

int main()
{
    float a, b, c, d, e, f, g, h, i, j, k, l, m, n, o = 0, p = 0;

    a = 0.;
    b = 1.;
    c = 0.2;
    d = 827.602; /* the compiler takes an approximate value. */
    e = 50000.;
    f = 0.000743;
    g = 12.3;
    h = 315.0066; /* the compiler takes an approximate value. */
    i = 2e-8;
    j = 0.006E-3;
    k = 1.6667E+8;
    l = .12121212e12; /* the compiler takes an approximate value. */
    m = 1;  /* the compiler takes it as a valid float. */
    n = 1,000.0; /* ',' is invalid within floating point, so it takes '1' int the memory. */
/*  o = 2E+10.2; */ /* exponential cant be a fraction, must be an integer. */
/*  p = 3E 10; */ /* spacing is invalid after exponential sign or within the number. */

    printf("a = %f\nb = %f\nc = %f\nd = %f\ne = %f\nf = %f\ng = %f\nh = %f\ni = %f\nj = %f\nk = %f\nl = %f\nm = %f\nn = %f\no = %f\np = %f\n", a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p);
}
