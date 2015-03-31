#include <iostream>
#include <queue>
using namespace std;
int bfs (int x, int y);
char graph[25][25];
int n;
int main()
{
    int s, caseno=1;
    char c;

    while(cin>>n)
    {
        s = 0;
        for (int i = 0; i<n; i++)
            for (int j = 0; j<n; j++)
            {
                cin>>graph[i][j];
            }

        for (int i = 0; i<n; i++)
            for (int j = 0; j<n; j++)
                if(graph[i][j]=='1') s += bfs(i,j);

        cout<<"Image number "<<caseno++<<" contains "<<s<<" war eagles."<<endl;
    }
    return 0;
}

int bfs (int x, int y)
{
    queue <int> q;
    q.push(x);
    q.push(y);

    while(!q.empty())
    {
        int i, j;
        int u = q.front(); q.pop();
        int v = q.front(); q.pop();
        graph[u][v]='0';
        for (i=u-1; i<=u+1; i++)
        {
            for (j=v-1; j<=v+1; j++)
            {
                if(i>=0&&j>=0&&i<n&&j<n)
                {
                    if(graph[i][j]=='1')
                    {
                        graph[i][j]='0';
                        q.push(i);
                        q.push(j);
                    }
                }
            }
        }
    }

    return 1;
}
