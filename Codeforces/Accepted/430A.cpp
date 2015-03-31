#include <bits/stdc++.h>

#define sz 55
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e9)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
using namespace std;

struct data{
    int pos, val, ans;
    data(int a, int b, int c)
    {
        pos = a;
        val = b;
        ans = c;
    }
};

bool comp(data a, data b)
{
    return a.val<b.val;
}
bool comp2(data a, data b)
{
    return a.pos<b.pos;
}

vector<data>v;

int main()
{
    #ifdef ENAM
//    	fread;
//	fwrite;
    #endif // ENAM
    int t, n, m, cas=1;

    scanf("%d %d", &n, &m);
    for (int i = 0; i<n; i++)
    {
        scanf("%d", &t);
        v.pb(data(i,t,0));
    }

    sort(v.begin(),v.end(),comp);
    v[0].ans=0;
    for (int i = 1; i<n; i++)
        v[i].ans = (v[i-1].ans^1);
    sort(v.begin(),v.end(),comp2);
    for (int i = 0; i<n; i++)
        printf("%d ", v[i].ans);

    return 0;
}
