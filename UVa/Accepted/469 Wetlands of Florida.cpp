#include <iostream>
#include <queue>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int bfs (int x, int y);
string graph[99];
string ex[99];
int n,m;
int main()
{
    int t, caseno=1,x,y, i;
    string in, a, b;
    char abc[1000];
    bool flag = false;
//    string::size_type sz;
    cin>>t;
    cin>>in;
    while(t--)
    {
        graph[0] = in;
        for (i = 1; 1; i++)
        {
            cin>>in;
            if(toupper(in[0])>='A'&&toupper(in[0])<='Z') graph[i] = in;
            else break;
        }
        m = graph[0].size();
        n = i;
        strcpy(abc,in.c_str());
        if(flag)         cout<<endl;
        else flag = true;
        do
        {
//            cout<<in<<"::"<<y<<endl;
            in = abc;
            for (i=0; i<n; i++)
                ex[i] = graph[i];
            if(toupper(in[0])>='0'&&toupper(in[0])<='9')
            {
                x = atoi(in.c_str());
                cin>>y;
//                cout<<in<<":@:"<<y<<endl;
                cout<<bfs(x-1,y-1)<<endl;
            }
            else break;
//            cout<<<<":"<<endl;
        }
        while(scanf("%s", abc)==1);

    }
    return 0;
}

int bfs (int x, int y)
{
    if(x<=n&&y<=m&&ex[x][y]=='W')
    {
        queue <int> q;
    q.push(x);
    q.push(y);
    int cnt=0;
    while(!q.empty())
    {
        int i, j;
        int u = q.front();
        q.pop();
        int v = q.front();
        q.pop();
        cnt++;
        ex[u][v]='L';
        for (i=u-1; i<=u+1; i++)
        {
            for (j=v-1; j<=v+1; j++)
            {
                if(i>=0&&j>=0&&i<n&&j<m)
                {
                    if(ex[i][j]=='W')
                    {
                        ex[i][j]='L';
                        q.push(i);
                        q.push(j);
                    }
                }
            }
        }
    }

    return cnt;
    }
    else return 0;

}
