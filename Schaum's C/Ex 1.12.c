/*program to calculate the areas of circles, using a while loop;
  the results are sorted in an array; the number of circles is unspecified */

#include <stdio.h>

#define PI 3.14159

float process (float radius);           /* function prototype declaration */

int main()
{
    int n, i = 0;                                    /* variable declaration */
    float radius[100], area[100];                   /* array declaration    */

    printf("To STOP, enter 0 for the radius\n\n");
    printf("Radius = ? ");
    scanf("%f", &radius[i]);

    while (radius[i])
    {
        if (radius[i] < 0)
            area[i] = 0;
        else
            area[i] = process (radius[i]);

        printf("\nRadius = ? ");
        scanf("%f", &radius[++i]);
    }

    n = --i;                            /* tag the highest value of i */

    /* display the array elements */
    printf("\nSummury of Results\n\n");
    for (i = 0; i <= n; ++i)
        printf("Radius = %f Area = %f\n", radius[i], area[i]);
    return 0;
}

float process (float r)                 /* function definition  */
{
    float a;                            /* local variable declaration   */
    a = PI * r * r;
    return a;
}
