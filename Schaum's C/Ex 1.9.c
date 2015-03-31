/*program to calculate the areas of circles, using a for loop*/

#include <stdio.h>

#define PI 3.14159

float process (float radius);           /*function prototype declaration*/

int main()
{
    float radius, area;                 /*variable declaration*/
    int count, n;                       /*variable declaration*/

    printf("How many circles? ");
    scanf("%d", &n);

    for (count = 1; count <= n; ++count)
    {
        printf("\nCircle no. %d:    Radius = ? ", count);
        scanf("%f", &radius);

        if (radius < 0)
            area = 0;
        else
            area = process (radius);

        printf("Area = %f\n", area);
    }
    return 0;
}

float process (float r)                 /*function definition*/
{
    float a;                            /*local variable declaration*/
    a = PI * r * r;
    return a;
}
