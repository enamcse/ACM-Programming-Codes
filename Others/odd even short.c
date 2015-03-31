#include <stdio.h>

int main()
{
    int a,b,c,d;

    scanf("%d",&a);

        b=a/2;
        c=2*b;
        d=a-c;

    if (d==0) printf("even");
    else printf("odd");
    return 0;
}
