#include <stdio.h>

int main()
{
    int a, b, c;

    printf("\aa = ?\n");
    scanf("%d", &a);

    printf("\ab = ?\n");
    scanf("%d", &b);

    c = a + b;

    printf("\aThis is not\b\b\b\ \t\v\n\f\r\"\'\?\\ c = %d \n\0", c);

    return 0;
}
