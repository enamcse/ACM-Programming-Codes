/*
ID: manetsus
PROG: milk2
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
#define input_file "milk2.in"
#define output_file "milk2.out"
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

    int n,a,b,x=inf,y=0, p,q;
    int ans=0, ans2=0;

    scanf("%d", &n);

    for (int i = 0; i<n; i++)
    {
        scanf("%d %d", &a, &b);
        x = min(x,a);
        y = max(y,b);
        v.pb(make_pair(a,b));
    }

    sort(all(v));

    p = v[0].first;
    q = v[0].second;

    ans = q - p;

    for (int i = 0; i<n; i++)
    {
        if(v[i].first<=q)
        {
            q = max(v[i].second,q);
        }
        else
        {
            ans = max(ans,q-p);
            p = v[i].first;
            ans2 = max(ans2,p-q);
            q= v[i].second;
        }
    }

    printf("%d %d\n", ans, ans2);


    return 0;
}

