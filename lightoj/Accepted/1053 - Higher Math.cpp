#include <stdio.h>

int main()
{
    int a,b,c,t,caseno=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&a, &b, &c);
        if((a*a+b*b) == c*c) printf("Case %d: yes\n",++caseno);
        else if((a*a+c*c) == b*b) printf("Case %d: yes\n",++caseno);
        else if((c*c+b*b) == a*a) printf("Case %d: yes\n",++caseno);
        else printf("Case %d: no\n",++caseno);
    }

    return 0;
}
