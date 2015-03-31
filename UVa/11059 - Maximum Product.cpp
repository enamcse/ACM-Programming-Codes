//#include <bits/stdc++.h>
//#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <map>
#include <list>
#include <set>
#include <string>
#include <stack>
#include <bitset>

#define sz 50005
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e9)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
using namespace std;

vector<int>v[20];
vector<int>zero;
int neg[2][20];
bool flag[20];


int main()
{
    #ifdef ENAM
    	fread;
//	fwrite;
    #endif // ENAM
    int t, n, m, cas=1, cnt, ind;
    ll mx, ans;
    while(~scanf("%d", &n))
    {
        if(n==1)
        {
            scanf("%d", ind);
            printf("Case #%d: The maximum product is %d.\n\n",cas++, ind);
        }
        for (int i = 0; i<20; i++)
            v[i].clear();
        clr(neg,-1);
        clr(flag, false);
        ans=0;
        mx = -(2e18);
        cnt=0;ind=0;
        for (int i = 0; i<n; i++)
        {
            scanf("%d", &m);
            if(m==0) {cnt++,ind=0; continue;}
            v[cnt].pb(m);
            if(m<0)
            {
                if(neg[0][cnt]==-1) neg[0][cnt]=ind;
                neg[1][cnt]=ind;
                flag[cnt]^=1;
            }
            ind++;
        }
        cnt++;
        for (int i = 0; i<cnt; i++)
        {
            m = v[i].size();
            if(flag[i])
            {
                ans = -(2e18);
                for (int j = 0; j<neg[1][i]; j++)
                {
                    if(ans==-(2e18)) ans = v[i][j];
                    else ans *= v[i][j];
                }
                mx = max(mx,ans);
                ans = -(2e18);
                cout<<ans<<endl;
                for (int j = neg[0][i]+1; j<m; j++)
                {
                    if(ans==-(2e18)) ans = v[i][j];
                    else ans *= v[i][j];
                }
                mx = max(mx,ans);
            }
            else
            {
                ans = -(2e18);
                for (int j = 0; j<m; j++)
                {
                    if(ans==-(2e18)) ans = v[i][j];
                    else ans *= v[i][j];
                }
                mx = max(mx,ans);
            }
        }

        printf("Case #%d: The maximum product is %lld.\n\n",cas++, ans);
    }

    return 0;
}
