/*program to calculate the area of a circle,with error checking*/

#include <stdio.h>
#define PI 3.14159

float process(float radius);                    /*FUNCTION PROTOTYPE*/

main()
{
    float radius, area;                         /* VARIABLE DECLARATION */

    printf("Radius = ?");
    scanf("%f", &radius);

    if (radius < 0)
        area = 0;

    else
    area = process(radius);

    printf("Area = %f", area);
}

float process(float r)                          /*FUNCTION DEFINITION*/
{
    float a;                                    /*LOCAL VARIABLE DECLARATION*/

    a = PI * r * r;
    return(a);
}
