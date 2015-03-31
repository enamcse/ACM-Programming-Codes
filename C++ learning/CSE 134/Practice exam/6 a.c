#include <stdio.h>
//#define swaps(x,y) x^=y^=x^=y;

void swap(int *p, int *q, int *r);

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
/*    swaps(a, b)
    swaps(a, c)

    printf("%d %d %d", a, b, c);*/
    swap(&a,&b,&c);
    printf("%d %d %d\n", a, b, c);
    return 0;
}

void swap(int *p, int *q, int *r)
{
    int a = *p, b = *q, c = *r;
    *p = c;
    *q = a;
    *r = b;
    printf("%d %d %d\n", *p, *q, *r);
    return;
}
