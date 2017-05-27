/**
* H:\Dropbox\Code\Codemarshal\CSE Week 2015 Online Contest\H.cpp
* Created on: 2015-12-11-16.44.16, Friday
* Verdict: Not Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define SZ(a) ((int)a.size())
#define sz 200005
#define pb push_back
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
#define cntbit(mask) __builtin_popcount(mask)
#define unify(a) stable_sort(a.begin(),a.end());a.resize(distance(a.begin(),unique(all(a))));
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e9)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define pi 3.14159265358979323846264338327950288419716939937510
#define fr(i,a,b) for(i=a;i<=b;i++)
#define cspf printf("Case %d: ", cas++);
#define csco cout<<"Case "<<cas++<<": ";
#define mod 1000000007
ll bigmod(ll sonkha,ll ghat,ll vag_const)
{
    ll vag_shesh=1;
    while(ghat>0)
    {
        if(ghat%2==1)
        {
            vag_shesh=(vag_shesh*sonkha)%vag_const;
        }
        ghat/=2;
        sonkha=(sonkha*sonkha)%vag_const;
    }
    return vag_shesh;
}
ll inverse_mod(ll bivajok, ll vag_const)
{
    return bigmod(bivajok,vag_const-2, vag_const);
}

using namespace std;

struct point
{
    ll x, y;
    point() {}
    point(ll a, ll b) : x(a), y(b) {}
    bool operator < (const point &p) const
    {
        if (x == p.x)
            return y < p.y;
        return x < p.x;
    }
};

bool check(vector<point> &p, ll cur, int s, ll d)
{
    vector<point> dist(p.size());
    for (int i = 0; i < p.size(); ++i)
    {
        ll h = p[i].y - cur;
        if (h > d)
            return false;
        ll delta = sqrt(1.0 * d * d - 1.0 * h * h);
        dist[i] = point(p[i].x + delta, p[i].x - delta);
    }
    sort(all(dist));
    int cnt = 0, i = 0;
    while (i < p.size())
    {
        ll cur = dist[i].x;
        while (dist[i].y <= cur && i < p.size())
            i++;

        cnt++;
        if (cnt > s)
            return false;
    }
    return cnt <= s;
}

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    int t,cas=1;
    ll k, n, s, d;
    cin>>t;

    while(t--)
    {

        cin >> k >> n >> s >> d;
        csco
        vector<point> p(n);
        for (int i = 0; i < n; ++i)
            cin >> p[i].x >> p[i].y;

        sort(all(p));

        if (!check(p, k, s, d))
        {
            cout<<"IMPOSSIBLE\n";
            continue;
        }
        ll lo = k - d - 10, hi = k, mid;
        while (lo < hi)
        {
            if (lo + 1 == hi)
            {
                if (check(p, lo, s, d))
                    hi = lo;
                break;
            }
            mid = (lo + hi) / 2;
            if (check(p, mid, s, d)) hi = mid;
            else lo = mid + 1;
        }

        cout<<(k - hi)<<"\n";
    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}
