#include <stdio.h>

int main()
{
    int fn1 = 0, fn2 = 1, fn, n, i = 2;

    scanf("%d", &n);

    if (n > 0)
    {
        printf("Number 0 Fibonocci number is : %d\n", fn1);
        printf("Number 1 Fibonocci number is : %d\n", fn2);

        while (i<=n)
        {
            fn = fn1 + fn2;
            fn1 = fn2;
            fn2 = fn;

            printf("Number %d Fibonocci number is : %d\n", i, fn);
            i++;
        }
    }
    else if (n == 0) printf("Number 0 Fibonocci number is : %d\n", fn1);
         else printf("Number %d is a negative number.\n", n);

    return 0;
}
