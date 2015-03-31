/**
* H:\Dropbox\Code\A2O\Ladder\22. Contest Hall Preparation.cpp
* Created on: 2015-01-31-02.38.55, Saturday
* Verdict: Not Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 200005
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

int rr[] ={0,0,-1,-1,-1,1,1,1};
int cc[] ={-1,1,-1,0,1,-1,0,1};



int adj[101][101];

bool teams[101];

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1,u,v;
    _

    cin>>t;

    while(t--)
    {
        cin>>n>>m;
        clr(teams,0);
        for (int i = 0; i<n; i++)
            for (int j = 0; j<m; j++)
                cin>>adj[i][j];
        for (int i = 0; i<n; i++)
            for (int j = 0; j<m; j++)
                if(adj[i][j]!=-1&&!teams[ adj[i][j] ])
                for (int k = 0; k<8; k++)
                {
                    u = i+rr[k];
                    v = j+cc[k];
                    if(u<0||v<0||u>=n||v>=m) continue;
                    if(adj[u][v]==adj[i][j])
                    {
                        teams[ adj[u][v]] = 1;
                        break;
                    }
                }
                n=0;
            for (int i = 1; i<=100; i++)
                if(teams[i])n++;
            cout<<n<<"\n";
    }


   return 0;
}
