#include <stdio.h>
#include <string.h>

int main()
{
    long int num;
    int count;
    int i, j, a[100];

    scanf("%ld", &num);

    while(num > 0)
    {
        count = 0;
        for (i = 0; num != 0; ++i)
        {
            a[i] = num % 2;
            num = num / 2;
            if (a[i] == 1) count++;
        }

        printf("The parity of ");

        for (j = i - 1; j >= 0; --j)
            printf("%d", a[j]);

        printf(" is %d (mod 2).\n", count);
        scanf("%ld", &num);
    }
    return 0;
}
