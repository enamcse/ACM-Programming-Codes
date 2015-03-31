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

int ab=0, bc=0, ca=0;

int main()
{
    _
    int a,b,c, x, y,yy, z,zz, fact;
    bool flag = false;
    cin>>a>>b>>c;
    if((a+b+c)&1)
    {
        cout<<"Impossible";
        return 0;
    }
    else if(a==b&&b==c)
    {
        x = (a>>1);
        cout<<x<<" "<<x<<" "<<x;
        return 0;
    }
    for (int i =0; i<=a; i++)
    {
        ab = i;
        ca=a-i;
        bc =c - ca;
        if(ab<0||bc<0||ca<0) continue;
        if(bc == b - ab)
        {
            if(ab||bc||ca)
            {
                flag = true;
                break;
            }
        }
    }
    if(flag)cout<<ab<<" "<<bc<<" "<<ca;
    else cout<<"Impossible";
    return 0;
}
