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

int node[100001];

int main()
{
    _
    int n, a, b, m;
    scanf("%d %d", &n, &m);
    while(m--)
    {
        scanf("%d %d", &a, &b);
        node[a]++;
        node[b]++;
    }
    a=b=m=0;
    for (int i =0; i<100001; i++)
    {
        if(node[i]==1) a++;
        else if(node[i]==2) b++;
        else if(node[i]==n-1) m++;
    }
    if(a==2&&n-2==b) printf("bus topology");
    else if(b==n) printf("ring topology");
    else if(a==n-1&&m==1) printf("star topology");
    else printf("unknown topology");
    return 0;
}
