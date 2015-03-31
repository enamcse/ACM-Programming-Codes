#include <stdio.h>
#include <string.h>


int main()
{
    int i, j, k, len, sum, prime;
    char a[30];

    while(scanf("%s", a) == 1)
    {
        prime = 1;
        sum = 0;
        len = strlen(a);

        for (i = 0; i < len; ++i)
        {
            if(a[i] >= 'a' && a[i] <= 'z') sum += a[i] - 'a' + 1;
            else if(a[i] >= 'A' && a[i] <= 'Z') sum += a[i] - 'A' + 27;
        }

        for (i = 2; i < sum; i++)
        	if(sum % i == 0) prime = 0;

        if(prime) printf("It is a prime word.\n");
        else printf("It is not a prime word.\n");
    }
    return 0;
}
