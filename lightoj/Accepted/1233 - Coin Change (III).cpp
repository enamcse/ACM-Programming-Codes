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
#include <stack>

#define sz 100010
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 100000007
using namespace std;

int a[100],c[100];
int dp[sz],used[sz];

typedef  pair<ll,int> pir;

vector<pir>vect;

int coin_change(int n,int target)
{
    clr(dp,0);
    dp[0]=1;
    int sum=0,len,deb,upto,tung;
    for (int i = 0,j; i<n; i++)
    {
        clr(used,0);
        j = vect[i].second;
        tung = 0;
        while(j!=a[tung]) tung++;
        upto = c[tung];
        len = min(vect[i].first,(ll)target);
        while(j<=len)
        {
            deb = (j - vect[i].second);
            if(used[deb]<upto&&!dp[j]){
            dp[j]+=dp[deb];
            used[j]=used[deb]+1;
            }
            j++;
        }
    }

    for (int i = 1; i<=target; i++)
        if(dp[i])sum++;

    return sum;
}

int main()
{
    int cas=1,t,n,k;
    scanf("%d",&t);
    while(t--)
    {
        vect.clear();
        scanf("%d %d",&n,&k);
        for (int i = 0; i<n; i++)
            scanf("%d",&a[i]);

        for (int i = 0; i<n; i++)
            scanf("%d",&c[i]);

        for (int i = 0; i<n; i++)
            vect.pb(make_pair(a[i]*c[i],a[i]));
        sort(vect.begin(),vect.end());
        for (int i = 1; i<n; i++)
            vect[i].first+=vect[i-1].first;
        printf("Case %d: %d\n",cas++,coin_change(n,k));
    }
    return 0;
}
/*
1
2 26
5 11 3 1
*/
