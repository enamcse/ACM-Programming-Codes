#include <stdio.h>
#define PI 3.14159
int main()
{
    float redius, square, circle, area;
    printf("Radius?");
    scanf("%f", &redius);
    square = (2*redius) * (2*redius);
    circle = PI * redius * redius;
    area = square - circle;
        if (redius >=0)
    printf("The rest area is %.2f", area);
        else printf("Radius cant be less than 0");
    return 0;
}
