#include <stdio.h>

int main()
{
    int a,b,c;

    a=-80, b=20, c=200;

    a=(a<0) ? 0 : 100;b=(b>0) ? 0 : 100;c=(c>0) ? 0 : 100;

    printf("%d %d %d\n", a,b,c);

    return 0;
}
