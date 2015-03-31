#include <stdio.h>
#include <string.h>

int main()
{
    int i, j, k, l, carry = 0, lena, lenb, len, u, v, w;
    char a[200], b[200], sum[201];

    while(gets(a) && gets(b))
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

        if (carry) printf("1");
        puts(sum);
    }

    return 0;
}
