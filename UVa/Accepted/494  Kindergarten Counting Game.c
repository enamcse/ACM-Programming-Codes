#include <stdio.h>
#include <string.h>

int main()
{
    int count, i;
    char a[300];

    while(gets(a))
    {
        count = 0;
        for (i = 0; i < strlen(a); ++i)
        {
            if((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z'))
            {
                count++;
                for(i++; (a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z'); ++i);
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
