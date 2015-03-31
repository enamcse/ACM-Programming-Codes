#include <bits/stdc++.h>

#define sz 50005
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

int main()
{
    pair<int, int> p[4];

    while(~scanf("%d", &p[0].first))
    {
        scanf("%d", &p[0].second);
        for (int i = 1; i<4; i++)
            scanf("%d %d", &p[i].first, &p[i].second);

        int i = 0;

        for (; i<4; i++)
            if(p[i].first||p[i].second) break;

        if(i==4) break;

        pair<ll,ll>a,b,c,u,d, m;

        m.first = p[0].first+p[2].first;
        m.second = p[0].second+p[2].second;

        a.first = p[0].second - p[1].second;
        b.first = p[1].first - p[0].first;
        c.first = p[0].first*(-a.first) + p[0].second * (-b.first);
        u.first = (a.first*m.first+b.first*m.second+ 2*c.first);
        d.first = a.first*a.first+b.first*b.first;
        u.first*=u.first;
        d.first*=4;

        a.second = p[1].second - p[2].second;
        b.second = p[2].first - p[1].first;
        c.second = p[1].first*(-a.second) + p[1].second * (-b.second);
        u.second = (a.second*m.first+b.second*m.second+ 2*c.second);
        d.second = a.second*a.second+b.second*b.second;
        u.second*=u.second;
        d.second*=4;

        ll temp = __gcd(u.first, d.first);
        u.first/=temp;
        d.first/=temp;

        temp = __gcd(u.second, d.second);
        u.second/=temp;
        d.second/=temp;

        if(u.first*d.second<=u.second*d.first) printf("(%lld/%lld)*pi\n", u.first, d.first);
        else printf("(%lld/%lld)*pi\n", u.second, d.second);

    }



    return 0;
}
