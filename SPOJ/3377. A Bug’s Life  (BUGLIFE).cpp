#include <iostream>
#include <string.h>
#include<stdio.h>
#include<list>
#include<set>
#include<queue>

using namespace std;

bool graph[2000][2000];
int col[2000];
set<int>s;

int if_col(int n)
{
    set<int>::iterator it;
    for (it = s.begin(); it!=s.end(); it++)
    {
        if(!col[*it]) return (*it);
    }
    return n;
}

bool bfs(int n)
{
    int a = 0, c = 1, dec;
    queue<int>q;
    a = if_col(n);
    while(a!=n)
    {
        q.push(a);
        while(!q.empty())
        {
            a = q.front();
            if(col[a]==1) dec =2;
            else dec = 1;
            q.pop();
            for (int i = 0; i<n; i++)
            {
                if(i==a||graph[a][i]==false) continue;
                if(col[i]==0)
                {
                    col[i] = dec;
                    q.push(i);
                }
                else if(col[i]!=dec) return false;
            }
        }
        a = if_col(n);
    }
    return true;
}

int main()
{
    int t, n, m, seen=1,i , j;
    scanf("%d", &t);
    while(t--)
    {
        memset(col,0,sizeof(col));
        memset(graph,false,sizeof(graph));
        s.clear();
        scanf("%d %d", &n, &m);
        while(m--)
        {
            scanf("%d %d", &i, &j);
            graph[i-1][j-1] = true;
            graph[j-1][i-1] = true;
            s.insert(i-1);
            s.insert(j-1);
        }
        if(!bfs(n)) printf("Scenario #%d:\nSuspicious bugs found!\n", seen++);
        else printf("Scenario #%d:\nNo suspicious bugs found!\n", seen++);
    }
    return 0;
}
