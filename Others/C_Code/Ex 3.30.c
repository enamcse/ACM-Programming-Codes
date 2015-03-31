#include <stdio.h>
#include <math.h>


int main()
{
    int a,b,c,root;
    double x1,x2;

    printf("a?\n");
    scanf("%d",&a);

    printf("b?\n");
    scanf("%d",&b);

     printf("c?\n");
    scanf("%d",&c);

    root = sqrt(b*b-4*a*c);
    x1 = (-b+root)/(2*a);
    x2 = (-b-root)/(2*a);

    printf("The root of the equation %dx2 + %dx + %d = 0 are %.2lf and %.2lf",a,b,c,x1,x2);

    return 0;
}
