/**
* H:\Dropbox\Code\HackerRank\World Cup - University Level CodeSprint 2015\World Cup Game.cpp
* Created on: 2015-09-13-09.49.45, Sunday
* Verdict: Solved
* Author: Enamul Hassan and Khan Mohammad Rumman Mahmud Mahdi Al Masud
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define SZ(a) ((int)a.size())
#define sz 500005
#define pb push_back
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
#define cntbit(mask) __builtin_popcount(mask)
#define unify(a) stable_sort(a.begin(),a.end());a.resize(distance(a.begin(),unique(all(a))));
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e18)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define pi 3.14159265358979323846264338327950288419716939937510
#define fr(i,a,b) for(i=a;i<=b;i++)
#define cspf printf("Case %d:", cas++);
#define csco cout<<"Case "<<cas++<<":";


using namespace std;

int token[sz];

vector<int>adj[sz];

ll score[sz], total, res;

void dfs(int x,int par)
{
    score[x] =  token[x];
    ll mx1=0;
    int y;
    for (int i = 0; i<SZ(adj[x]); i++)
    {
        y = adj[x][i];
        if(y!=par)
        {
            dfs(y,x);

            score[x]+=score[y];

            mx1=max(mx1, score[y]);

        }
    }

    ll sec = total - score[x];

    mx1=max(mx1, sec);

    res = max(res,total-mx1);
}


int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1,x,y;

//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    scanf("%d", &n);

    for (int i = 1; i<=n; i++)
    {
        scanf("%d", &token[i]);
        total+=token[i];
    }
    for (int i = 0; i<n-1; i++)
    {
        scanf("%d %d", &x, &y);
        adj[x].pb(y);
        adj[y].pb(x);
    }

    dfs(1,-1);

    printf("%lld",res);

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}
