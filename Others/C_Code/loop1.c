#include <stdio.h>

int main()
{
    long long int n, i = 1, sum = 0, multiple = 1;
    scanf("%d", &n);
    while (i <= n)
    {
        sum = sum + i;
        multiple = multiple * i;
        printf("sum = %d & multiply = %d i =%d\n", sum, multiple, i);
        i++;
    }

    printf("Sum = %d and Factorial = %d\n", sum, multiple);
    return 0;
}
