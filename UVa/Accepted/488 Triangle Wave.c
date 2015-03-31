#include <stdio.h>

int main()
{
    int i, j, amp, freq, n;

    scanf("%d", &n);

    while(n--)
    {
        scanf(" %d", &amp);
        scanf(" %d", &freq);
        while(freq--)
        {
            for (i = 1; i <= amp; i++)
            {
                for (j = 1; j <= i; j++)
                    printf("%d", i);
                printf("\n");
            }
            for (i=i-2; i >= 1; i--)
            {
                for (j = 1; j <= i; j++)
                    printf("%d", i);
                printf("\n");
            }
            if(freq != 0 || n != 0)
                printf("\n");
        }
    }

    return 0;
}
