/**
* H:\Dropbox\Code\HackerRank\#HackerRankWorldCup\Sum Nim.cpp
* Created on: 2015-09-19-23.37.39, Saturday
* Verdict: Solved
* Author: Enamul Hassan & Rumman Mahmud
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define SZ(a) ((int)a.size())
#define sz 50
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

int arr[sz],n;

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

map<pair<int, int>, ll>mpp;

ll rec(int pos, int xors)
{
    if(pos==n+1) return xors==0;
    if(mpp.count({pos,xors})) return mpp[ {pos,xors} ];
    ll & ret = mpp[ {pos,xors} ];
    ret = 0;
    for (int i = pos; i<=n; i++)
    {
        ret+=rec(i+1,xors^(arr[i]-arr[pos-1]));
    }
    return ret;
}


int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    n = read_int();

    for (int i = 1; i<=n; i++)
    {
        arr[i] = read_int();
        arr[i]+=arr[i-1];
    }

    printf("%lld",rec(1,0));

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
