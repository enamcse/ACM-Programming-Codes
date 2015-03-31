#include <stdio.h>

int scan(void);

int main()
{
    int i, n, y, x;

    while(scanf("%d", &x) == 1)
    {
        switch (n  = scan())
        {
        	case 1:
                y =  2 * x;
                printf("%d\n", y);
                continue;

        	default:
                y =  10 * x;
                printf("%d\n", y);
                continue;

            case 2:
                y =  4 * x;
                printf("%d\n", y);
                continue;
        }

    }
    return 0;
}

int scan(void)
{
    int a;
    scanf(" %d", &a);
    return a;
}
