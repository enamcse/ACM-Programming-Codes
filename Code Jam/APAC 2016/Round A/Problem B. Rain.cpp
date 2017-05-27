/**
* E:\Dropbox\Code\Code Jam\APAC 2016\Round A\Problem B. Rain.cpp
* Created on: 2016-07-10-11.28.03, Sunday
* Verdict: Not Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define SZ(a) ((ll)a.size())
#define sz 200005
#define pb push_back
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
#define cntbit(mask) __builtin_popcount(mask)
#define unify(a) stable_sort(a.begin(),a.end());a.resize(distance(a.begin(),unique(all(a))));
#define fread freopen("B-large.in","r",stdin)
#define fwrite freopen("B-large-out.txt","w",stdout)
#define inf (1e5)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define pi 3.14159265358979323846264338327950288419716939937510
#define fr(i,a,b) for(i=a;i<=b;i++)
#define cspf printf("Case %d:", cas++);
#define csco cout<<"Case #"<<cas++<<": ";
#define mod 1000000007

#ifdef ENAM
#define deb(args...) {dbg,args; cerr<<endl;}
#else
#define deb(args...)
#endif

ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

int cc[] = {0,0,1,-1};
int rr[] = {1,-1,0,0};


using namespace std;

int grid[55][55], col[55][55],col2[55][55], cnt,n,m,cnt2;

void bfs(int xx, int yy)
{
    int x = xx;
    int y = yy;
//    col[x][y] = cnt;
    int up = inf,u,v;
    queue<int>q;
    q.push(x);
    q.push(y);
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        v = q.front();
        q.pop();
        if(col[u][v]==cnt) continue;
        col[u][v] = cnt;
        for(int i = 0; i<4; i++)
        {
            x = u+cc[i];
            y = v+rr[i];
            if(x<0||y<0||x>=n||y>=m) { up=0; continue;}
            if(grid[x][y]!=grid[u][v])up = min(up,grid[x][y]);
            if(grid[x][y]!=grid[u][v]||col[x][y]==cnt) continue;
            q.push(x);
            q.push(y);
        }
    }
//    cerr<<"xx = "<<xx<<" "<<"yy = "<<yy<<" up = "<<up<<endl;
    if(up<=grid[xx][yy]) return;
    cnt2++;
    q.push(xx);
    q.push(yy);
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        v = q.front();
        q.pop();
        if(col2[u][v]==cnt2) continue;
        col2[u][v] = cnt2;

        for(int i = 0; i<4; i++)
        {
            x = u+cc[i];
            y = v+rr[i];
            if(x<0||y<0||x>=n||y>=m) continue;
            if(grid[x][y]!=grid[u][v]||col2[x][y]==cnt2) continue;
            q.push(x);
            q.push(y);
        }
        grid[u][v] = up;
    }
}

int main()
{
#ifdef ENAM
      fread;
  fwrite;
#endif // ENAM
	_
	int cas = 1,t,x,y,z;
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    cin>>t;

    while(t--)
    {cin>>n>>m;
        y=0;
        x=0;
        clr(grid,0);
        for(int i = 0; i<n; i++)
            for(int j = 0; j<m; j++){
                cin>>grid[i][j];
                y+=grid[i][j];
                x=max(x,grid[i][j]);
            }
    for(int k = 1; k<=x; k++){
        cnt++;
        for(int i =0; i<n; i++)
            for(int j = 0; j<m; j++)
                if(k==grid[i][j] && col[i][j]!=cnt)bfs(i,j);

    }
        z=0;
        for(int i = 0; i<n; i++)
            for(int j = 0; j<m; j++){
                z+=grid[i][j];
            }
        csco
        cout<<(z-y)<<"\n";
//        cerr<<z << " >> "<< y<<endl;
    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
