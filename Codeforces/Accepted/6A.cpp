#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 100
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
using namespace std;

vector<int>v;

int main()
{
    _
    int a;
    for (int i = 0; i<4; i++)
    {
        cin>>a;
        v.pb(a);
    }
    sort(v.begin(), v.end());
    if(v[3]<v[1]+v[2]||v[2]<v[1]+v[0]) cout<<"TRIANGLE";
    else if (v[3]==v[1]+v[2]||v[2]==v[1]+v[0]||v[3]==v[0]+v[1]) cout<<"SEGMENT";
    else cout<<"IMPOSSIBLE";
    return 0;
}
