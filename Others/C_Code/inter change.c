#include <stdio.h>

int main()
{
    int i;
    float f;
    double d;
    char c;

    scanf("%d",&i);
    c=d=f=i;
    printf("The number is in\ninteger:%d\nfloating type:%.555f\ndouble type:%.4000f\ncharacter type:%c\n", i, f, d, c);

    return 0;
}
