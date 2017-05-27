/**
* H:\Dropbox\Code\UVa\10000 - Longest Paths.cpp
* Created on: 2015-09-19-14.32.30, Saturday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define SZ(a) ((int)a.size())
#define sz 105
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
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

vector<int>adj[sz];

pair<int,int> dp[sz];

inline void write_int(int x)
{
#ifdef USE_SIGN
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
#endif

    char buf[10], *p = buf;
    do
    {
        *p++ = '0' + x % 10;
        x /= 10;
    }
    while (x);
    do
    {
        putchar(*--p);
    }
    while (p > buf);
}

inline int read_int()
{
    char c;

    while (c = getchar(), c <= ' ')
    if(c==EOF) return 0;
#ifdef USE_SIGN
    bool sign = c == '-';
    if (sign)
    {
        c = getchar();
    }
#endif

    int res = c - '0';
    while (c = getchar(), c >= '0' && c <= '9')
    {
        res = res * 10 + (c - '0');
    }
    // One character is gobbled here

#ifdef USE_SIGN
    return sign ? -res : res;
#else
    return res;
#endif
}

pair<int,int> rec(int x)
{
    pair<int,int> &ret = dp[x];

    if(~ret.first) return ret;

    pair<int,int> temp;
    ret = {0,x};
    for (int i = 0; i<adj[x].size(); i++)
    {
        temp = rec(adj[x][i]);
        temp.first++;
        if(temp.first>ret.first ||(temp.first==ret.first && temp.second<ret.second)) ret = temp;
    }
    return ret;
}

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int st, n, m, cas=1,x,y;

//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    while(n = read_int())
    {
        assert(n<=100);

        st = read_int();
        x = read_int();
        y = read_int();

        clr(dp,-1);
        while(x||y)
        {
            adj[x].pb(y);
            x = read_int();
            y = read_int();
        }

        pair<int,int>res = rec(st);
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",cas++,st,res.first,res.second);

        for (int i = 0; i<=n; i++) adj[i].clear();
    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
