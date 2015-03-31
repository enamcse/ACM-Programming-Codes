#include <stdio.h>
int max(int i, int j);
int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    //min = a < b ? (a < c ? a : b )
    printf("%d", max(c,max(a,b)));
    return 0;
}

int max(int i, int j)
{
    int p;
    p = i>j?i:j;
    return p;


}
