#include <stdio.h>

int recur(int a, int b)
{
    if(b <= 0)
        return 1;
    int n = a + b;
    printf("a = %d b = %d res = %d\n",a,b,n);
    n = recur(b+1, a%b) + recur(b-1, (a%b)-1);
    printf("a = %d b = %d res = %d\n",a,b,n);
    return n;
}

int main()
{
    recur(2,4);
}
