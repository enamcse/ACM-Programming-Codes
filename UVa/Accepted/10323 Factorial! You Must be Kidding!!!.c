#include <stdio.h>

int main()
{
    int n;

    while(scanf("%d", &n) == 1)
    {
        if (n < 0)
        {
            if (n % 2 == 0) printf("Underflow!\n");
            else printf("Overflow!\n");
        }
        else if (n < 8) printf("Underflow!\n");
        else if (n > 13) printf("Overflow!\n");
        else switch (n)
            {
            case 8:
                printf("40320\n");
                break;
            case 9:
                printf("362880\n");
                break;
            case 10:
                printf("3628800\n");
                break;
            case 11:
                printf("39916800\n");
                break;
            case 12:
                printf("479001600\n");
                break;
            case 13:
                printf("6227020800\n");
                break;
            }
    }
    return 0;
}
