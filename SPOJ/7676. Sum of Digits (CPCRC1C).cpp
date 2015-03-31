//pair dp , digit dp

//#include <bits/stdc++.h>
//#define _ ios_base::sync_with_stdio(0);cin.tie(0);
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
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1; while(ghat>0)  {if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;} return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const) { return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;
int n;
char line[20];


pair<ll, ll>dp[12][2];  //fs = jog fol, sc = niche kototi sonkha banano somvob

pair<ll, ll> rec(int pos, bool max_flag)
{
    if(pos==n) return make_pair(0,1);
    pair<ll, ll> &ret = dp[pos][max_flag];
    if(ret.first !=-1) return ret;
    ret = make_pair(0,0);

    int cond = max_flag?line[pos]-'0':9;
    pair<ll, ll> temp;
    for (int i = 0; i<=cond; i++)
    {
        temp = rec(pos+1, max_flag && i==cond);
        ret.first +=( temp.first + temp.second * i);
        ret.second+=temp.second;
    }
    return ret;
}


int main()
{
    #ifdef ENAM
//    	fread;
//	fwrite;
    #endif // ENAM
    int a,b;
    pair<ll, ll> p, q;

    while(~scanf("%d %d", &a, &b))
    {
        if(a==-1&&b==-1) break;

        if(a>1)
        {
            a--;
            sprintf(line,"%d", a);
            n= strlen(line);
            clr(dp,-1);
            p = rec(0,1);
        }
        else p.first = 0;

        sprintf(line,"%d", b);
        n= strlen(line);
        clr(dp,-1);
        q = rec(0,1);

        printf("%lld\n", q.first - p.first);


    }

    return 0;
}
