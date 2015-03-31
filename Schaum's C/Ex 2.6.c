/* hexa decimal integer constants*/
#include <stdio.h>

int main()
{
    int a, b, c, d;
    int e, f, g, h;
    int i, j, k;

 /* a = 0x; */   /* compiler showing error, invalid suffix 'x' */
    b = 0X1;
    c = 0X7FFF;   /* 32767 is the value converted into decimal constant */
    d = 0xabcd; /* 43981 is the value converted into decimal constant */

    printf("%d\n%d\n%d\n%d\n\n", a, b, c, d);

    e = f = g = h = 0x0;

 /* e = 0X12.34;*/  /* the compiler took it as an  error for having illegal character '.' */
 /* f = 0BE38;  /* the compiler did not take it as a hexadecimal constant for lacking of '0x' */
 /* g = 0x.4bff; */ /* the compiler took it as an  error for having illegal character '.' */
 /* h = 0XDEFG; */  /* the compiler took it as an error for having illegal character 'G' in hexadecimal constant */

    printf("%d\n%d\n%d\n%d\n", e, f, g, h);

    scanf("%d", &j);

    i = 0x7fffffff;
    k = i + j;

    printf("%d + %d = %d\n", i, j, k);

    /*
    experimentally I saw that the highest integer number in decimal is 2147483647,
    octal is 17777777777,
    and hexa decimal is 7FFFFFFF.
    */

    return 0;
}
