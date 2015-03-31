#include <stdio.h>

int main()
{
    int n, i, a, b, c;

    scanf("%d", &n);

    while(n--)
    {
        scanf("%d %d %d", &a, &b, &c);
        a + b <= c ?  printf("Wrong!!\n") : printf("OK\n");
    }
    return 0;
}
