#include <stdio.h>

int main()
{
    long int i, t, x, y, z;

    scanf("%ld", &t);
    for (i = 1; i <= t; i++)
    {
        scanf("%ld %ld %ld", &x, &y, &z);
        if (x>0&&y>0&&z>0)
        {
            if (x+y<=z || y+z<=x || x+z<=y) printf("Case %d: Invalid\n", i);
            else if (x == y && y == z) printf("Case %d: Equilateral\n", i);
            else if ((x == y && x != z) || (y == z && y != x) || (x == z && z != y))
                printf("Case %d: Isosceles\n", i);
            else printf("Case %d: Scalene\n", i);
        }
        else printf("Case %d: Invalid\n", i);
    }
    return 0;
}
