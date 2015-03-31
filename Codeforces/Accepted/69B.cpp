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

int l[sz],r[sz], t[sz],c[sz];

int main()
{
    _
    int n, m, money=0,cur=0, mn = inf;
    cin>>n>>m;
    for (int i =0; i<m; i++)
        cin>>l[i]>>r[i]>>t[i]>>c[i];
    for (int i=1; i<=n; i++)
    {
        mn = inf;
        cur=0;
        for (int j =0; j<m; j++)
        {
            if(i>=l[j]&&i<=r[j]&&mn>t[j])
            {
                mn = t[j];
                cur = c[j];
            }
        }
        money+=cur;
    }
    cout<<money;
    return 0;
}
