/*last valid output gives for 12*/
#include <stdio.h>

unsigned long int fact (int a);

int main()
{
    int n;
    while (scanf("%d", &n) == 1)
    {
        printf("Factorial %d is %u\n", n, fact(n));
    }
    return 0;
}

unsigned long int fact (int a)
{
    unsigned long int b;
    if (a == 0)
    return 1;
    b = fact (a - 1);
    return a * b;
}
