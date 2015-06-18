/**
* H:\Dropbox\Code\Codeforces\516B.cpp
* Created on: 2015-02-17-23.26.23, Tuesday
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

int rr[] ={0,0,1,-1};
int cc[] ={1,-1,0,0};


string s[2005];
int degree[2005][2005];
bool col[2005][2005];

bool bfs(int n, int m)
{
    queue< int >q;

    for (int i = 0; i<n; i++)
        for (int j = 0; j<m; j++)
            if(!col[i][j]&&degree[i][j]==1)
            {
                q.push(i);
                q.push(j);
            }
    while(!q.empty())
    {
        int i = q.front();
        q.pop();
        int j = q.front();
        q.pop();
        if(col[i][j]) continue;
        col[i][j] =  true;
        int ans=-1;

        for (int xx = 0; xx<4; xx++)
            {
                int u = i+rr[xx];
                int v = j+cc[xx];
                if(u<0||v<0||u>=n||v>=m||col[u][v]) continue;
                if(ans==-1) ans=xx;
                else return false;
            }
        if(ans==-1) return false;

        switch (ans)
        {
        case 0:
            s[i][j]='<';
            s[i+ rr[ans] ][ j +cc[ans] ]='>';
            break;
        case 1:
            s[i][j]='>';
            s[i+ rr[ans] ][ j +cc[ans] ]='<';
            break;
        case 2:
            s[i][j]='^';
            s[i+ rr[ans] ][ j +cc[ans] ]='v';
            break;
        case 3:
            s[i][j]='v';
            s[i+ rr[ans] ][ j +cc[ans] ]='^';
            break;
        }
        i+=rr[ans];
        j+=cc[ans];
        col[i][j] = true;

        for (int xx = 0; xx<4; xx++)
            {
                int u = i+rr[xx];
                int v = j+cc[xx];
                if(u<0||v<0||u>=n||v>=m||col[u][v]) continue;
                if(--degree[u][v]==1)
                {
                    q.push(u);
                    q.push(v);
                }
            }
    }

    for (int i = 0; i<n; i++)
        for (int j = 0; j<m; j++)
            if(s[i][j]=='.') return false;
    return true;
}


int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1,p,q, tot=0;
    _
	cin>>n>>m;
	for (int i = 0; i<n; i++)
    {
        cin>>s[i];
        for (int j = 0; j<m; j++)
            if(s[i][j] == '*') col[i][j]++;
    }
    for (int i = 0; i<n; i++)
        for (int j = 0; j<m; j++)
            if(s[i][j]=='.')
            for (int xx = 0; xx<4; xx++)
            {
                int u = i+rr[xx];
                int v = j+cc[xx];
                if(u<0||v<0||u>=n||v>=m||s[u][v]=='*') continue;
                degree[u][v]++;
            }

    if(bfs(n,m))
        for (int i = 0; i<n; i++)
            cout<<s[i]<<endl;
    else cout<<"Not unique";


   return 0;
}
