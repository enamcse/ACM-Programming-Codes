#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main()
{
    _
    int x1,x2,y,t,cas=1, r;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &r);
        x1 = (r>>2) * 11;
        x2 =  -(r>>2) * 9;
        y = (r>>1) * 3;
        printf("Case %d:\n%d %d\n%d %d\n%d %d\n%d %d\n",cas++,x2,y,x1,y,x1,-y,x2,-y);
    }
    return 0;
}
