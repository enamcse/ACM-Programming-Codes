#include <stdio.h>

#define swap(a,b) a^=b^=a^=b;

int main()
{
    int x, y, z;
    while(1)
    {
        scanf("%i %i %i", &x, &y, &z);
        swap(x, y)
        swap(x, z)
        printf("%i %i %i\n", x, y, z);
    }
    return 0;
}
