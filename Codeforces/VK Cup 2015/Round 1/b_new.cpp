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
#define w first
#define h second
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

int n;

pair<int,int> val[1010];

int go(int totW,bool flag)
{
    int res=oo;
    for(int i=0;i<n;i++)
    {
        int mxH = flag?val[i].w:val[i].h;///no flip and check + flip and check.
        int lieneed=flag;
        int totdiff=0;
        int addiW=flag?val[i].w-val[i].h:0;///if no flip the diff=0 otherwise flip cost.
        vector<int> diffs;
        for(int j=0;j<n;j++)
        {
            if(j==i) continue;
            if(val[j].h>mxH)
            {
                if(val[j].w>mxH) goto skip;///can't flip here
                else
                {
                    lieneed++;
                    addiW+=val[j].w-val[j].h;///flip must otherwise val[j].h will become mxH
                }
            }
            else if(val[j].w<=mxH)///for extra flip if needed
            {
                if(val[j].w>val[j].h)///only when we can reduce overall width because height is fixed
                {
                    diffs.psb(val[j].w-val[j].h);
                }
            }
        }
        if(lieneed>n/2) goto skip;
        else
        {
            totdiff = addiW;
            sort(all(diffs),greater<int>());///want to reduce as maximum as possible
            diffs.resize(min(SZ(diffs),n/2-lieneed));
            for(int i: diffs) totdiff+=i;
            int curW = totW-totdiff;
            res=min(res,curW*mxH);
        }

        skip: continue;
    }
    return res;
}

int main()
{
    #ifdef MAHDI
//    Read;
//    Write;
    #endif // MAHDI
    SF("%d",&n);
    int totW=0;
    for(int i=0;i<n;i++)
    {
        SF("%d %d",&val[i].w,&val[i].h);
        totW+=val[i].w;
    }
    int res=go(totW,false);
    res=min(res,go(totW,true));

    deb(res);
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

95485
*/













