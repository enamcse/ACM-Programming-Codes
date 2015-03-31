#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 1001
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
using namespace std;

int num[sz];
vector<int>v;

struct data
{
    int a,b;
    bool operator < (const data &x) const
    {
        if(x.a==a) return x.b > b;
        else return x.a < a;
    }
    data(int p, int q)
    {
        a = p;
        b = q;
    }
};

priority_queue<data>q;

void pre()
{
    int k;
    num[1] = 1;
    for (int i=2; i<1001; i++)
        num[i]=2;
    for (int i = 2; i<1001; i++)
    {
        k=(i<<1);
        while(k<1001)
        {
            num[k]++;
            k+=i;
        }
    }
    for (int i = 1; i<1001; i++)
    {
        q.push(data(num[i],i));
//        cout<<i<<" : "<<num[i]<<endl;
    }
    v.pb(0);
    while(!q.empty())
    {
        v.pb(q.top().b);
        q.pop();
    }
    return;
}

int main()
{
    _
    pre();
    int n, t, cas=1;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        printf("Case %d: %d\n",cas++,v[n]);
    }
    return 0;
}
