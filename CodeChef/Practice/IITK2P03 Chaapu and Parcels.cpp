/**
* H:\Dropbox\Code\CodeChef\Practice\IITK2P03 Chaapu and Parcels.cpp
* Created on: 2015-03-04-23.59.11, Wednesday
* Verdict: Solved
* Author: Enamul Hassan
* Problem link: http://www.codechef.com/problems/IITK2P03
* Concept: If we fixed the T and tell how many gift could be sent over
           this time then we could find it using best matching or
           Bipartite Matching. Because here, our target is to maximize
           the matching number between gift and channel. However, we
           can fixed the T by using binary search on T. If it can be
           possible to make at least K pair in time T, then we would
           go left, otherwise go right.
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 105
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define clr(abc,z) memset(abc,z,sizeof(abc))

using namespace std;

ll arr[sz][sz], mid;
int  n,m, counter=1, visited[sz], par[sz];
int dfs(int u)
{
    if(visited[u]==counter) return 0;
    visited[u] = counter;
    int len = m;
    for (int i = 0; i<len; i++)
    {
        if(arr[u][i]>mid) continue;
        if(par[i]==-1 || dfs(par[i])==true)
        {
            par[i] = u;
            return 1;
        }
    }
    return 0;
}


int BPM()
{
    int ret = 0;
    clr(par,-1);
    for (int i = 0; i<n; i++)
    {
        ret+=dfs(i);
        counter++;
    }

    return ret;
}



int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    ll lef=0,righ=1e12, ans,k;
    cin>>n>>m>>k;

    for (int i = 0; i<n; i++)
        for (int j = 0; j<m; j++)
            cin>>arr[i][j];

    while(lef<=righ)
    {
        mid=(lef+righ)/2LL;

        if(BPM()<k) lef=mid+1;
        else
        {
            righ=mid-1;
            ans = mid;
        }
    }
    cout<<ans;

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
