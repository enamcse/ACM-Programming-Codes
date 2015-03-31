//Verdict: NOT SOLVED
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

string name[sz][2], now;
int ordr[sz],n,m;

int main()
{
    #ifdef ENAM
//        fread;
//    fwrite;
    #endif // ENAM
    char line[100], line1[100];
    scanf("%d", &n);
    now = "";
    for (int i = 1; i<=n; i++)
    {
        scanf("%s %s", line, line1);
        name[i][0] = line;
        name[i][1] = line1;
    }

    for (int i = 0; i<n; i++)
        scanf("%d", &ordr[i]);

    for (; m<n; m++)
    {
        if(name[ ordr[m] ][0] > now && name[ ordr[m] ][1] > now)
        {
            if(name[ ordr[m] ][0] < name[ ordr[m] ][1]) now = name[ ordr[m] ][0];
            else now = name[ ordr[m] ][1];
        }
        else if(name[ ordr[m] ][0] > now)now = name[ ordr[m] ][0];
        else if(name[ ordr[m] ][1] > now)now = name[ ordr[m] ][1];
        else break;
    }

    if(m==n) puts("YES");
    else puts("NO");


    return 0;
}
