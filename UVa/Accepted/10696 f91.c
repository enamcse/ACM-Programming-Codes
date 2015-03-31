#include <stdio.h>

int f91 (int n);

int main()
{
    int n, num;

    while(scanf("%d", &n) == 1)
    {
        if(n == 0)break;
        num = f91(n);
        printf("f91(%d) = %d\n", n, num);
    }
    return 0;
}

int f91 (int n)
{
    if (n >= 101) return n - 10;
    else return 91;
}
