#include <stdio.h>

int main()
{
    int i, j, k, l, n = 10;

    //scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= (n - i); j++)
        	printf(" ");
        for (k = 1; k <= i; k++)
        	{
        	    if (k == 1) printf("*");
        	    else printf(" ");
        	}
        for (l = 2; l <= i; l++)
        	{
        	    if (l == i) printf("*");
        	    else printf(" ");
        	}
        printf("\n");
    }

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
        	printf(" ");
        for (k = 1; k <= (n - i); k++)
        {
            if (k == 1) printf("*");
            else printf(" ");
        }
        for (l = 2; l <= (n - i); l++)
        	{
        	    if (l == (n - i)) printf("*");
        	    else printf(" ");
        	}
        printf("\n");
    }
    return 0;
}
