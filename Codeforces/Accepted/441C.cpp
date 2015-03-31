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

#define sz 500
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

map< int, pair<int,int> >mp;

int main()
{
    #ifdef ENAM
//    	fread;
//	fwrite;
    #endif // ENAM
    int t=1, n, cas=1,k,m;
    scanf("%d %d %d", &n, &m, &k);

    for (int i = 1; i<=n; i++)
    {
        if(i%2)
        {
            for (int j = 1; j<=m; j++)
                mp[cas++]= make_pair(i,j);
        }
        else
        {
            for (int j = m; j>=1; j--)
                mp[cas++]= make_pair(i,j);
        }
    }

    for (int i = 0; i<k-1; i++)
    {
        printf("%d ", 2);
        printf("%d %d ", mp[t].first, mp[t].second);
        t++;
        printf("%d %d\n", mp[t].first, mp[t].second);
        t++;
    }
    k = cas-(k<<1)+1;
    printf("%d ", k);

    for (int i = 0; i<k; i++)
    {
        printf("%d %d ", mp[t].first, mp[t].second);
        t++;
    }



    return 0;
}
