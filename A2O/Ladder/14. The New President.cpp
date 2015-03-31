/**
* H:\Dropbox\Code\A2O\Ladder\14. The New President.cpp
* http://a2oj.com/p.jsp?ID=14
* Created on: 2015-01-31-02.52.55, Saturday
* Verdict: Not Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 200005
#define pb(a) push_back(a)
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
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

int adj[101][101];

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1;
    _

    cin>>t;

    while(t--)
    {
        cin>>m>>n;
        for (int i = 0; i<n; i++)
            for (int j = 0; j<m; j++)
                cin>>adj[i][j];
        vector< pair<int,int> >v(m);
        for (int i = 1; i<=m; i++)
            v[i-1] = {0,i};
        for (int i = 0; i<n; i++)
            v[ adj[i][0]-1 ].first ++;
        sort(allr(v));
        if(v[0].first>n/2)
        {
            cout<<v[0].second<<" 1\n";
            continue;
        }
        int a,b,x,y;
        a=0,b=0;
        x=v[0].second;
        y=v[1].second;
        for (int i = 0; i<n; i++)
            for (int j = 0; j<m; j++)
                if(adj[i][j]==x||adj[i][j]==y)
                {
                    if(adj[i][j]==x) a++;
                    else b++;
                    break;
                }
        if(a>b) cout<<x<<" 2\n";
        else cout<<y<<" 2\n";
    }

   return 0;
}
