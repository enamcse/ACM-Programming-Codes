#include <stdio.h>
#include <string.h>

int main()
{
    int i, j, k, l, carry = 0, t, len, u, v, w, count, lensum;
    char a[200], b[200], sum[201];

    scanf("%d ", &t);

    for(j = 0; j < t; ++j)
    {
        gets(a);
        len = strlen(a);
        for (i = 0; i < len; ++i)
        {
            b[i] = a[len - i - 1];
        }
        b[len] = '\0';
        count = 0;

        while (strcmp(a, b))
        {
            carry = 0;
            sum[len] = '\0';
            for (i = 0; i < len; i++)
            {
                u = a[len - i - 1] - '0';
                v = b[len - i - 1] - '0';

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
                lensum = strlen(sum);
                sum[lensum+1] = '\0';
                for (k = lensum; k >= 0; --k)
                    sum[k+1] = sum[k];
                sum[0] = '1';
            }

            strcpy(a,sum);
            for (k = 0; k < 200; ++k)
                sum[k] = 0;

            len = strlen(a);
            for (i = 0; i < len; ++i)
            {
                b[i] = a[len - i - 1];
            }
            b[len] = '\0';
            ++count;
        }

        printf("%d %s\n", count, a);
    }

    return 0;
}
