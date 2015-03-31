#include <stdio.h>

int main()
{
    int a, b, c;
    double x, y, z;

    scanf("%d %d %d", &a, &b, &c);

    while(a != 0 && b != 0 && c!= 0)
    {
        x = a;
        y = b;
        z = c;
        if(((x * x) + (y * y)) == (z * z)) printf("right\n");
        else if(((x * x) + (z * z)) == (y * y)) printf("right\n");
        else if(((z * z) + (y * y)) == (x * x)) printf("right\n");
        else printf("wrong\n");
        scanf("%d %d %d", &a, &b, &c);
    }

    return 0;
}
