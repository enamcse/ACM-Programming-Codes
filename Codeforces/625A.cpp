/**
* E:\Dropbox\Code\Codeforces\625A.cpp
* Created on: 2016-02-07-15.01.50, Sunday
* Verdict: Not Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define SZ(a) ((ll)a.size())
#define sz 200005
#define pb push_back
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
#define cntbit(mask) __builtin_popcount(mask)
#define unify(a) stable_sort(a.begin(),a.end());a.resize(distance(a.begin(),unique(all(a))));
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e18)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define pi 3.14159265358979323846264338327950288419716939937510
#define fr(i,a,b) for(i=a;i<=b;i++)
#define cspf printf("Case %d:", cas++);
#define csco cout<<"Case "<<cas++<<": ";
#define mod 1000000007
#define mp make_pair
using namespace std;

#define paii pair<ll,ll>

//ax+by=1
paii egcd ( ll a, ll b )
{
	if (b == 1)
		return mp(0, 1);
	paii ret = egcd(b%a, a);
	int p = ret.second-(b/a)*ret.first, q = ret.first;
	p %= b; //for overflow

	//cout << a << "*" << p << " + " << b << "*" << q << " = 1\n";
	return mp(p, -(a*p-1LL)/b);
}

//ax+by=c
bool find_any_solution( ll a , ll b, ll c, ll &x0 , ll &y0 , ll &g)
{
    if( !a && !b ) return !c;
    g=__gcd(a,b);
    if( (c%g)!=0 )
        return false;
    a/=g;
    b/=g;
    c/=g;
    paii ret=egcd(abs(a), abs(b));
    x0=ret.first;
    y0=ret.second;

    x0 = (x0*(c%b))%b;
    y0 = (c-a*x0)/b;
    if( a<0 ) x0*= -1;
    if( b<0 ) y0*= -1;

    return true;
}

void shift_solution( ll &x , ll &y , ll a, ll b, ll cnt) {
    x+= cnt*b;
    y-= cnt*a;
}

// ax+by=c;
ll find_all_solutions (ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy) //mainly takes the range
{
    ll x, y, g;

    if (!find_any_solution (a, b, c, x, y, g))
        return 0;
    if(!a&&!b)
       return (maxx-minx+1)*(maxy-miny+1);

    if(a&&!b)
    {
       x=c/a;
       if(x<minx||x>maxx) return 0;
       return maxy-miny+1;
    }

    if(!a&&b)
    {
       y=c/b;
       if(y<miny||y>maxy) return 0;
       return maxx-minx+1;
    }

    a /= g; b /= g;

    ll sign_a = a> 0?  1: - 1;
    ll sign_b = b> 0?  1: - 1;

    shift_solution (x, y, a, b, (minx - x) / b);
    if (x <minx)
        shift_solution (x, y, a, b, sign_b);
    if (x> maxx)
        return 0LL;
    ll lx1 = x;

    shift_solution (x, y, a, b, (maxx - x) / b);
    if (x> maxx)
        shift_solution (x, y, a, b, - sign_b);
    ll rx1 = x;

    shift_solution (x, y, a, b, - (miny - y) / a);
    if (y <miny)
        shift_solution (x, y, a, b, - sign_a);
    if (y> maxy)
        return 0LL;
    ll lx2 = x;

    shift_solution (x, y, a, b, - (maxy - y) / a);
    if (y> maxy)
        shift_solution (x, y, a, b, sign_a);
    ll rx2 = x;

    if (lx2> rx2)
        swap (lx2, rx2);
    ll lx = max (lx1, lx2);
    ll rx = min (rx1, rx2);

    return max(0LL,(rx - lx) / abs (b) + 1);
}

int main()
{
	long long x,y,a,b,c,mx;
    cin>>a>>b>>c;
    mx = 0;
    for (x = 0; a*x<=c; x++)
    {
        y = c - a*x;
        if(y<0||y%b) continue;
        y/=b;
        mx = max(mx, x+y);
    }

    cout<<mx<<endl;
    cout<<"Ans = "<<find_all_solutions(a,b,c,0,c,0,c)<<endl;
    ll m;
    ll ap = a/__gcd(a,b), bp = b/__gcd(a,b);
    paii k = egcd(ap,bp );
    cout<<"Ans@ = "<<k.first<<" "<<k.second<<" "<<c/__gcd(a,b)<<endl;
   return 0;
}
/**
12 15 249
*/
