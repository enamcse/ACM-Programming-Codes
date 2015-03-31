#include <stdio.h>

int main()
{
    float cent;
    float fern;
    printf("What is the value of temperature in centrigrade?: ");
    scanf("%f", &cent);
    fern = 32 + 1.8 * cent;
    printf("The converted temperature in Farenhite scale is: %f",fern);
}
