#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <string>
#include <string.h>

using namespace std;

#define clr(y,z) memset(y,z, sizeof(y))
#define cntbit(mask) _builtin_popcount(mask)
#define fs first
#define sc second
#define pb push_back
#define pp pop_back
#define chg(a, b) a^=b^=a^=b
#define sz 100005
#define inf (1e9)

int rr[] = {0,0,1,-1};
int cc[] = {1,-1,0,0};

char line[200][200];
bool flag[200][200];
int t, n, m, ans;

int li, lj;

int dfs(int i, int j, int cnt)
{
    if(flag[i][j]||line[i][j]=='.') return cnt;
    int mx = cnt, u, v;
    flag[i][j] = true;
    for (int k = 0; k<4; k++)
    {
        u = i+cc[k];
        v = j+rr[k];
        if(u<0||v<0||u>=n||v>=m ||flag[u][v]||line[u][v]=='.') continue;
//        flag[u][v] = true;
        int now = dfs(u,v,cnt+1);
        if(now>mx)
        {
            mx = now;
            li = u, lj = v;
        }

    }

    return mx;
}

void check()
{
    for (int i = 0; i<n; i++)
        {
            for (int j = 0; j<m; j++)
            {
                cout<<flag[i][j]<<" ";
            }
            cout<<endl;
        }
        return;
}

int main()
{
    #ifdef ENAM
//        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif



    scanf("%d", &t);
    int div, mx;
    for (int cas = 1; cas<=t; cas++)
    {
        div = 0;
        mx = 0;
        clr(flag,false);
        scanf("%d %d", &n, &m);
        for (int i = 0;i<n; i++)
        	scanf("%s", line[i]);

        for (int i = 0; i<n; i++)
        {
            for (int j = 0; j<m; j++)
            {
                if(flag[i][j] == false && line[i][j]=='#')
                {

                    mx = max(mx,dfs(i,j,0));
//                    cout<<"@"<<i<<" "<<j<<" "<<mx<<endl;
//                    check();
                    div++;
                }
            }
        }

        mx=mx/2;
//        cout<<div<<":"<<mx<<endl;
        if(div==1)
        {

        }
        if(div>=3) printf("Case %d: -1\n", cas);
        else printf("Case %d: %d\n", cas, mx);
    }



    return 0;
}
