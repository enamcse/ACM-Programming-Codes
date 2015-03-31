#include <stdio.h>
#define PI 3.1415926535897932384626433832795028841971693993751

int main()
{
    int t;
    double w, l, r, green, area, red;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lf", &l);
        w = 6 * l / 10;
        r = l / 5;
        area = l * w;
        red = PI * r * r;
        green = area - red;
        printf("%.2lf %.2lf\n", red, green);
    }
    return 0;
}
