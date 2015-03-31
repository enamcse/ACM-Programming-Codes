#include <bits/stdc++.h>
    #define _ ios_base::sync_with_stdio(0);cin.tie(0);

    #define sz 1010
    #define pb(a) push_back(a)
    #define pp pop_back()
    #define ll long long
    #define fread freopen("input.txt","r",stdin)
    #define fwrite freopen("output.txt","w",stdout)
    #define inf (1<<30-1)
    #define clr(abc,z) memset(abc,z,sizeof(abc))
    #define PI acos(-1)
    using namespace std;

    vector <vector<int> >adj;
    vector <int> lived;
    int visited[sz],n;

    void bfs(int k)
    {
        queue<int>q;
        q.push(k);
        int x, len;
        bool col[sz];
        clr(col,false);
        col[k] = true;
        while(!q.empty())
        {
            x = q.front();
            q.pop();
            len = adj[x].size();
            visited[x]++;
            for (int i = 0; i<len; i++)
            {
                if(col[adj[x][i]]==true) continue;
                q.push(adj[x][i]);
                col[adj[x][i]]=true;
            }
        }

        return;
    }

    int main()
    {
        _
        vector<int>v;
        int t, k , m, cnt,cas=1, x, y;
        scanf("%d", &t);
        while(t--)
        {
            cnt = 0;
            clr(visited,0);
            adj.clear();
            lived.clear();
            scanf("%d %d %d", &k, &n, &m);
            while(k--)
            {
                scanf("%d", &x);
                lived.pb(x-1);
            }
            x = n;
            while(x--) adj.pb(v);
            while(m--)
            {
                scanf("%d %d", &x, &y);
                adj[x-1].pb(y-1);
            }
            k = lived.size();
            for (int i = 0; i<k; i++)
                bfs(lived[i]);
            for (int i = 0; i<n; i++)
                if(visited[i]>=k) cnt++;
            printf("Case %d: %d\n",cas++,cnt);
        }
        return 0;
    }
