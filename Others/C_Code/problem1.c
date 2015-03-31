#include <stdio.h>

int main()
{
    int a, b, c,d;
    float e, f;
    printf("a = ?");
    scanf("%d",&a);

    printf("b = ?");
    scanf("%d",&b);

    printf("c = ?");
    scanf("%d",&c);

    printf("d = ?");
    scanf("%d",&d);


    e=d-a;

    {
        if (e>=1)
            f=a+b*c/e, printf("%.2f",f);
        else if (e==0)
            printf("calculation error: d-a = 0");
        else f=a+b*c/e, printf("%.2f",f);
    }
    return 0;
}
