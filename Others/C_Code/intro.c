#include <stdio.h>
int main()
{
    float radius, area; /*memory allocation*/
    printf("Radius = ? "); /*output*/
    scanf("%f", &radius);
    area = 3.14159 * radius * radius; /*work of micro processor*/
    printf("Area = %f", area);
    return 0;
}
