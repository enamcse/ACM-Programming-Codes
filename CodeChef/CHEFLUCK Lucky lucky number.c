#include <stdio.h>

int main()
{
    int i, k, t, flag, n;

    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        flag = 1;
        for (i = 0; i <= n && flag; i+= 4)
        {
            for (k = 0; (i + k) <= n; k+= 7)
            	if ((i + k) == n)
            	{
            	    flag = 0;
            	    printf("%d\n", k);
            	    break;
            	}
        }

        if (flag) printf("%d\n", -1);
    }
    return 0;
}
/*
#include<stdio.h>
int main() {
    int t , n ;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        n = ((n/7)-((n%7)%4))*7;
        printf("%d\n",(0>n)?-1:n);
    }
    return 0;
}
*/
