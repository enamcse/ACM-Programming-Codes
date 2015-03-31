#include <stdio.h>

int main()
{
    int i, x = 0;
    for (i = 1; i < 10; ++i)
    {
        if(i%2 == 0) x++;
        else {
         x--;
         break;
        }
        printf("%d ", x);
    }
    printf("\nx = %d", x);
    return 0;
}
