//Verdict: SOLVED
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

#define sz 100005
#define pb(a) push_back(a)
#define pp pop_back()
#define all(a) a.begin(),a.end()
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
#define sc1(n) scanf("%d", &(n))
#define scc1(n) scanf("%c", &(n))
#define scs1(n) scanf("%s", (n))
#define sc2(a,b) scanf("%d %d", &(a), &(b))
#define scc2(a,b) scanf("%c %c", &(a), &(b))
#define sc3(a,b,c) scanf("%d %d %d", &(a), &(b), &(c))
#define scc3(a,b,c) scanf("%c %c %c", &(a), &(b), &(c))
#define pf1(n) printf("%d", (n))
#define pf2(a,b) printf("%d %d", (a), (b))
#define pf3(a,b,c) printf("%d %d %d", (a), (b), (c))
#define pfc1(n) printf("%c", (n))
#define pfs1(n) printf("%s", (n))

using namespace std;

int arr[sz],n;

ll dp[sz];

ll rec(int pos)
{
    if(pos>=sz) return 0;

    ll &ret = dp[pos];
    if(ret!=-1) return ret;
    ret = 0;
    bool flag = false;
    for (int i = pos+2; i<sz; i++)
    {
        if(arr[i])
        {
            ret=max(ret,rec(i));
            if(flag) break;
            else flag = true;
        }
    }
    ret+=arr[pos]*(ll)pos;
    return ret;
}


int main()
{
#ifdef ENAM
//        fread;
//    fwrite;
#endif // ENAM
    int t, m, cas=1;
    clr(dp,-1);
    sc1(n);

    for (int i = 0; i<n; i++)
    {
        sc1(m);
        arr[m]++;
    }

    for (int i = 0; i<sz; i++)
    {
        if(arr[i])
        {
            printf("%lld\n", arr[i+1]?max(rec(i),rec(i+1)): rec(i));
            break;
        }
    }

    return 0;
}

