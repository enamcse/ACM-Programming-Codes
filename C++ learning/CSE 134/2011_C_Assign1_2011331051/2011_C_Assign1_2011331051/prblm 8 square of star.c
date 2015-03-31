#include <stdio.h>

int main()
{
    int size, x, y;

    printf("square size : ");
    scanf("%d", &size);

    if(size < 0) printf("square can't be negative!");

    else
    {
        for(x = 0; x < size; x++)
        {
            for(y = 0; y < size; y++)
            {
                if(y == (size - 1)) printf("*\n");
                else if(x == 0 || y == 0 || x == (size - 1)) printf("* ");
                else printf("  ");
            }
        }
    }

    return 0;
}
