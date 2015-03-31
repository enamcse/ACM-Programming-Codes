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

int rr[8] = {-1,-1,-1,1,1,1,0,0};
int cc[8] = {-1,0,1,-1,0,1,-1,1};

int main()
{
    _
    int n, x, y, s;
    cin>>n>>x>>y;
    s = (n>>1);
    if((x==s&&(y==s||y==(s+1)))||(x==(s+1)&&(y==s||y==(s+1)))) cout<<"NO";
    else cout<<"YES";
    return 0;
}
