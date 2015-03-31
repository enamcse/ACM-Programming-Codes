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

#define sz 100005
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

vector<ll>even;
vector<ll>odd;

vector<ll>part[sz];

int main()
{
    #ifdef ENAM
//    	fread;
//	fwrite;
    #endif // ENAM
    int t, n, e,o, cas=1, k, p, x, y, z;
    ll d;
    scanf("%d %d %d", &n, &k, &p);

    for (int i = 0; i<n; i++)
    {
        scanf("%I64d", &d);
        if(d%2) odd.pb(d);
        else even.pb(d);
    }
    o = odd.size();
    e = even.size();
    if(k-p<=o)
    {
        int h=p,j = 0,i;
        for (i = 0; i<e; i++,j++)
        {
            j%=p;
            part[j].pb(even[i]);
        }

        for (i = 0; i<k-p; i++,h++)
        {
            part[h].pb(odd[i]);
        }
        x = o - k + p;
        if(x%2==0)
        {
            for (int i = k-p, h = 0; i<o; i++,h++)
            {
                if(h%2==0)j++;
                j%=p;
                part[j].pb(odd[i]);
            }
        }
        else {printf("NO");return 0;}
    }
    else {printf("NO");return 0;}
    printf("YES\n");
    for (int i = 0; i<k; i++)
    {
        o = part[i].size();
        printf("%d", o);
        for (int j = 0; j<o; j++)
            printf(" %I64d", part[i][j]);
        printf("\n");
    }

    return 0;
}
