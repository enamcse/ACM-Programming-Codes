/*program to calculate the areas of circles, using a while loop;
  the number of circles is unspecified */

#include <stdio.h>

#define PI 3.14159

float process (float radius);           /*function prototype declaration*/

int main()
{
    float radius, area;                 /*variable declaration*/

    printf("To STOP, enter 0 for the radius\n");
    printf("\nRadius = ? ");
    scanf("%f", &radius);

    while (radius != 0)                 /*only 'radius' is sufficient in bracket*/
    {
        if (radius < 0)
            area = 0;
        else
            area = process (radius);

        printf("Area = %f\n", area);

        printf("\nRadius = ? ");
        scanf("%f", &radius);
    }
    return 0;
}

float process (float r)                 /*function definition*/
{
    float a;                            /*local variable declaration*/
    a = PI * r * r;
    return a;
}
