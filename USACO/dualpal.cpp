/*
ID: manetsus
PROG: dualpal
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
#define input_file "dualpal.in"
#define output_file "dualpal.out"
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


int base,n;
string s;
map<int,char>digit;


string convert_to_base(int now)
{
    string ss="";

    int m;

    while(now)
    {
        m = now%base;
        ss+=digit[m];
        now/=base;
    }
    reverse(all(ss));

    return ss;
}


bool check_pal()
{
    int now = s.size(), len;
    len = now/2;
    for (int i = 0; i<len; i++)
        if(s[i]!=s[now-1-i]) return false;
    return true;
}


int main()
{
    #if !defined ENAM
        fread;
    fwrite;
    #endif // ENAM
//    ofstream fout (input_file);
//    ifstream fin (output_file);

    for (int i = 0; i<10; i++)
        digit[i]='0'+i;

    int lim, st,cnt, it=0;

    scanf("%d %d", &lim, &st);

    for (int i = st+1; it<lim; i++)
    {
        cnt=0;
        for (int j = 2; j<=10; j++)
        {
            base = j;
            s=convert_to_base(i);
            if(check_pal()) cnt++;
        }

        if(cnt>=2)
        {
            printf("%d\n", i);
            it++;
        }

    }


    return 0;
}

