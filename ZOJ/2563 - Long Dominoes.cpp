/* 
* @Author: Enamul Hassan
* @Date:   2015-03-23 02:39:18
* @Last Modified by:   Enamul
* @Last Modified time: 2015-03-23 02:40:13
* @Verdict: Solved
* @File Path: H:\Dropbox\Code\ZOJ\2563 - Long Dominoes.cpp
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 200005
#define pb(a) push_back(a)
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
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}
using namespace std;

int h, low;
map< pair<int, pair<int,int> >,ll >dp;
//map< pair<int, pair<int,int> >,ll >dp2;
//ll dp[40][(1<<9)][(1<<9)];
//ll dp2[40][(1<<9)][(1<<9)];
ll rec(int pos, int mask, int mask2);

ll gen(int pos, int mask, int mask2, int mask3)
{
    if(mask == (1<<low)-1) return rec(pos+1,mask2,mask3);
//    if(dp2.count( make_pair(pos, make_pair(mask,mask2) ) )) return dp2[ make_pair(pos, make_pair(mask,mask2) ) ];
//    dp2[ make_pair(pos, make_pair(mask,mask2) ) ] = 0;

//    ll &ret = dp2[pos][mask][mask2];
//    if(ret!=-1) return ret;
    ll ret = 0;
    int i;
    for(i = 0;i<low;i++)
    {
        if(!((1<<i)&mask))
        {
            if(i+2<low)
            {
                if(!((1<<(i+1))&mask)  && !((1<<(i+2))&mask)) ret+=gen(pos,mask|(1<<i)|(1<<(i+1))|(1<<(i+2)), mask2,mask3);
            }
            if(pos+2<h)
            {
                if(!((1<<i)&mask2)  && !((1<<i)&mask3)) ret+=gen(pos,mask|(1<<i), mask2|(1<<i),mask3|(1<<i));
            }
            break;
        }
    }
    if(i==low) ret=rec(pos+1,mask2, mask3);
    return ret;
}

void print(int m)
{
    cout<<":";
    while(m)
    {
        cout<<m%2;
        m/=2;
    }
    cout<<" ";
}

ll rec(int pos, int mask, int mask2)
{
//    cout<<pos;
//    print(mask);
//    print(mask2);
//    cout<<endl;
    if(pos==h)
    {
        if(!mask && !mask2)
            return 1;
        return 0;
    }
    if(dp.count( make_pair(pos, make_pair(mask,mask2) ) )) return dp[ make_pair(pos, make_pair(mask,mask2) ) ];
    dp[ make_pair(pos, make_pair(mask,mask2) ) ]=gen(pos,mask,mask2,0);
    return dp[ make_pair(pos, make_pair(mask,mask2) ) ];
}

int main(){
	#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int  n, m;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();


	while(cin>>n>>m&&(m|n))
    {
        if(n>m) swap(n,m);
        low = min(m,n);
        h = max(m,n);
//        clr(dp,-1);
        dp.clear();
//        dp2.clear();
//        clr(dp2,-1);
        cout<<rec(0,0,0)<<"\n";

    }


//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}












