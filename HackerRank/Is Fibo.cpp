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

#define sz 100
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
#define mod 1000000007
using namespace std;

ll fib[sz];



int main()
{
    fib[0]=0;
    fib[1]=1;
    int i;
    vector<ll>v;
    for (i = 2; fib[i-1]<1000000000000; i++)
        fib[i]=fib[i-1]+fib[i-2];

    for (int j =0; j<i; j++)
        v.pb(fib[j]);
    int t;
    scanf("%d", &t);
    ll n;
    while(t--)
    {
        scanf("%lld", &n);
        if(binary_search(v.begin(),v.end(),n)) printf("IsFibo\n");
        else printf("IsNotFibo\n");
    }

	return 0;
}
