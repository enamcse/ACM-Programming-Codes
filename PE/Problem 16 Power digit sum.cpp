#include <stdio.h>
#include <string.h>
#define sz 1000

int main()
{
    int i, j, k, l, carry = 0, lena, lenb, len, u, v, w, cnt=0;
    char a[sz] = {"1"}, b[sz], sum[sz];
    while(cnt++!=1000)
    {
        strcpy(b,a);
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
            len = strlen(sum);
            for (i =len; i>=0; i--)
                sum[i+1]=sum[i];
            sum[0] = '1';
        }

//        puts(sum);
        strcpy(a,sum);
    }
    len = strlen(sum);
    cnt = 0;
    for (i=0; i<len; i++)
    {
        w = sum[i] - '0';
        cnt+= w;
    }
    printf("Sum of digits: %d\n", cnt);
    return 0;
}
