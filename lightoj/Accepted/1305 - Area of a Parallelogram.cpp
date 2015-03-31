#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 100
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
using namespace std;

int main()
{
    _
    int t,cas=1,x[4],y[4],area,xa,xb,ya,yb;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d %d %d %d",&x[0],&y[0],&x[1],&y[1],&x[2],&y[2]);
        x[3] = x[0]+x[2]-x[1];
        y[3] = y[0]+y[2]-y[1];
        xa = x[2] - x[3];
        ya = y[2] - y[3];
        xb = x[0] - x[3];
        yb = y[0] - y[3];

        area = abs(xa*yb - ya*xb);
        printf("Case %d: %d %d %d\n",cas++,x[3],y[3],area);
    }
    return 0;
}
