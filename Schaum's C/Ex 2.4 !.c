#include <stdio.h>

int main()
{
    int a, b, c, d, e;

    a = b = c = d = e = 0;

    a = 12,245; /* ',' is an invalid integer. the compiler just omitted digits after ','.*/
    b = 36.0;   /* no error found here. only the digits after decimal point are omitted.*/
    /*c = 10 20 30;*/ /* spacing is invalid for integer number. so, it didnt found ';' after integer*/
    d = 123-45-6789; /* it makes a result of substruction. so, the result came in minus sign*/
    /*e = 0900;*/  /*0 refers to octal integer. 9 is an invalid integer in octal. so, it showed error*/

    printf("%d\n%d\n%d\n%d\n%d\n\n", a, b, c, d, e);

    return 0;
}
