/**
* H:\Dropbox\Code\UVa\10042 - Smith Numbers.cpp
* Created on: 2015-09-19-16.54.47, Saturday
* Verdict: Solved
* Author: Enamul Hassan
* Comment: This is naive solution, should not pass in the actual case.
**/

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
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

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

bool isprime(int x)
{
    if(x==2) return 1;
    if(x<2||x%2==0) return 0;
    for (int i = 3; i<=sqrt(x); i++)
        if(x%i==0) return 0;
    return 1;
}

int getsum(int x)
{
    int ret=0;
    while(x)
    {
        ret+=x%10;
        x/=10;
    }
    return ret;
}

int getit(int x)
{
    for (int i = x+1; ; i++)
    {
        if(isprime(i))continue;
        int now = i, sum=0;
        for (int j = 2; j<=sqrt(now); j++)
        {
            while(now%j==0)
            {
                sum+=getsum(j);
                now/=j;
            }
        }
        if(now!=1) sum+=getsum(now);
        if(getsum(i)==sum) return i;
    }
}

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1;
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    t = read_int();

    while(t--)
    {
        n = read_int();

        write_int(getit(n));
        putchar('\n');
    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
