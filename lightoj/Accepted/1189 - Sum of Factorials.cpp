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

#define sz 25
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

ll fact[sz];

int main()
{
    vector<int>v;
    fact[0]=1;
    for (int i = 1; i<=20; i++)
        fact[i]=i*fact[i-1];

    int cas=1,t;
    ll n,lim;
    scanf("%d", &t);
    while(t--)
    {
        v.clear();
        scanf("%lld", &n);
        for (int i = 20; i>=0; i--)
        {
            if(n<=fact[i])
            {
                lim = n;

                for (int j = i; j>=0; j--)
                {
                    if(lim-fact[j]>=0)
                    {
                        v.pb(j);
                        lim-=fact[j];

                    }
                }
                if(lim==0) break;
                else v.clear();
            }
        }
        printf("Case %d: ",cas++);
        lim = v.size();
        if(lim)
        {
            sort(v.begin(),v.end());
            for (int i = 0; i<lim-1; i++)
                printf("%d!+",v[i]);
            printf("%d!\n",v[lim-1]);
        }
        else printf("impossible\n");
    }

	return 0;
}
