#include <stdio.h>

int main()
{
    float c, a, b;
    b = 3.14159;
    printf("Write the value of the circle: ");
    scanf("%f", &c);
    a = b * c * c;
    printf("\nThe radius of the circle is %f \nAnd the area  is %f", c, a);
}
