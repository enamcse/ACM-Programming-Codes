/**
* H:\Dropbox\Code\UVa\12832 - Chicken Lover.cpp
*
* Created on: 2014-11-04-18.56.35, Tuesday
* Author: Enamul Hassan
* Verdict: SOLVED
**/

#include <bits/stdc++.h>
//#define _ ios_base::sync_with_stdio(0);cin.tie(0);


#define sz 100005
#define pb(a) push_back(a)
#define pp pop_back()
#define all(a) a.begin(),a.end()
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

ll mygcd ( ll a, ll b )
{
    ll c;
    while ( a != 0 )
    {
        c = a;
        a = b%a;
        b = c;
    }
    return b;
}

char line[60010];
int lim;
int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1, k;
    ll up, down, gcd;
    fgets(line,5,stdin);
    sscanf(line,"%d", &t);

    while(t--)
    {
        lim=0;
        fgets(line,10,stdin);
        sscanf(line,"%d", &m);
        up = 0;
        down = 1;
        fgets(line,60010,stdin);
        while(m--)
        {
            sscanf(line+lim,"%d %d", &n, &k);
            up = up*n + down*k;
            down *=n;
            gcd = mygcd(up, down);
            up/=gcd;
            down/=gcd;
            while(line[lim]>='0' && line[lim]<='9') lim++;
//            lim--;
            while(!(line[lim]>='0' && line[lim]<='9'))lim++;
//            lim--;
            while(line[lim]>='0' && line[lim]<='9') lim++;
//            lim--;
            while(!(line[lim]>='0' && line[lim]<='9'))lim++;
//            lim--;
        }
        printf("Case %d: %lld/%lld\n", cas++,up, down);

    }


    return 0;
}
