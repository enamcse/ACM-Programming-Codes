/**
* H:\Dropbox\Code\UVa\260 - Il Gioco dell'X.cpp
* Created on: 2015-02-09-23.24.22, Monday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 205
#define pb(a) push_back(a)
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e18)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define pi 3.14159265358979323846264338327950288419716939937510
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

char grid[sz][sz];
int n;
bool col[sz][sz];

bool dfs(int x, int y)
{
    col[x][y] = true;
    if(x==n-1) return true;
    bool ret = false;
    if(x-1>=0&&y-1>=0&&grid[x-1][y-1]=='b'&&!col[x-1][y-1]) ret|=dfs(x-1,y-1);
    if(x-1>=0&&grid[x-1][y]=='b'&&!col[x-1][y]) ret|=dfs(x-1,y);
    if(y-1>=0&&grid[x][y-1]=='b'&&!col[x][y-1]) ret|=dfs(x,y-1);
    if(y+1<n&&grid[x][y+1]=='b'&&!col[x][y+1]) ret|=dfs(x,y+1);
    if(x+1<n&&grid[x+1][y]=='b'&&!col[x+1][y]) ret|=dfs(x+1,y);
    if(x+1<n&&y+1<n&&grid[x+1][y+1]=='b'&&!col[x+1][y+1]) ret|=dfs(x+1,y+1);
    return ret;
}

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, m, cas=1;
    _
    bool flag;
    while(cin>>n&&n)
    {
        flag = false;
        clr(col,false);
        for (int i = 0; i<n; i++)
            cin>>grid[i];
        for (int i = 0; i<n; i++)
        {
            if(grid[0][i]=='b'&&!col[0][i]&&dfs(0,i))
            {
                flag = true;
                break;
            }
        }
        cout<<cas++<<" ";
        if(flag) cout<<"B\n";
        else cout<<"W\n";
    }


   return 0;
}
