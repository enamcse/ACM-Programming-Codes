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

vector<int>a,b;

int main()
{
    int t, n, m, cas=1, k, sum, j;
    while(~scanf("%d %d", &n, &m)&&(n||m))
    {
        a.clear();b.clear();
        for (int i = 0; i<n; i++)
        {
            scanf("%d", &k);
            a.pb(k);
        }
        sort(a.begin(),a.end());
        for (int i = 0; i<m; i++)
        {
            scanf("%d", &k);
            if(k>=a[0])b.pb(k);
        }
        m = b.size();
        if(n>m)
        {
            printf("Loowater is doomed!\n");
            continue;
        }
        sort(b.begin(),b.end());
        sum = 0;
        k = 0;
        j=0;
        for (int i = 0; i<n; i++)
        {
            for (; k<m; k++)
            {
                if(a[i]<=b[k])
                {
                    sum+=b[k];
                    k++;
                    j++;
                    break;
                }
            }
        }
        if(j==n) printf("%d\n", sum);
        else printf("Loowater is doomed!\n");

    }

    return 0;
}
