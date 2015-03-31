#include <iostream>
#define sz 100
using namespace std;

bool colour[sz][sz];
bool graph[sz][sz];
struct node
{
    int x;
    int y;
};

node Q[sz];
void dfs(node a, int m, int n);

int main()
{
    node a;
    int i,j,count,m,n;
    char w;
    cin>>m>>n;
    while(m!=0)
    {
        count=0;
        for (i=0; i<m; i++)
        {
            for (j=0; j<n; j++)
            {
                cin>>w;
                if(w=='@') graph[i][j] = true;
                else graph[i][j] = false;
                colour[i][j] = false;
            }
        }

        for (i=0; i<m; i++)
            for (j=0; j<n; j++)
            {
                if(colour[i][j]==false&&graph[i][j]==true)
                {
                    a.x = i;
                    a.y = j;
                    dfs(a,m,n);
                    count++;
                }
                else colour[i][j]==true;
            }
        cout<<count<<endl;
        cin>>m>>n;
    }


    return 0;
}

void dfs(node p, int m, int n)
{
    int i, j, front, rear;
    node a;
    front = rear = 0;
    i = Q[rear].x = p.x;
    j = Q[rear++].y = p.y;

    colour[i][j] = true;

    while(front<rear)
    {
        a.x = Q[front].x;
        a.y = Q[front++].y;
        for (i=a.x-1; i<=a.x+1; i++)
        {
            for (j=a.y-1; j<=a.y+1; j++)
            {
                if(i>=0&&j>=0&&i<m&&j<n)
                {
                    if(colour[i][j]==false)
                    {
                        if(graph[i][j]==true)
                        {
                            Q[rear].x = i;
                            Q[rear++].y = j;
                        }
                        colour[i][j]=true;
                    }
                }
            }
        }
    }
    return;
}
