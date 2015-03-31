#include <stdio.h>
#define PI 3.14159

float process (float radius);

int main()
{
    float radius, area;
    int count;
    printf("To STOP, enter 0 for radius\n");
    printf("Radius = ? ");
    scanf("%f", &radius);

    for (count = 1; count != 0; ++count)
    {
        if (radius < 0)
            area = 0;
        else
            area = process (radius);
        printf("Area = %f\n", area);

    }
}

float process (float r)
{
    float a;
    a = PI * r * r;
    return (a);
}

