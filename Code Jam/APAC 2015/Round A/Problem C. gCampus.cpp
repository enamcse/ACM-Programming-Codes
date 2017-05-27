/**
* H:\Dropbox\Code\Code Jam\APAC 2015\Problem C. gCampus.cpp
* Created on: 2015-08-23-12.45.39, Sunday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define SZ(a) ((int)a.size())
#define sz 105
#define pb push_back
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
#define cntbit(mask) __builtin_popcount(mask)
#define unify(a) stable_sort(a.begin(),a.end());a.resize(distance(a.begin(),unique(all(a))));
#define fread freopen("C-large.in","r",stdin)
#define fwrite freopen("outputClarge.txt","w",stdout)
#define inf (5e8)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define pi 3.14159265358979323846264338327950288419716939937510
#define fr(i,a,b) for(i=a;i<=b;i++)
#define cspf printf("Case %d:", cas++);
#define csco cout<<"Case #"<<cas++<<":\n";
#define mod 1000000007

using namespace std;

int adj[sz][sz],grid[sz][sz];
map<tuple<int,int,int>,int>mpp;
int main()
{
#ifdef ENAM
    	fread;
	fwrite;
#endif // ENAM
    int t, n, m, cas=1,x,y,z;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    set<int>ans;
    cin>>t;

    while(t--)
    {
        csco
        ans.clear();
        mpp.clear();
        cin>>n>>m;
        for (int i = 0; i<n; i++)
        {
            for (int j = 0; j<n; j++)
                grid[i][j]=inf,adj[i][j]=inf;
            grid[i][i]=0;
            adj[i][i]=0;
        }
        for (int i = 0; i<m; i++)
        {
            cin>>x>>y>>z;

            adj[x][y] = min(z,adj[x][y]);
            adj[y][x] = adj[x][y];
            grid[x][y] = adj[x][y];
            grid[y][x] = adj[x][y];
            mpp[ make_tuple(x,y,z) ] = i;
        }

        for (int i = 0; i<n; i++)
            for (int j = 0; j<n; j++)
            {
                if(i==j) continue;
                for (int k = 0; k<n; k++)
                {
                    if(i==k || j==k) continue;
                    adj[j][k] = min(adj[j][k], adj[j][i]+adj[i][k]);
                }
            }

//        for (int i = 0; i<n; i++)
//        {
//            for (int j = 0; j<n; j++)
//                cerr<<adj[i][j]<<" ";
//            cerr<<endl;
//        }

        for (auto xx: mpp)
        {
            bool flag = true;
            x = get<0>(xx.first);
            y = get<1>(xx.first);
            z = get<2>(xx.first);
//            cerr<<x<<":"<<y<<"->"<<z<<"\n";
            for (int i = 0; i<n&&flag; i++)
                for (int j = 0; j<n&&flag; j++)
                {
//                    if(i== x|| j==y || i== y|| j==x) continue;
                    if(adj[i][x]+adj[y][j]+z == adj[i][j])
                    {
                        flag = false;
                        break;
                    }
                }
                if(flag) ans.insert(xx.second);
        }

        for (auto xx: ans )
        {
            cout<<xx <<"\n";
        }

    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}

/**
1
3 3
0 1 10
1 2 3
2 1 3
*/
