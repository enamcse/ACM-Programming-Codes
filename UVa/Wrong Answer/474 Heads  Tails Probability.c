#include <stdio.h>

int main()
{
    int power, i = 0;
    double numb, inverse = 1;

    while (scanf("%d", &power) == 1)
    {
        while ( i < power)
        {
            inverse = inverse * 2;
            i++;
        }

        numb = 1 / inverse;
        printf("2^-%d = %.3e\n", power, numb);
        inverse = 1;
    }
    return 0;
}
