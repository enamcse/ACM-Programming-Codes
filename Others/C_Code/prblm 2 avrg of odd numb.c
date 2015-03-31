#include <stdio.h>

int main()
{
    int n,i=1, mod, n_odd = 0, numb, numb2;
    double sum = 0, avg;

    printf("How many numbers :");
    scanf("%d", &n);

    while (i <= n)
    {
        printf("Number %d is : ",i++);
        scanf("%d", &numb);

        numb2 = numb;

        if (numb < 0) numb2 = -numb2;

        mod = numb2 % 2;

        if (mod == 1)
        {
            n_odd++;
            sum = sum + numb;
        }
    }
    if (n_odd == 0) printf("No Odd number found!");
    else
    {
        avg = sum / n_odd;
        printf("Average of Odd numbers is: %.2lf\n", avg);

    }

    return 0;
}
