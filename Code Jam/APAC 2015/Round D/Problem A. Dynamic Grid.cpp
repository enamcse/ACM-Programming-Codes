/**
* H:\Dropbox\Code\Code Jam\APAC 2015\Round D\Problem A. Dynamic Grid.cpp
* Created on: 2015-11-08-11.06.55, Sunday
* Verdict: Solved
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
#define fread freopen("A-large.in","r",stdin)
#define fwrite freopen("outputALarge.txt","w",stdout)
#define inf (1e18)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define pi 3.14159265358979323846264338327950288419716939937510
#define fr(i,a,b) for(i=a;i<=b;i++)
#define cspf printf("Case %d:", cas++);
#define csco cout<<"Case #"<<cas++<<":\n";
#define mod 1000000007
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

int rr[] = {0,0,1,-1};
int cc[] = {1,-1,0,0};

string s[105];
bool col[105][105];


int R,C;

void bfs(int x, int y)
{
    queue<int>q;
    q.push(x);
    q.push(y);
    int u, v;

    while(!q.empty())
    {
        x = q.front();
        q.pop();
        y = q.front();
        q.pop();
        if(col[x][y]) continue;
        col[x][y]=1;

        for (int i = 0; i<4; i++)
        {
            u = x + rr[i];
            v = y + cc[i];
            if(u<0||v<0||u>=R||v>=C||s[u][v]=='0'||col[u][v]==true) continue;
            q.push(u);
            q.push(v);
        }
    }
}


int calc()
{
    int ret = 0;
    clr(col,0);
    for (int i = 0; i<R; i++)
    {
        for (int j = 0; j<C; j++)
        {
            if(s[i][j]=='0'||col[i][j]) continue;
            bfs(i,j);
            ret++;
        }
    }
    return ret;
}

int main()
{
#ifdef ENAM
    	fread;
	fwrite;
#endif // ENAM
    int t, n, m, cas=1;
    int x, y, z;
    char ch;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    cin>>t;

    while(t--)
    {
        csco
        cin>>R>>C;

        for (int i = 0; i<R; i++)
        {
            cin>>s[i];
        }
        cin>>n;

        for (int i = 0; i<n; i++)
        {
            cin>>ch;
            if(ch=='M')
            {
                cin>>x>>y>>z;
                s[x][y] = z+'0';
            }
            else
            {
                cout<<calc()<<"\n";
            }
        }
    }


//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}