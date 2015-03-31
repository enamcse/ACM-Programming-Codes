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

#define sz 155
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

int a[sz], b[sz];
vector<ll>rest;
vector<ll>::iterator  it;

int main()
{
    #ifdef ENAM
    	fread;
	fwrite;
    #endif // ENAM
    int t=0, n, m, cas=1;
    ll points=0L;
    scanf("%d %d", &n, &m);

    for (int i = 0; i<n; i++)
        scanf("%d", &a[i]);

    for (int i = 0; i<m; i++)
        scanf("%d", &b[i]);
    b[m]= inf;


    sort(b,b+m);

    for (int i = 0; i<n; i++)
    {
        if(b[t]-1==i) rest.pb(a[i]),t++;
        else points += a[i];
    }

    sort(rest.begin(), rest.end());
    m = rest.size();
    for (int i = 0; i<m; i++)
    {
        if(rest[ rest.size() - 1 ]>=points)
        {
            points+= rest[ rest.size()-1];
            rest.erase(rest.begin() + rest.size()-1);
            continue;
        }
        it = upper_bound(rest.begin(), rest.end(), points);
        if(it!= rest.begin())
        {
            points<<=1L;
            rest.erase(it-1);
        }
        else
        {
            points+= rest[ rest.size()-1];
            rest.erase(rest.begin() + rest.size()-1);
        }
    }
    printf("%I64d", points);

    return 0;
}
