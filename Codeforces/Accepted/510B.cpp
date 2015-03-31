/**
* H:\Dropbox\Code\Codeforces\510B.cpp
* Created on: 2015-02-02-22.29.46, Monday
* Verdict: Solved
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

int rr[] = {0,-1,0,1};
int cc[] = {-1,0,1,0};

char line[100][100];
int col[100][100],n,m;

bool bfs(int x, int y)
{
//    cout<<x<<" "<<y<<"LLLLLLLLLLL"<<endl;
    queue< pair<int,int> >q;
    queue<int>dir;
    q.push(make_pair(x,y));
    dir.push(4);
    col[x][y]++;
    while(!q.empty())
    {

        pair<int,int>p = q.front();
        int d = dir.front();
        q.pop();dir.pop();
//        cout<<p.first<<" "<<p.second<<"  j"<<endl;
        for (int i = 0; i<4; i++)
        {
            if(i==d) continue;
            int u = p.first+rr[i];
            int v = p.second+cc[i];
//            cout<<u<<" "<<v<<" hh"<<endl;
            if(u<0||v<0||u>=n||v>=m||line[p.first][p.second]!=line[u][v]) continue;
            {
//                cout<<u<<" "<<v<<" hhh"<<col[u][v]<<endl;
                if(col[u][v]++>=1) return true;
                if(i==0) dir.push(2);
                else if(i==1) dir.push(3);
                else if(i==2) dir.push(0);
                else if(i==3) dir.push(1);
                q.push(make_pair(u,v));
            }
        }
    }
    return false;
}


int main()
{
#ifdef ENAM
//      fread;
//  fwrite;
#endif // ENAM
    _
    bool flag = false;
    cin>>n>>m;

    for (int i = 0; i<n; i++)
        cin>>line[i];

    for (int i = 0; i<n&&!flag; i++)
        for (int j = 0; j<m&&!flag; j++)
        {
            if(!col[i][j])flag|=bfs(i,j);
        }

    if(flag) cout<<"Yes";
    else cout<<"No";


   return 0;
}
