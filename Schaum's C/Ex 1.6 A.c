/*program to calculate the area of a circle*/
#include <stdio.h>
main()
{
    float radius, area;

    printf("Radius = ?\n");
    scanf("%f", &radius);

    area = 3.14159 * radius * radius;

    printf("Area = %f", area);

    return 0;
}
