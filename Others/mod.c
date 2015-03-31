#include <stdio.h>

int main()
{
    int i, j, k;

    printf(" a % b = mod, (a b): ");
    while(scanf("%d %d", &i, &j) == 2)
    {
        k=i%j;
        printf("mod = %d\n", k);
        printf(" a % b = mod, (a b): ");
    }

    return 0;
}
