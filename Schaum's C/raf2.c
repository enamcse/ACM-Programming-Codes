#include <stdio.h>

int main()
{
    int a = 017777777770, b;

    while (a >= 0)
    {
        b = a;
        a++;

        printf("a = %d\nb = %d\n", a, b);
    }

    printf("Final b is %d\n", b);

    return 0;
}
