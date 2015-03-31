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

int num[1001], c[1001];
int main()
{
    _
    int n, h=0, cnt=0, in,k;
    scanf("%d", &n);
    for (int i =0; i<n; i++)
    {
        scanf("%d",&in);
        num[in]++;
    }
    for (int i = 0; i<1001; i++)
    {
        if(num[i]>0)cnt++;
        c[i] = num[i]*i;
        h = num[i]>h?num[i]:h;
    }
    for (int i = 0; i<1001; i++)
    {
//        cout<<num[i]<<" : "<<i<<endl;
        if(h==num[i])
        {
            printf("%d %d", num[i],cnt);
            break;
        }
    }
    return 0;
}
