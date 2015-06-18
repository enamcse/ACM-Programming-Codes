/* 
* @Author: Enamul Hassan
* @Date:   2015-04-10 01:40:00
* @Last Modified by:   Enamul
* @Last Modified time: 2015-04-10 11:13:36
* @Verdict: Solved
* @File Path: H:\Dropbox\Code\lightoj\1063 - Ant Hills.cpp
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 10005
#define SZ(a) ((int)a.size())
#define pb(a) push_back(a)
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define clr(abc,z) memset(abc,z,sizeof(abc))
using namespace std;

//no problem in multiple edge
int tim[sz],low[sz];
bool flag[sz];
int timer;
vector<int> adj[sz];//only adj should be cleared

void dfs(int u,int par)// par=-1 dhore call dite hobe(root ar parent nai)
{
    tim[u] = low[u] = ++timer;
    int subtree = 0;
    for(int i = 0 ; i<SZ(adj[u]) ; i++)
    {
        int v = adj[u][i];
        if(v==par) continue; //parent check is needed
        if(!tim[v])
        {
            subtree++;
            dfs(v,u);
            low[u] = min(low[u],low[v]);
            if(low[v]>=tim[u] && par!=-1) flag[u] = true; //attention greater equals for bridge and articulation point
        }
        else //determining back edge
        {
            low[u] = min(low[u],tim[v]);
        }
    }

    if(par==-1 && subtree>1) flag[u] = true; //for root
    return;
}

void articulationPoint(int n)
{
	clr(flag,false);
    clr(tim,0);
    timer=0;
    for(int i=1;i<=n;i++)
    if(!tim[i])
        dfs(i,-1);
}


int main(){
	#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1, ans,u,v;
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();


	scanf("%d", &t);

	while(t--)
	{
		scanf("%d %d", &n, &m);
		ans = 0;

		for (int i = 1; i <= n; ++i)
		{
			adj[i].clear();
		}

		for (int i = 0; i<m; i++)
	    {
	        scanf("%d %d", &u, &v);
	        adj[u].pb(v);
	        adj[v].pb(u);
	    }
	    articulationPoint(n);

		for (int i = 1; i <= n; ++i)
			if(flag[i]) ans++;
		printf("Case %d: %d\n", cas++, ans);
	}


//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}












