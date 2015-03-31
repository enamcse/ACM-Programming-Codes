/**
* H:\Dropbox\Code\DevSkill\Dev Skill Coding Contest - 1\C.cpp
* Created on: 2015-02-15-21.35.06, Sunday
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
#define fread freopen("InputFileC.txt","r",stdin)
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

char line[100];

int rr[] = {0,0,-1,1};
int cc[] = {-1,1,0,0};

int n, m;

string s[100];
bool col[100][100];

bool bfs()
{
    int x, y, dx, dy;
    clr(col,false);
    for (int i = 0; i<n; i++)
        for (int j = 0; j<m; j++)
            if(s[i][j] == 'P') x = i, y = j;
            else if(s[i][j] == 'G') dx = i, dy = j;
    queue<int>q;
    q.push(x);
    q.push(y);
    col[x][y] = true;
    int u, v, p1, p2;
    while(!q.empty())
    {
        p1 = q.front();
        q.pop();
        p2 = q.front();
        q.pop();

        for (int i = 0; i<4; i++)
        {
            u = p1+rr[i];
            v = p2+cc[i];
            if(u<0||v<0||u>=n||v>=m||col[u][v]) continue;
            if(s[u][v]=='G') return true;
            if(s[u][v]!='.') continue;
            col[u][v] = true;
            q.push(u);
            q.push(v);
        }
    }
    return false;
}

int main()
{
#ifdef ENAM
    	fread;
	fwrite;
#endif // ENAM
    int t, cas=1;

    while(gets(line))
    {
        n=0;
        m = strlen(line);

        while(gets(line))
        {
            if(line[0]=='-') break;
            s[n++] = line;
        }
        cout<<(bfs()?"Possible":"Impossible")<<endl;
    }



   return 0;
}
