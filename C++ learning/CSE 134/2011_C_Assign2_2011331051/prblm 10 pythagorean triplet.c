#include <stdio.h>
#include <math.h>

int main()
{
    int x, y, z, x2, y2, z2, a, b, m, n, count = 0, flag = 0, p;

    printf("range : x to y (write two numbers separated by space) :");
    scanf("%d %d", &m, &n);

    for (x = 1; x <= n; x++)
    {
        x2 = pow(x, 2);
        for (y = x + 1; y <= n; y++)
        {
            y2 = pow(y, 2);
            for (z = y + 1; z <= n; z++)
            {
                z2 = pow(z, 2);
                a = z2;
                b = x2 + y2;
                if (a == b && z > m && z <= n)
                {
                    flag = 0;
                    for (p = 2; p <= x; p++)
                    {
                        if ((x % p) == 0 && (y % p) == 0 && (z % p) == 0) flag = 1;
                    }
                    if (flag == 0) printf("Pythagorean triplet no. %d : %d, %d, %d\n", ++count, x, y, z);
                }
            }
        }
    }
    if (count == 0) printf("There is no Pythagorean triplet in this range!\n");
    else printf("The number of Pythagorean triplet is : %d\n", count);
    return 0;
}
