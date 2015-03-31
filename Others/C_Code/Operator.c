#include <stdio.h>

int main()
{
    int a = 5, b =5, c =6;
    int l1, l2;
    l1 = (a < 5 && b < c && c <= a);
    printf("%d\n", l1);
    return 0;
}
