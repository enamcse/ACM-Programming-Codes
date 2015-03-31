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
    int n,cas=1,p[6],k;
    double OA,AB,L;
    scanf("%d",&n);
    while(n--)
    {
        k=6;
        while(k--)
        {
            scanf("%d",&p[k]);
        }
        OA = (double)((p[5]-p[3])*(p[5]-p[3])+(p[4]-p[2])*(p[4]-p[2]));
        AB = (double)((p[1]-p[3])*(p[1]-p[3])+(p[0]-p[2])*(p[0]-p[2]));
        L = sqrt(OA) * acos((1-(AB/(2*OA))));
        printf("Case %d: %lf\n",cas++,L);
    }
    return 0;
}
