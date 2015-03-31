#include <stdio.h>
#include <string.h>
#define SZ 80

int main()
{
    int i, j, k, l, carry = 0, lena, lenb, len, u, v, w, count=SZ, co=0,flag;
    char a[20], b[20], sum[21], fib[SZ][20], examine[100];

    strcpy(fib[co++],"0");
    strcpy(a,"0");
    strcpy(fib[co++],"1");
    strcpy(b,"1");

    while(count--)
    {
        lena = strlen(a);
        lenb = strlen(b);
        len = lena > lenb ? lena : lenb;
        carry = 0;
        sum[len] = '\0';
        for (i = 0; i < len; i++)
        {
            if(lena - i > 0) u = a[lena - i - 1] - '0';
            else u = 0;

            if(lenb - i > 0) v = b[lenb - i - 1] - '0';
            else v = 0;

            w = u + v + carry;
            carry = 0;
            if(w > 9)
            {
                w = w%10;
                carry = 1;
            }

            sum[len - i - 1] = w + '0';
        }

        if (carry)
        {
            sum[len + 1] = '\0';
            for (i = len; i > 0 ; i--)
            {
                sum[i] = sum[i - 1];
            }
            sum[0] = '1';
        }
        strcpy(a, b);
        strcpy(b, sum);
        strcpy(fib[co++],sum);
    }

    while(scanf("%s", examine) == 1)
    {
        flag=1;
        for (i = 0; i < SZ; ++i)
        	if(strcmp(fib[i],examine) == 0)
        	{
        	    printf("%d\n", i);
        	    flag=0;
        	    break;
        	}
        	else if (strlen(fib[i]) > strlen(examine))
        	{
        	    printf("%d\n", -1);
        	    flag=0;
        	    break;
        	}
        if(flag) printf("%d\n", -1);
    }
    return 0;
}




/*
#include <stdio.h>

int main()
{
    int i, num, a[1000];

    a[0] = 0;
    a[1] = 1;

    for (i = 2; i < 1000; ++i)
    	a[i] = a[i-1]+a[i-2];

    while (scanf("%d", &num)==1)
        for (i = 0; i < 1000; ++i)
        	if(a[i] == num)
        	{
        	    printf("%d\n", i);
        	    break;
        	}
        	else if (a[i] > num)
        	{
        	    printf("%d\n", -1);
        	    break;
        	}


    return 0;
}
*/
