#include<stdio.h>

int main()
{
    int i,j,k,n,d;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        if(i==1)
            d=i;
        for(j=1; j<=2*(n-i); j++)
            printf(" ");
        for(k=1; k<=d; k++)
            printf("*");
        d=d+4;
        printf("\n");
    }
    return 0;
}
