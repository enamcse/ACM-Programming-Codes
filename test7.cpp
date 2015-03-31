#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <map>
#include <list>
#include <set>
#include <string>
#include <stack>
#include <bitset>

#define sz 500005
#define pb(a) push_back(a)
#define pp pop_back
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e9)
#define PI acos(-1)
#define _ ios_base::sync_with_stdio(0);cin.tie();
#define clr(y,z) memset(y,z,sizeof(y))
#define ll long long
#define mp make_pair
#define pf prinf
#define sf scanf
#define all(v) v.begin(),v.end()
#define mod 1000000007
using namespace std;

ll bigmod(ll B, ll P, ll M){ll R = 1; while(P>0){if(P%2==1) {R=(R*B)%M;} P/=2;B=(B*B)%M;} return R;}

int rr[] = {0,0,1,-1};
int cc[] = {1,-1,0,0};
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


int main()
{
    _
    int n, m;

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


    return 0;
}

