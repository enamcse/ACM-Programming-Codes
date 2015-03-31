#include <stdio.h>

int main()
{
    int n, GCD, LCM;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d %d", &GCD, &LCM);
        if(LCM%GCD==0) printf("%d %d\n", GCD, LCM);
        else printf("%d\n", -1);
    }

    return 0;
}
