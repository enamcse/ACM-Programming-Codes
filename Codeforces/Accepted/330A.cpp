#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 100
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
using namespace std;

char graph[11][11];

int main()
{
    _
    int r, c, er=0, ec=0;
    bool flag;
    cin>>r>>c;

    for (int i = 0; i<r; i++)
        cin>>graph[i];

    for (int i = 0; i<r; i++)
    {
        flag = true;
        for (int j = 0; j<c; j++)
            if(graph[i][j]=='S') flag = false;
        if(flag) er++;
    }

    for (int i = 0; i<c; i++)
    {
        flag = true;
        for (int j = 0; j<r; j++)
            if(graph[j][i]=='S') flag = false;
        if(flag) ec++;
    }
    cout<<(r*ec+(er*(c - ec)))<<endl;
    return 0;
}
