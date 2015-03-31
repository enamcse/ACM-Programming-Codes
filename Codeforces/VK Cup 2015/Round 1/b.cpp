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
#define oo 1000000010
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

pair<int,int> dp[1010][1010];
int n;
pair<int,int> val[1010];

pair<int,int> rec(int pos,int mxh)
{
    if(pos==n) return mp(mxh,0);
    pair<int,int> &ret = dp[pos][mxh];
    if(ret.fs!=-1) return ret;
    ret=mp(oo,oo);
    pair<int,int> tmp=rec(pos+1,max(mxh,val[pos].fs));
    ret=mp(tmp.fs,tmp.sc+val[pos].sc*tmp.fs);
    tmp=rec(pos+1,max(mxh,val[pos].sc));
    if(ret.sc>tmp.sc+val[pos].fs*tmp.fs)
    {
        ret=mp(tmp.fs,tmp.sc+val[pos].fs*tmp.fs);
    }
    else if(ret.sc==tmp.sc+val[pos].fs*tmp.fs)
    {
        ret.fs=min(ret.fs,tmp.fs);
    }
    return ret;
}

map<pair<int,pair<int,int> > ,int > mpp;
int rec2(int pos,int w,int h)
{
    if(pos==n) return w*h;
    pair<int,pair<int,int> > tmp = mp(pos,mp(w,h));
    if(mpp.count(tmp)) return mpp[tmp];
    int ret = rec2(pos+1,w+val[pos].fs,max(h,val[pos].sc));
    ret = min(ret,rec2(pos+1,w+val[pos].sc,max(h,val[pos].fs)));
    mpp[tmp]=ret;
    return ret;
}

int main()
{
    #ifdef MAHDI
//    Read;
//    Write;
    #endif // MAHDI
    SF("%d",&n);
    for(int i=0;i<n;i++)
    {
        SF("%d %d",&val[i].fs,&val[i].sc);
    }
    sort(val,val+n);
    int ress=oo;
    for(int i=0;i<n;i++)
    {
        int h=val[i].sc,w=0;
        bool flag=true;
        for(int j=0;j<n;j++)
        {
            if(min(val[j].fs,val[j].sc)>h)
            {
                flag=false;
                break;
            }
            else
            {
                int mx=max(val[j].fs,val[j].sc);
                if(mx>h)
                {
                    w+=mx;
                }
                else
                {
                    int mn=min(val[j].fs,val[j].sc);
                    w+=mn;
                }
            }
        }
        if(flag)
        {
            ress=min(ress,w*h);
        }
        h=val[i].fs,w=0;
        flag=true;
        for(int j=0;j<n;j++)
        {
            if(min(val[j].fs,val[j].sc)>h)
            {
                flag=false;
                break;
            }
            else
            {
                int mx=max(val[j].fs,val[j].sc);
                if(mx>h)
                {
                    w+=mx;
                }
                else
                {
                    int mn=min(val[j].fs,val[j].sc);
                    w+=mn;
                }
            }
        }
        if(flag)
        {
            ress=min(ress,w*h);
        }
    }
    deb(ress);

    return 0;
}

/*
10
65 4
98 65
1 1
45 31
14 17
98 34
62 100
977 13
131 21
34 15

---> 254020

--->95485
*/












