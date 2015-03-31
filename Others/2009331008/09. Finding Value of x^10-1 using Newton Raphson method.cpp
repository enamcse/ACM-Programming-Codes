
#include<stdio.h>
#include<math.h>

main()
{
    double x = 0.5;              // Initial guess
    int i=0;

    printf(" Iteration              X\n\n");

    while(1)
    {
        printf("%4d", i);
        printf("%30.15lf\n", x);
        x=x-(pow(x, 10)-1)/(10*pow(x, 9));
        i++;
        if(i==41) break;
    }
    printf("Here it is converging on the true root of 1.00000, but it is very slow rate.\n I think after more iteration it will reach in the true root.\n");
}
