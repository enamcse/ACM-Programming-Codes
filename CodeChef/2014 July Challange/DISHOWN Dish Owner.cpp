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

#define sz 10005
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

int par[sz], S[sz];

int find_par(int n)
{
    return par[n] = (par[n]==n?n:find_par(par[n]));
}

void disjoint(int x, int y)
{
    int a = find_par(x);
    int b = find_par(y);
    if(a==b) printf( "Invalid query!\n" );
    else if(S[a]>S[b]) par[b] = a;
    else if(S[a]<S[b]) par[a] = b;

    return;
}


void init(int n)
{
    for (int i = 1; i<=n; i++)
        par[i] = i;
    return;
}

int main()
{
    #ifdef ENAM
//    	fread;
//	fwrite;
    #endif // ENAM
    int t, n, q, op, x, y;

    scanf("%d", &t);

    while(t--)
    {

        scanf("%d", &n);
        init(n);
        for (int i = 1; i<=n; i++) scanf("%d", &S[i]);

        scanf("%d", &q);
        for (int i = 0; i<q; i++)
        {
            scanf("%d", &op);
            if(op)
            {
                scanf("%d", &x);
                printf("%d\n", find_par(x));
            }
            else
            {
                scanf("%d %d", &x, &y);
                disjoint(x,y);
            }
        }

    }


    return 0;
}
