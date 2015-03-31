#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>
#include <cctype>
#define sz 25
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clear(abc,z) memset(abc,z,sizeof(abc))

#define check(i,j)  for (int i = 0; i<H; i++)\
                    {\
                        for (int j = 0; j<W; j++)\
                        {\
                            cout<<color[i][j];\
                        }\
                        cout<<endl;\
                    }

using namespace std;

void bfs (int x, int y);

char graph[sz][sz];
bool color[sz][sz];

queue <int> a,b;
int cnt,W,H;

int main()
{
    int T, caseno=1;
    int x, y;
    scanf("%d",&T);
    while(T--)
    {
        cnt=0;
        scanf("%d %d",&W, &H);
        for (int i = 0; i<H; i++)
        {
            scanf("%s", graph[i]);
        }
        for (int i = 0; i<H; i++)
            for (int j = 0; j<W; j++)
                if(graph[i][j]=='@')
                {
                    x=i, y=j;
                    color[i][j]=true;
                }
                else if (graph[i][j]=='#') color[i][j] = false;
                else if (graph[i][j]=='.') color[i][j] = true;
//        check(k,l)
//        cout<<x<<y<<endl;
        bfs(x,y);
        printf("Case %d: %d\n", caseno++,cnt);
    }

    return 0;
}

void bfs (int x, int y)
{
    a.push(x), b.push(y);
    while(!a.empty())
    {
//        check(k,l)
//        cout<<"::"<<a.front()<<" "<<b.front()<<endl;

        cnt++;
        int i=a.front(), j=b.front();
        color[i][j] = false;
        i=a.front()-1;
        if(i>=0&&color[i][j]==true)
        {
            color[i][j]=false;
            a.push(i);
            b.push(j);
        }
//        cout<<endl;
//        check(k,l)
        i=a.front(), j=b.front()-1;
        if(j>=0&&color[i][j]==true)
        {
            color[i][j]=false;
            a.push(i);
            b.push(j);
        }
//        cout<<endl;
//        check(k,l)
        i=a.front(), j=b.front()+1;
        if(j<W&&color[i][j]==true)
        {
            color[i][j]=false;
            a.push(i);
            b.push(j);
        }
//        cout<<endl;
//        check(k,l)
        i=a.front()+1, j=b.front();
        if(i<H&&color[i][j]==true)
        {
            color[i][j]=false;
            a.push(i);
            b.push(j);
        }
//        cout<<endl;
//        check(k,l)
        a.pop();
        b.pop();

//        cout<<"::"<<a.size()<<" "<<b.size()<<endl;
    }
    return;
}
