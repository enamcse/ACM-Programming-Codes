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

#define sz 1000
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

int v[sz];

bool check(int mm, int n, int m)
{
    int cnt = 1,sum = 0;
    for (int i = 0; i<n; i++)
    {
        if(mm<v[i]) return false;
        if(sum+v[i]>mm)
        {
            cnt++;
            sum = v[i];
        }
        else sum += v[i];
    }
    return cnt<=m;
}


int main()
{
    #ifdef ENAM
    	fread;
	fwrite;
    #endif // ENAM

    int t, cas=1, ans=0, n, m;

    scanf("%d", &t);

    while(t--)
    {
        scanf("%d %d", &n, &m);

        for (int i = 0; i<n; i++) scanf("%d", &v[i]);

        int bg=1,en=1000000011;

        while(bg<=en)
        {
            int mid = ((bg+en)>>1);
            if(check(mid,n,m)) en = mid-1, ans = mid;
            else bg = mid+1;
        }

        printf("Case %d: %d\n",cas++,ans);
    }


    return 0;
}
