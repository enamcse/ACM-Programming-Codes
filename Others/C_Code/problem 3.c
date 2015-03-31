#include <stdio.h>

int main()
{
    int x1, y1, x2, y2, x3, y3, x4, y4;

    printf("A(x,y)?");
    scanf("%d%d",&x1,&y1);

    printf("B(x,y)?");
    scanf("%d%d",&x2,&y2);

    printf("C(x,y)?");
    scanf("%d%d",&x3,&y3);

    x4=x3;
    y4=y1;

    if ((((x3-x2)*(x3-x2))+((y3-y2)*(y3-y2)))==(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1))))
            printf("(%d,%d)",x4,y4);
        else printf("This doesnt make a square!");
    return 0;

}
