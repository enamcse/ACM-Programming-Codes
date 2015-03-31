#include <stdio.h>
#include <math.h>
#define EPS .00000001
int main()
{
    long long int n, i, flag,sqr;
    double s;
    scanf("%lld", &n);

    while(n)
    {
        flag=0;
        s=sqrt(n)+EPS;
        sqr=(int) s;
//        printf(".....%d\n",sqr);
        if(sqr*sqr==n) flag = 1;
        if(flag) printf("yes\n");
        else printf("no\n");

        scanf("%lld", &n);
    }

    return 0;
}
