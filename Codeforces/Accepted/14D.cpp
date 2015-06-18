/* 
* @Author: Enamul Hassan
* @Date:   2015-04-04 19:48:17
* @Last Modified by:   Enamul
* @Last Modified time: 2015-04-04 20:21:57
* @Verdict: Solved
* @File Path: H:\Dropbox\Code\Codeforces\14D.cpp
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 205
#define pb(a) push_back(a)
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)

using namespace std;


struct edge
{
    int u,v;
    edge(){}
    edge(int x, int y)
    {
        u = x;
        v = y;
    }
};
vector<edge>e;

int bada, badb;
int mxw, mxnode;
vector<int>adj[sz];

int dfs(int pos, int par, int depth)
{
	if(depth>mxw)
	{
		mxw = depth;
		mxnode = pos;
	}
    int ret = 0;

    for(int i = 0; i<adj[pos].size(); i++)
    {
        if(adj[pos][i]==par) continue;
        if((pos==bada&&badb==adj[pos][i]) || (pos==badb&&bada==adj[pos][i])) continue;
        ret=max(ret,(dfs(adj[pos][i],pos, depth+1) + 1));
    }

    return ret;
}


int getChain(int n, int pre)
{
	mxw=0;mxnode=-1;
	dfs(n,pre,1);
	return dfs(mxnode,-1,0);
}

int main(){
	#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

	int x,y,n, ans = 0,  now, now2;

    cin>>n;

    for(int i = 1; i<n; i++)
    {
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
        e.pb(edge(x,y));
    }

    for (int i = 0; i<e.size(); i++)
    {
        if(adj[ e[i].u ].size()==1 || adj[ e[i].v ].size() ==1 )
            continue;

        bada = e[i].u;
        badb = e[i].v;

        now = getChain(bada,badb);
        now2 = getChain(badb,bada);
        ans = max(ans, now*now2);
    }
    cout<<ans<<"\n";
	


//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}












