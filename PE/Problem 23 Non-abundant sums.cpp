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

#define sz 55
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

vector<int>v;
int len, m= 28123;
bool flag[28140];


int main()
{
    #ifdef ENAM
//    	fread;
//	fwrite;
    #endif // ENAM
    int ans=0,t, n, cas=1;

    for (int i = 6; i<=m; i++)
    {
        int sum = 0;
        for (int j = 1; j<i; j++)
            if(i%j==0) sum+=j;
        if(sum>i) v.pb(i);
    }
    len = v.size();

    for (int i = 0; i<len; i++)
        for (int j = 0; j<len; j++)
            if(v[i]+v[j]<=m) flag[ v[i] + v[j]  ] = true;

    for (int i = 1; i<=m; i++)
        if(!flag[i]) ans+=i;
    cout<<ans<<endl;
    return 0;
}
