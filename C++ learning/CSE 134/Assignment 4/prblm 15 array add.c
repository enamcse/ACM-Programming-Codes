#include <stdio.h>
#include <string.h>

int main()
{
    char x[1000], y[1000], sum[1000];
    int i, carry = 0, len1, len2, len, u, v, add;

    sum[0] = '0';

    gets(x);
    gets(y);

    len1 = strlen (x);
    len2 = strlen (y);



    if (len1 > len2)
    {
        len = len1;

        for (i = len2 - 1; i >= 0; i--)
            y[i + len1 - len2] = y[i];

        for (i = len1 - len2 - 1; i >= 0; i--)
            y[i] = 0;
    }
    else
    {
        len = len2;

        for (i = len1 - 1; i >= 0; i--)
            x[i + len2 - len1] = x[i];

        for (i = len2 - len1 - 1; i >= 0; i--)
            x[i] = 0;
    }


    for (i = len - 1; i >= 0; i--)
    {
        u = x[i] - '0';
        v = y[i] - '0';

        add = u + v + carry;

        carry = add / 10;

        sum[i + 1] = (add % 10) + '0';
    }
    if (carry == 1) sum[0] = '1';

    sum[len + 1] = '\0';

    for (i = 0; i< len; i++)
    	printf("%c", sum[i]);
    return 0;
}
