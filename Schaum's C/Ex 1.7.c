/*program to calculate the area of a circle*/

#include <stdio.h>
#define PI 3.14159

float process(float radius);                    /*FUNCTION PROTOTYPE*/

main()
{
    float radius, area;                         /* VARIABLE DECLARATION */

    printf("Radius = ?");
    scanf("%f", &radius);
    area = process(radius);
    printf("Area = %f", area);
}

float process(float r)                          /*FUNCTION DEFINITION*/
{
    float a;                                    /*LOCAL VARIABLE DECLARATION*/

    a = PI * r * r;
    return(a);
}
