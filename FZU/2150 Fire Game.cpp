//#include <bits/stdc++.h>
//#define _ ios_base::sync_with_stdio(0);cin.tie(0);
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
#include <list>
#include <set>
#include <string>
#include <stack>
#include <bitset>

#define sz 12
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e9)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1; while(ghat>0)  {if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;} return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const) { return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

int rr[] ={1,-1,0,0};
int cc[] ={0,0,1,-1};

char line[sz][sz];
int col[sz][sz];
int t, n, m, cas=1, mx, cnt;

vector<int>v;

int bfs(int a, int b, int c, int d)
{
    queue<int>q;
    q.push(a);
    q.push(b);
    col[a][b] = 0;
    col[c][d] = 0;
    int x,y, mx = 0, u, v, now = cnt;

    if(a==c&&b==d)
    {
        now--;
    }
    else
    {
        q.push(c);
        q.push(d);
        now-=2;
    }

    while(!q.empty())
    {
        x = q.front();
        q.pop();
        y = q.front();
        q.pop();

        for (int i = 0; i<4; i++)
        {
            u = x+rr[i];
            v = y+cc[i];
            if(u>=n||v>=m||u<0||v<0||col[u][v]!=-1||line[u][v]!='#') continue;
            col[u][v] = col[x][y] + 1;
            now--;
            mx = max(mx, col[u][v]);
            q.push(u);
            q.push(v);
        }
    }
//    cout<<cnt<<" > "<<now<<": "<<a<<" "<<b<<" "<<c<<" "<<d<<" = "<<mx<<endl;
    return now?1e9:mx;
}

int main()
{
    #ifdef ENAM
//    	fread;
//	fwrite;
    #endif // ENAM
    int div;
    scanf("%d", &t);

    while(t--)
    {
        mx = 1e9;
        clr(col,-1);
        cnt=div = 0;
        v.clear();
        scanf("%d %d", &n, &m);
        for (int i = 0; i<n; i++)
            scanf("%s", line[i]);

        for (int i = 0; i<n; i++)
            for (int j = 0; j<m; j++)
            {
                if(line[i][j]=='#')
                {
                    if(col[i][j]==-1&&div<3)bfs(i,j, i, j), div++;
                    cnt++;
                    v.pb(i);
                    v.pb(j);
                }
            }

        if(div<3)
        {
            int len = v.size();
            for (int i = 0; i<len; i+=2)
                for (int j = i; j<len; j+=2)
                        {
                            clr(col,-1);
                            mx=min(mx, bfs(v[i],v[i+1], v[j], v[j+1]));
                        }
            printf("Case %d: %d\n", cas++, mx);
        }
        else printf("Case %d: -1\n", cas++);


    }


    return 0;
}

/**
4
3 3
.#.
###
.#.
3 3
.#.
#.#
.#.
3 3
...
#.#
...
3 3
###
..#
#.#
*/
