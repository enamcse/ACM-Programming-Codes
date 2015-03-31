#include <stdio.h>

int main()
{
    int flag;
    double x, y;

    printf("Enter the value of x : ");
    scanf("%lf", &x);

    printf("press -1 : absolute value of x,\n");
    printf("press  0 : square of x,\n");
    printf("press  1 : the value of x,\n");
    printf("press 2 or 3 : the value of 2*(x-1),\n");
    printf("press any other key : null value.\n\n");
    printf("press your choice from the above : ");
    scanf("%d", &flag);

    switch (flag)
    {
    case -1:
        y = abs(x);
        break;

    case 0:
        y = sqrt(x);
        break;

    case 1:
        y = x;
        break;

    case 2:
    case 3:
        y = 2 * (x -1);
        break;

    default:
        y = 0;
        break;
    }

    printf("Your desired value is : %lf", y);

    return 0;
}
