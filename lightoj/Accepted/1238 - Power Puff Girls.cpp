#include <stdio.h>
#include <string.h>
#include <queue>
#include <map>

#define sz 31

#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e9)

using namespace std;

int cc[] = {0,0,1,-1};
int rr[] = {1,-1,0,0};

int col[sz][sz], cnt, mx;

int n, m;
map<char, int>mp;

char line[sz][sz];

int bfs(int u, int v)
{
    cnt++;
    col[u][v] = cnt;
    queue<pair< pair <int, int> , int> >q;
    pair< pair<int, int> , int>now;
    q.push(make_pair(make_pair(u,v), 0));
    while(!q.empty())
    {

        now = q.front();

        for (int i = 0; i<4; i++)
        {
            u = now.first.first+rr[i];
            v = now.first.second+cc[i];
            if(col[u][v]==cnt) continue;
            if(line[u][v]=='m'||line[u][v]=='#') continue;
            if(line[u][v]=='h') return now.second+1;
            col[u][v] = cnt;
            q.push(make_pair(make_pair(u,v), now.second+1 ));
        }
        q.pop();
    }
    return inf;
}

int main()
{
#ifdef ENAM
    fread;
    fwrite;
#endif // ENAM
    int t, cas=1;
    int mark[3][2];
    mp['a'] = 1;
    mp['b'] = 3;
    mp['c'] = 5;
    mp['h'] = 4;
    mp['m'] = 16;
    mp['.'] = 32;
    mp['#'] = 8;

    scanf("%d", &t);
    while(t--)
    {
        mx = 0;
        scanf("%d %d", &n, &m);
        for (int i = 0; i<n; i++)
            scanf("%s", line[i]);

        for (int i = 0; i<n; i++)
            for (int j = 0; j<m; j++)
                if(mp[ line[i][j] ]&1)
                {
                    mark[ (mp[ line[i][j] ]>>1)  ][0] = i;
                    mark[ (mp[ line[i][j] ]>>1)  ][1] = j;
                }

        for (int i = 0; i<3; i++)
            mx = max(mx, bfs(mark[i][0], mark[i][1]));
        printf("Case %d: %d\n", cas++, mx);
    }
    return 0;
}

/*
2
6 8
########
#...c..#
#......#
#.a.h.b#
#......#
########
5 9
#########
#mmm...c#
#ma.h####
#m....b.#
#########
*/
