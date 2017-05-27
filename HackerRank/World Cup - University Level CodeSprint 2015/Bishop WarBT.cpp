/**
* H:\Dropbox\Code\HackerRank\World Cup - University Level CodeSprint 2015\Bishop War.cpp
* Created on: 2015-09-11-23.02.17, Friday
* Verdict: Not Solved
* Author: Enamul Hassan
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

int n, m;

void print(int pos, vector<string> &grid)
{
    cerr<<"-------------------:"<<n<<"\n";

    for (int i = 0; i<grid.size(); i++)
        cerr<<grid[i]<<"\n";

}

int rec(int pos, vector<string> &grid)
{
    if(pos==n) return 1;

//    print(pos,grid);

    int ret=0,x,y;

    for(int i = 0; i<m; i++)
    {
        vector<int>v;
        if(grid[pos][i]=='.')
        {
            grid[pos][i]='B';
            for(x=pos-1,y=i-1;x>=0&&y>=0&&grid[x][y]!='*'; x--,y--)
            {
                v.pb(x);
                v.pb(y);
                v.pb(grid[x][y]);
                grid[x][y] ='H';
            }
            for(x=pos-1,y=i+1;x>=0&&y<m&&grid[x][y]!='*'; x--,y++)
            {
                v.pb(x);
                v.pb(y);
                v.pb(grid[x][y]);
                grid[x][y] ='H';
            }
            for(x=pos+1,y=i+1;x<n&&y<m&&grid[x][y]!='*'; x++,y++)
            {
                v.pb(x);
                v.pb(y);
                v.pb(grid[x][y]);
                grid[x][y] ='H';
            }
            for(x=pos+1,y=i-1;x<n&&y>=0&&grid[x][y]!='*'; x++,y--)
            {
                v.pb(x);
                v.pb(y);
                v.pb(grid[x][y]);
                grid[x][y] ='H';
            }

            ret+=rec(pos+1,grid);
            grid[pos][i]='.';

            for(int j = 0;j<v.size();j+=3)
            {
                grid[v[j]][ v[j+1] ] =v[j+2];
            }
        }


    }


    return ret;
}

int main()
{
#ifdef ENAM
    	fread;
//	fwrite;
#endif // ENAM
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    vector<string>s;
    string now;
    cin>>n>>m;

    for(int i = 0;i<n;i++)
    {
        cin>>now;
        s.pb(now);
    }

    cout<<rec(0,s);

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
