/**
* H:\Dropbox\Code\UVa\12549 - Sentry Robots.cpp
* Created on: 2015-01-24-04.11.06, Saturday
* Verdict: Not Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 200005
#define pb(a) push_back(a)
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e18)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define pi 3.14159265358979323846264338327950288419716939937510
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
ll bigmod(ll sonkha,ll ghat,ll vag_const)
{
    ll vag_shesh=1;
    while(ghat>0)
    {
        if(ghat%2==1)
        {
            vag_shesh=(vag_shesh*sonkha)%vag_const;
        }
        ghat/=2;
        sonkha=(sonkha*sonkha)%vag_const;
    }
    return vag_shesh;
}
ll inverse_mod(ll bivajok, ll vag_const)
{
    return bigmod(bivajok,vag_const-2, vag_const);
}

using namespace std;

int n,m;
int grid[105][105];

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1, k,x,y, ans;
    _

    cin>>t;

    while(t--)
    {
        clr(grid,0);
        cin>>n>>m;
        cin>>k;
        for (int i = 0; i<k; i++)
        {
            cin>>x>>y;
            grid[x-1][y-1]=1;
        }
        cin>>k;
        for (int i = 0; i<k; i++)
        {
            cin>>x>>y;
            grid[x-1][y-1]=2;
        }
        ans = 0;

        for (int i = 0; i<n; i++)
        {
            for (int j = 0; j<m; j++)
                if(grid[i][j]==1)
                {
                    x =0;
                    for (int l = j+1; l<m; l++)
                    {
                        if(grid[i][l]==2) break;
                        else if(grid[i][l]==1) x++;
                    }
                    y =0;
                    for (int l = i+1; l<n; l++)
                    {
                        if(grid[l][j]==2) break;
                        else if(grid[l][j]==1) y++;
                    }
                    if(x>y)
                    {
                        for (int l = j+1; l<m; l++)
                        {
                            if(grid[i][l]==2) break;
                            else grid[i][l]=0;
                        }
                    }
                    else
                    {
                        for (int l = i+1; l<n; l++)
                        {
                            if(grid[l][j]==2) break;
                            else grid[l][j]=0;
                        }
                    }
                    ans++;
                }


        }
        cout<<ans<<"\n";

    }



    return 0;
}

/**
2
4 6
4
2 2
2 4
4 2
4 4
3
2 3
3 3
4 3
4 5
6
1 2
1 3
2 4
2 2
3 3
4 3
2
2 3
3 2
*/
