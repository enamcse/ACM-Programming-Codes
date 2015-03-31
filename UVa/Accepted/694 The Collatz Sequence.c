#include <stdio.h>

int main()
{
    long long i, j, a, l, term, temp, t = 1;

    scanf(" %lld %lld", &a, &l);

    while(a >= 0 && l >= 0)
    {
        term = 0;
        temp = a;
        while(temp != 1 && temp <= l)
        {
            if(temp%2 == 0) temp /= 2;
            else temp = temp * 3 + 1;
            term++;
        }
        if (temp == 1 && temp < l) ++term;
        printf("Case %lld: A = %lld, limit = %lld, number of terms = %lld\n", t++, a, l, term);
        scanf(" %lld %lld", &a, &l);
    }
    return 0;
}
