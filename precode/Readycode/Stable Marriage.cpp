#include <cstdio>
#include <stack>
#define sz 200

using namespace std;

int main()
{
    int n,t,cas=1,x,p,q,r;
    int cand[sz][sz],comp[sz][sz];
    stack<int>qq;
    int conn[sz];
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);

        for (int i = n-1; i>=0; i--)
        {
            qq.push(i);
            conn[i]=-1;
        }

        for (int i = 0; i<n; i++)
        {
            for (int j = 0; j<n; j++)
            {
                scanf("%d", &cand[i][j]);
                cand[i][j]-=(n+1);
            }
        }

        for (int i = 0; i<n; i++)
        {
            for (int j = 0; j<n; j++)
            {
                scanf("%d", &comp[i][j]);
                comp[i][j]--;
            }
        }

        while(!qq.empty())
        {
            x = qq.top();
            qq.pop();
            int k = 0;
            while(cand[x][k]==-1) k++;
            p = cand[x][k];
            if(conn[p]==-1) conn[p] = x;
            else
            {
                for (int i = 0; i<n; i++)
                    if(comp[p][i]==conn[p])
                    {
                        q = i;
                        break;
                    }
                for (int i = 0; i<n; i++)
                    if(comp[p][i]==x)
                    {
                        r = i;
                        break;
                    }

                if(r<q)
                {
                    qq.push(conn[p]);
                    conn[p] = x;
                }
                else qq.push(x);
            }
            cand[x][k]=-1;
        }

        printf("Case %d:",cas++);
        for (int i = 0; i<n; i++) printf(" (%d %d)", conn[i]+1,n+i+1);
        printf("\n");
    }

	return 0;
}
/*
1
3
4 5 6
4 5 6
4 5 6
1 2 3
1 2 3
1 2 3
*/
