#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 1000001
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
using namespace std;

double csum[sz];

int main()
{
    _
    int n, t, cas=1, base,ans;
    for (int i =1; i<sz; i++)
        csum[i] = csum[i-1]+log10((double)i);
    scanf("%d", &t);

    while(t--)
    {
        scanf("%d %d", &n, &base);
        ans = (csum[n]/log10((double)base))+1;
        printf("Case %d: %d\n", cas++,ans);
    }
    return 0;
}
