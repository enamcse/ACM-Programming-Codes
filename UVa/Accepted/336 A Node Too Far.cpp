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
#include<set>
#define sz 100
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
using namespace std;

map <int, vector <int> > a;
map <int,bool> col;
map<int,int>level;
set <int> l;

int lim;

void bfs(int x)
{
    queue<int>p,q;
    p.push(x);
    level[x] = 0;
    col[x] = true;
    int szz, lev=1;
    do
    {
        szz = p.size();
        for (int i = 0; i<szz; i++, p.pop())
            q.push(p.front());
        while(!q.empty())
        {
            x = q.front();
            szz =a[x].size();
            for (int i = 0; i<szz; i++)
            {
                int g = a[x][i];
                if(!col[g])
                {
                    col[g] = true;
                    p.push(g);
                    level[g] = lev;
                }
            }
            q.pop();
        }
        lev++;
    }
    while(!p.empty());
}

int main()
{
    int x, y, n, caseno=1;
    while(scanf("%d", &n)&&n)
    {
            l.clear();
            a.clear();
            col.clear();
            level.clear();
        for (int i = 0; i<n; i++)
        {
            scanf("%d %d", &x, &y);
            l.insert(x);
            l.insert(y);
            a[x].pb(y);
            a[y].pb(x);
        }
        set<int> :: iterator it;
        for (it = l.begin(); it!=l.end(); it++)
        {
            col[*it] = false;
            level[*it] = inf;
//        cout<<*it<<endl;
        }

        while(scanf("%d %d", &x, &y)&&(x||y))
        {
            for (it = l.begin(); it!=l.end(); it++)
            {
                col[*it] = false;
                level[*it] = inf;
            }
            bfs(x);
            int em=0;

            for (it = l.begin(); it!=l.end(); it++)
            {
                if(level[*it] > y) em++;
//            cout<<*it<<": "<<level[*it]<<", em = "<<em<<endl;
            }

            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", caseno++, em, x, y);
        }
    }
//    int ssize, s, t;
//    for (it = l.begin(); it != l.end(); it++)
//    {
//        s = *it;
//        cout<<*it<<": "<<level[*it]<<endl;
//        t = a[s].size();
//        printf("m = %d: ", *it);
//        for (int j = 0; j<t; j++)
//            printf("%d ", a[s][j]);
//        printf("\n");
//    }

    return  0;
}
