/*
ID: manetsus
PROG: beads
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
#define input_file "beads.in"
#define output_file "beads.out"
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

char line[1000];

map<int,char>mm;

//int dp[350][350][350][2][3];
int n;

int rec(int pos, int s, int e, int col, int dir, bool t)
{
    if(s==e) return 1;
    pos=(pos+n)%n;
    if(dir==1 && pos==e) if(t)return 0;
    else t = true;
    if(dir==2 && pos==s) return 0;



    int ret;// = dp[pos][s][e][col][dir];
//    if(ret!=-1) return ret;
    ret= (line[pos]=='w' || line[pos]==mm[col]);
//    cout<<"@-------: "<<pos<<" " <<ret<<endl;
    if(!dir)
    {

        ret+=max(rec(pos-1,s,e,col,1,t),rec(pos-1,s,e,!col,1,t));
        if(line[pos]=='w' || line[pos]==mm[col])ret+=rec(pos+1,s,e,col,2,t);
    }
    if(dir==1 && (line[pos]=='w' || line[pos]==mm[col]))ret+=rec(pos-1,s,e,col,1,t);
    if(dir==2 && (line[pos]=='w' || line[pos]==mm[col]))ret+=rec(pos+1,s,e,col,2,t);

//    cout<<"@: "<<pos<<" " <<ret<<endl;
    return ret;
}


int main()
{
    #if !defined ENAM
        fread;
    fwrite;
    #endif // ENAM
//    ofstream fout (input_file);
//    ifstream fin (output_file);
    int mx=0;

    mm[0] = 'b';
    mm[1] = 'r';

    scanf("%d %s", &n, line);

//    clr(dp,-1);

    for (int i = 0; i<n; i++)
    {
        mx=max(mx,rec(i,i,(i+n-1)%n, 0,0,0));
//        cout<<i<<" --  "<<(i+n-1)%n<<" --> "<<mx<<endl;
        mx=max(mx,rec(i,i,(i+n-1)%n, 1,0,0));
//        cout<<i<<" --> "<<mx<<endl;
    }

    printf("%d\n", min(n,mx));


    return 0;
}
