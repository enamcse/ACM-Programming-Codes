/*
ID: manetsus
PROG: milk
LANG: C++
*/
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
#define sz 100
#define input_file "milk.in"
#define output_file "milk.out"
#define pb(a) push_back(a)
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
#define fread freopen(input_file,"r",stdin)
#define fwrite freopen(output_file,"w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define chng(a,b) a^=b^=a^=b;
#define PI acos(-1)
#define mod 1000000007
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1; while(ghat>0)  {if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;} return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const) { return bigmod(bivajok,vag_const-2, vag_const);}
using namespace std;

vector< pair<int,int> >v;

int main()
{
    #if !defined ENAM
        fread;
    fwrite;
    #endif // ENAM
//    ofstream fout (input_file);
//    ifstream fin (output_file);

    int n, m, a, b;
    ll cost=0LL;
    scanf("%d %d", &n, &m);

    for (int i = 0; i<m; i++)
    {
        scanf("%d %d", &a, &b);
        v.pb(make_pair(a,b));
    }

    sort(all(v));

    for (int i = 0; i<m&&n; i++)
    {
        if(n>=v[i].second)
        {
            cost+=(v[i].first*(ll)v[i].second);
            n-=v[i].second;
        }
        else
        {
            cost+=(v[i].first*(ll)n);
            n=0;
        }
    }


    printf("%lld\n", cost);


    return 0;
}

