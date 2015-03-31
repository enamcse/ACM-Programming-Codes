#include<stdio.h>

int main()
{
    int t, n, i=1, s = 0 ;


    while(scanf("%d", &n)!= 0)
    {
        if(n==0) break;
        s =0;
        for(i=n; i>=1; i--)
        {
            s += (i*i);
        }
        printf("%d\n", s);


    }

    return 0;
}
