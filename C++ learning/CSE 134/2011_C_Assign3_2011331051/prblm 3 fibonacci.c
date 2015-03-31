/*last valid output gives for 47*/
#include <stdio.h>

unsigned long fibonacci (int n);

int main()
{
    int fib;
    while (scanf("%d", &fib) == 1)
    {
        printf("Fibonacci number %d is : %u\n", fib, fibonacci(fib));
    }
    return 0;
}

unsigned long fibonacci (int n)
{
    unsigned long a, b;
    if (n == 0) return 0;
    else if (n == 1) return 1;
    a = fibonacci (n - 1);
    b = fibonacci (n - 2);
    return a + b;
}
