#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 1000
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
using namespace std;

bool graph[sz][sz];

int main()
{
    _
    int n,m, p, q;
    bool flag;
    scanf("%d %d", &n, &m);
    for (int i = 0; i<n; i++)
        for (int j =0; j<n; j++)
            graph[i][j] = true;
    for (int i = 0; i<n; i++)
        graph[i][i] = false;
    for (int i  = 0; i<m; i++)
    {
        scanf("%d %d", &p, &q);
        graph[p-1][q-1] = false;
        graph[q-1][p-1] = false;
    }

    for (int i = 0; i<n; i++)
    {
        flag = true;
        for (int j = 0; j<n; j++)
        {
            if(i==j) continue;
            if(graph[i][j]==false)
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            p = i;
            break;
        }
    }
    printf("%d\n", n-1);
    for (int i = 0; i<n; i++)
    {
        if(i==p) continue;
        printf("%d %d\n", p+1, i+1);
    }
    return 0;
}
