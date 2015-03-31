#include <stdio.h>
#include <string.h>

int main()
{
    long int num;
    int i, j, a[100];

    scanf("%ld", &num);

    while(num >= 0)
    {
        if (num == 0)
        {
            i = 1;
            a[0] = 0;
        }
        else
            for (i = 0; num != 0; ++i)
            {
                a[i] = num % 3;
                num = num / 3;
            }

        for (j = i - 1; j >= 0; --j)
            printf("%d", a[j]);

        printf("\n");
        scanf("%ld", &num);
    }
    return 0;
}
