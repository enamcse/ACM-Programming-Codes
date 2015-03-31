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

#define sz 1000
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

int v[sz];

inline bool check(int m, int n, int k)
{
    int cnt = 1,sum = 0;
    for (int i = 0; i<n; i++)
    {
        if(m<v[i]) return false;
        if(sum+v[i]>m)
        {
            cnt++;
            sum = v[i];
        }
        else sum += v[i];
    }
    return cnt<=k;
}

int main()
{
    #ifdef ENAM
    	fread;
//	fwrite;
    #endif // ENAM
    int t, cas=1;

    scanf("%d", &t);

    while(t--)
    {
        int n, k;
        scanf("%d %d", &n, &k);
        n++;k++;
        for (int i = 0; i<n; i++) scanf("%d", &v[i]);
        int bg=1,en=10000110,m;
        while(bg<=en)
        {
            int mid = ((bg+en)>>1);
            if(check(mid,n,k)) en = mid-1, m = mid;
            else bg = mid+1;
        }
        printf("Case %d: %d\n",cas++,m);
        int mid =0, pr=0,cnt=0;

        while(pr<k)
        {
            if(mid+v[cnt]>m)
            {
                printf("%d\n", mid);
                pr++;
                mid = v[cnt];
            }
            else mid += v[cnt];

            if(k-pr>=n-cnt)
            {
                printf("%d\n", mid);
                cnt++;
                while(cnt<n) printf("%d\n", v[cnt++]);
                break;
            }
            cnt++;
        }
    }


}
