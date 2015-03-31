#include <stdio.h>
#define PI 3.14159
float process(float radius);

main()
{
    float radius, area;
    printf("Radius = ?");

    scanf("%f",&radius);

    if(radius < 0)
        area = 0;
    else
        area = process(radius);
    printf("Area = %f", area);
}

float process(float r)
{
    float a;
    a= PI * r *r;
    return(a);
}
