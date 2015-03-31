#include <stdio.h>

int main()
{
    int n = 1;
    while (n <= 10000)
    {
        if (n < 9)
        {
            printf("%d\n", n);
            n = n + 2;
        }
        else
        {
            printf("%d\n", n);
            n = n + 11;
        }
    }
    return 0;
}
