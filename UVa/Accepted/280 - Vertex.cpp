/**
* H:\Dropbox\Code\UVa\280 - Vertex.cpp
* Created on: 2015-02-09-23.52.34, Monday
* Verdict: Solved
* Comment: This problem will give Runtime Error if dfs is used due to stack memory.
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

using namespace std;

bool col[102];
vector<int>v[102];
void bfs(int x)
{
    queue<int>q;

    q.push(x);

    while(!q.empty())
    {
        x = q.front();
        q.pop();
        int n = v[x].size();
        for (int i = 0; i<n; i++)
        {
            if(!col[ v[x][i] ])
            {
                col[ v[x][i] ] = true;
                q.push(v[x][i]);
            }
        }
    }
    return;
}

int main()
{
#ifdef ENAM
//    	fread;
    fwrite;
#endif // ENAM
    int t, n, m, cas=1,x,y;

    while(~scanf("%d", &n)&&n)
    {
//        cout<<"here"<<endl;
        for (int i = 1; i<=n; i++)
            v[i].clear();
        while(1)
        {
            scanf("%d", &x);
            if(!x) break;
            while(1)
            {
                scanf("%d", &y);
                if(!y) break;
                v[x].pb(y);
            }
        }
        scanf("%d", &y);
        for (int i = 0; i<y; i++)
        {
            clr(col,0);
            scanf("%d", &x);
            bfs(x);

            vector<int>ans;
            for (int i = 1; i<=n; i++)
                if(!col[i]) ans.pb(i);

            x = ans.size();
            printf("%d", x);
            for (int i = 0; i<x; i++)
                printf(" %d", ans[i]);
            puts("");
        }
    }


    return 0;
}
