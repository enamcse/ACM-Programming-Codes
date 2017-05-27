
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
#define inf (1e18)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define pi 3.14159265358979323846264338327950288419716939937510
#define fr(i,a,b) for(i=a;i<=b;i++)
#define cspf printf("Case %d:", cas++);
#define csco cout<<"Case "<<cas++<<":";
#define mod 1000000007

#ifdef ENAM
#define deb(args...) {dbg,args; cerr<<endl;}
#else
#define deb(args...)
#endif

struct debugger {
    template<typename T> debugger& operator ,(const T& v) {
        std::cerr << v << " ";
        return *this;
    }
} dbg;

ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

map<ll,ll>mpp,indx;

ll prod=1,ans=1,fw[sz],bw[sz];

int main()
{
	_
	ll n,m,y,k;
	
	cin>>n;

	for(int i = 0; i<n; i++)
	{
		cin>>m;
		mpp[m]++;
	}
	
	
	m=0;
	for(auto &x: mpp)
	{
		prod*=(x.second+1);
		prod%=(mod-1);
		fw[m]=prod;
		indx[x.first]=m++;
	}

	prod = 1;

	for(map<ll,ll>::reverse_iterator x = mpp.rbegin(); x!=mpp.rend(); x++)
	{
		prod*=((x->second)+1);
		prod%=(mod-1);
		bw[indx[(x->first)]] = prod;
	}
	
	for(auto &x: mpp)
	{
		y = x.second;
		k = y++;
		if(y&1LL)k/=2;
		else y/=2;
		y=(k*y)%(mod-1);
		if(indx[x.first] >0)y=(fw[ indx[x.first]-1 ]*y)%(mod-1);
		if(indx[x.first]+1 < m)y=(bw[ indx[x.first]+1 ]*y)%(mod-1);
		ans*=(bigmod(x.first,y,mod));
		//ans+=mod;
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}


