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


int k[sz], m[sz][sz] ;

int main()
{
    int t, n, cas=1, mn = inf,cnt;

    scanf("%d", &n);

    for (int i = 0; i<n; i++)
        scanf("%d", &k[i]);

    for (int i = 0; i<n; i++)
        for (int j = 0; j<k[i]; j++)
            scanf("%d", &m[i][j]);

    for (int i = 0; i<n; i++)
    {
        cnt=k[i]*15;
        for (int j = 0; j<k[i]; j++)
            cnt+=m[i][j]*5;
        mn = min(mn,cnt);
    }

    printf("%d", mn);

    return 0;
}