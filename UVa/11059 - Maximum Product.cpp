//Verdict: SOLVED
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

int S[30],n;
ll mx,now;


int main()
{
    #ifdef ENAM
//    	fread;
	fwrite;
    #endif // ENAM
    int cas=1;

    while(~scanf("%d", &n))
    {
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &S[i]);
        }
        mx = 0;

        for (int i = 0; i<n; i++)
        {
            now = S[i];
            mx =max(now,mx);
            for (int j = i+1; j<n; j++)
            {
                now*=S[j];
                mx =max(now,mx);
            }

        }


        printf("Case #%d: The maximum product is %lld.\n\n",cas++,mx);
    }

    return 0;
}
