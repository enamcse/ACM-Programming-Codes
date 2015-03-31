#include <stdio.h>

int main()
{
    int t, lost, me, lift ,caseno=0;

    scanf("%d",&t);
    while(t--)
    {
        lost = 19;
        scanf("%d %d",&me,&lift);
        if(me-lift>0) lost+=(4 * (me-lift));
        else lost+=(4 * (lift-me));
        lost += (4 * me);
        printf("Case %d: %d\n",++caseno, lost);
    }

    return 0;
}
