/* octal integer constants*/
#include <stdio.h>

int main()
{
    int a, b, c, d;
    int e, f, g;
    float h;

    a = 0;
    b = 01;
    c = 0743;   /* 483 is the value converted into decimal constant */
    d = 077777; /* 32767 is the value converted into decimal constant */

    printf("%d\n%d\n%d\n%d\n\n", a, b, c, d);

    e = 743; /* the compiler took it as decimal constant lacking of starting with '0' */
    /*f = 05280;*/ /*invalid digit '8' for octal constant */
    g = 0777.777; /* the compiler took it as decimal constant for having illegal character '.' */
    h = 0777.777; /* the compiler took it as decimal constant for having illegal character '.' */

    printf("%d\n%d\n%f\n\n", e, g, h);

    return 0;
}
