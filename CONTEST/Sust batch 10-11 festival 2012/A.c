#include <stdio.h>

int main()
{
    int a;

    scanf("%d", &a);

    while(a != 42)
    {
        printf("%d\n", a);
        scanf("%d", &a);
    }

    return 0;
}
