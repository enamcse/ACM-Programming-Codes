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

struct data
{
    int h, t, m;
};

data arr[2010];

bool comp(data p, data q)
{
    if(p.m==q.m) return p.h<q.h;
    return p.m<q.m;

}

bool taken[2010];

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int x, n, m, cas=1, cnt=0, ans=0;

    scanf("%d %d", &n, &x);
    m = x;

    int mark = 0;

    for (int i = 0; i<n; i++)
    {
        scanf("%d %d %d", &arr[i].t, &arr[i].h, &arr[i].m);
    }

    sort(arr, arr+n, comp);


    while(true)
    {
        bool flag = true;
        for (int i = n-1; i>=0; i--)
        {

            if(taken[i]==0&&mark==arr[i].t&&arr[i].h<=m)
            {
                cnt++;
                m+=arr[i].m;
                mark^=1;
                taken[i] = 1;
                flag = false;
                break;
            }

        }
        if(flag) break;

    }
    ans = cnt;
    cnt=0;
    mark = 1;
    m = x;
    clr(taken,0);


    while(true)
    {
        bool flag = true;
        for (int i = n-1; i>=0; i--)
        {

            if(taken[i]==0&&mark==arr[i].t&&arr[i].h<=m)
            {
                cnt++;
                m+=arr[i].m;
                mark^=1;
                taken[i] = 1;
                flag = false;
                break;
            }

        }
        if(flag) break;
    }

    ans = max(ans, cnt);
    cout<<ans;

    return 0;
}
