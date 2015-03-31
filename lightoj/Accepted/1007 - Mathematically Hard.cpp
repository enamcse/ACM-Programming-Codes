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

#define sz 5000010
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

unsigned ll cum[sz];

void phi_gen()
{
    for (int i = 2; i<sz; i++)
        if(!cum[i])
        {

            for (int j = i; j<sz; j+=i)
            {
                if(!cum[j]) cum[j]=j;
                cum[j]=(cum[j]/i)*(i-1);
            }
        }
    return;
}



int main()
{
    phi_gen();
    for (int i = 1; i<sz; i++)
        cum[i]=(cum[i]*cum[i])+cum[i-1];
    int t, a, b, cas=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d", &a, &b);
        printf("Case %d: %llu\n",cas++,cum[b]-cum[a-1]);
    }
	return 0;
}
