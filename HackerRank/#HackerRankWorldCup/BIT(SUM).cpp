#include <sstream>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <complex>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <string.h>
#include <assert.h>
#include <time.h>

using namespace std;

#define SZ(x) ((int)x.size())
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define clrall(name,val) memset(name,(val),sizeof(name));
#define EPS 10e-9
#define ll long long
#define ull long long unsigned
#define SF scanf
#define PF printf
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo (1ll<<61)
#define mp make_pair
#define mt make_tuple
#define get(a,b) get<b>(a)
#define fs first
#define sc second
#define rep(var,s,n,it) for(var=(s);var<(n);(var)+=it)
#define rev(var,s,n,it) for(var=(n-1);var>(s-1);(var)-=it)
#define Read freopen("in.txt","r",stdin)
#define Write freopen("out.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

ll BigMod(ll B,ll P,ll M){     ll R=1; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

template<class T1> void deb(T1 e1){cout<<e1<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}

//int dx[]= {-1,-1,0,0,1,1};
//int dy[]= {-1,0,-1,1,0,1};
//int dx[]= {0,0,1,-1};/*4 side move*/
//int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/


///0 based indexing

const int MAX = 100050;
const int M = 1000000007;

int tree[MAX],bitN;

void init (int n)
{
	bitN = n;
	clrall(tree,0);
}
///for min or max use result = min/max(result,tree[r]);
inline int query (int r)
{
	int result = 0;
	for (; r >= 0; r = (r & (r+1)) - 1)
    {
        result = (result + tree[r]);
        if(result>=M) result-=M;
    }
	return result;
}

inline int query (int l, int r)
{
	return ((query (r) - query (l-1))%M + M)%M;
}
///for min or max use tree[i] = min/max(tree[i],delta);
inline void update (int i, int delta)
{
    for (; i < bitN; i = (i | (i+1)))
    {
        tree[i] = (tree[i] + delta);
        if(tree[i]>=M) tree[i]-=M;
    }
}

int val[MAX],idx[MAX];

inline bool comp(const int &a,const int &b)
{
    if(val[a]==val[b]) return a>b;
    return val[a]<val[b];
}

int main()
{
    int test,cas=0,value,tmp,ans;
    SF("%d",&test);
    while(test--)
    {
        init(bitN);
        SF("%d",&bitN);
        for(int i=0;i<bitN;i++) SF("%d",&val[i]);
        for(int i=bitN-1;i>-1;i--) idx[i]=i;
        sort(idx,idx+bitN,comp);
        ans=0;
        for(int i=0;i<bitN;i++)
        {
            value=query(idx[i]-1);
            ans+=value+1;
            if(ans>=M) ans-=M;
            update(idx[i],(value+1));
        }
        PF("Case %d: %d\n",++cas,ans);
    }
    return 0;
}













