#include <stdio.h>
#include <string.h>

int main()
{
    int i, len1, len2, sum1, sum2, v, x, y, z;
    double ratio, s1, s2;
    char a[30], b[30];

    while(gets(a)&&gets(b))
    {
        sum1 = sum2 = 0;
        len1 = strlen(a);
        len2 = strlen(b);
        for (i = 0; i < len1; ++i)
        {
            if(a[i] >= 'a' && a[i] <= 'z') sum1 += a[i] - 'a' + 1;
            else if(a[i] >= 'A' && a[i] <= 'Z') sum1 += a[i] - 'A' + 1;
        }

        for (i = 0; i < len2; ++i)
        {
            if(b[i] >= 'a' && b[i] <= 'z') sum2 += b[i] - 'a' + 1;
            else if(b[i] >= 'A' && b[i] <= 'Z') sum2 += b[i] - 'A' + 1;
        }

        if ((sum1 == 0 && len1 == 0) || (sum2 == 0 && len2 == 0))
        {
            sum1 = 0;
            sum2 = 9;
        }
        else if(sum1 == 0 && sum2 == 0)
        {
            sum1 = 1;
            sum2 = 1;
        }
        else if (sum2 == 0)
        {
            sum1 = sum1 % 9;
            if (sum1 == 0) sum1 = 9;
            sum2 = 9;
        }
        else if (sum1 == 0)
        {
            sum2 = sum2 % 9;
            if (sum2 == 0) sum2 = 9;
            sum1 = 9;
        }

        while (sum1 >= 10)
        {
            v = sum1 % 10;
            sum1/=10;
            z = sum1 % 10;
            sum1/=10;
            y = sum1 % 10;
            sum1/=10;
            x = sum1 % 10;
            sum1 = v + x + y + z;
        }

        while (sum2 >= 10)
        {
            v = sum2 % 10;
            sum2/=10;
            z = sum2 % 10;
            sum2/=10;
            y = sum2 % 10;
            sum2/=10;
            x = sum2 % 10;
            sum2/=10;
            sum2 = v + x + y + z;
        }

        s1 = sum1;
        s2 = sum2;

        if (s1 > s2) ratio =  (s2 / s1) * 100;
        else ratio = (s1 / s2) * 100;

        printf("%.2lf %c\n", ratio,'%');
    }
    return 0;
}
