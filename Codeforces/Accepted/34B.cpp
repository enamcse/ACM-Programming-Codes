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

vector<int>mon;

int main()
{
    _
    int n, m, money=0,x;
    cin>>n>>m;
    for (int i =0; i<n; i++)
    {
        cin>>x;
        if(x<0) mon.pb(-x);
    }
    sort(mon.begin(),mon.end());
    for (int i =mon.size()-1; i>=0&&m; i--,m--)
    {
        money+=mon[i];
    }
    cout<<money;
    return 0;
}
