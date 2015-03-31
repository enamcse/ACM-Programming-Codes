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
    unsigned int n,t,cas=1, cnt, k;
    scanf("%u", &t);
    while(t--)
    {
        scanf("%u", &n);
        k=(1<<31);
        cnt=0;
        while(k)
        {
            if((n&k)!=0) cnt++;
            k>>=1;
        }
        if(cnt%2) printf("Case %u: odd\n", cas++);
        else printf("Case %u: even\n", cas++);
    }
    return 0;
}
