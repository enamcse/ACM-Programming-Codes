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
#define sz 300
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
using namespace std;

vector <int> node[sz];
int col[sz], n;
//bool flag;

//bool all()
//{
//    for (int i = 0; i<n; i++)
//        if(col[i]==0) return false;
//    if(flag) return true;
//    else
//    {
//        flag = true;
//        return false;
//    }
//}

bool bfs(int x)
{
    int s, c = 1, y;
    s = node[x].size();
    queue<int> p, q;
    p.push(x);
    while(!p.empty())
    {
        if(c==1) c = 2;
        else c = 1;
        while(!p.empty())   //transfering p to q
        {
            q.push(p.front());
            p.pop();
        }
        while(!q.empty())
        {
            x = q.front();
            q.pop();
            if(col[x]==0) col[x] = c;
            else if(col[x]!=c) return false;//cout<<"signal 1"<<endl;
            s = node[x].size();
            for (int i = 0; i<s; i++)
            {
                y = node[x][i];
                if(col[y]==0)
                {
                    if(c==1) col[y] = 2;
                    else col[y] = 1;
                    p.push(y);
                }
                else if (col[y]==c) return false;//cout<<"signal 2"<<endl;
            }
        }
//        if(all()) return true;
    }
    return true;
}

int main()
{
    int e, szz, x, y;
    while(scanf("%d", &n)&&n)
    {
        for (int i = 0; i<n; i++)
            node[i].clear();
        scanf("%d", &e);
        clr(col,0);
        for (int i = 0; i<e; i++)
        {
            scanf("%d %d", &x, &y);
            node[x].pb(y);
            node[y].pb(x);
        }

        //adjacency list
//        for (int i  = 0; i<n; i++)
//        {
//            cout<<"for "<<i<<" :";
//            int k = node[i].size();
//            for (int j = 0; j<k; j++)
//                cout<<node[i][j]<<" ";
//            cout<<endl;
//        }
//        flag = false;
        if(bfs(0)) printf("BICOLORABLE.\n");
        else printf("NOT BICOLORABLE.\n");

//        cout<<"here"<<endl;
//        for (int i = 0; i<n; i++)
//            cout<<i<<"::"<<col[i]<<endl;
//        cout<<"end"<<endl;

    }
    return 0;
}
