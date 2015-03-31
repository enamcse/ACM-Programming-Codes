//Verdict: NOT SOLVED
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
#define all(a) a.begin(),a.end()
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

vector< pair<int,int> >v;
int ans=2;

void check(int a, int b)
{
    int cnt=0, dist,x,y;
    if(v[a].first == v[b].first)
    {
        if(v[a].second == v[b].second) return;
        dist = abs(v[a].second - v[b].second);

        cnt=binary_search(all(v), make_pair(v[a].first+dist, v[a].second))+binary_search(all(v), make_pair(v[b].first+dist, v[b].second));
        ans = min(ans,2-cnt);

        cnt=binary_search(all(v), make_pair(v[a].first-dist, v[a].second))+binary_search(all(v), make_pair(v[b].first-dist, v[b].second));
        ans = min(ans,2-cnt);
    }
    else
    {
        if(v[a].first > v[b].first) chng(a,b);

        x = abs(v[a].second - v[b].second);
        y = abs(v[a].first - v[b].first);

        if(v[a].second == v[b].second)
        {
            dist = abs(v[a].first - v[b].first);

            cnt=binary_search(all(v), make_pair(v[a].first, v[a].second+dist))+binary_search(all(v), make_pair(v[b].first, v[b].second+dist));
            ans = min(ans,2-cnt);

            cnt=binary_search(all(v), make_pair(v[a].first, v[a].second-dist))+binary_search(all(v), make_pair(v[b].first, v[b].second-dist));
            ans = min(ans,2-cnt);
        }
        else if(v[a].second < v[b].second)
        {
            cnt=binary_search(all(v), make_pair(v[a].first+x, v[a].second-y))+binary_search(all(v), make_pair(v[b].first+x, v[b].second-y));
            ans = min(ans,2-cnt);

            cnt=binary_search(all(v), make_pair(v[a].first-x, v[a].second+y))+binary_search(all(v), make_pair(v[b].first-x, v[b].second+y));
            ans = min(ans,2-cnt);
        }
        else
        {
            cnt=binary_search(all(v), make_pair(v[a].first-x, v[a].second-y))+binary_search(all(v), make_pair(v[b].first-x, v[b].second-y));
            ans = min(ans,2-cnt);

            cnt=binary_search(all(v), make_pair(v[a].first+x, v[a].second+y))+binary_search(all(v), make_pair(v[b].first+x, v[b].second+y));
            ans = min(ans,2-cnt);
        }
    }
    return;
}


int main()
{
#ifdef ENAM
//        fread;
//    fwrite;
#endif // ENAM
    int t, n, x,y;

    scanf("%d", &n);

    for (int i = 0; i<n; i++)
    {
        scanf("%d %d", &x, &y);
        v.pb(make_pair(x,y));
    }

    sort(all(v));

    if(n==0) puts("4");
    else if(n==1) puts("3");
    else
    {
        for (int i = 0; ans && i<n; i++)
        {
            for (int j = i+1;ans && j<n; j++)
                check(i,j);
        }
        printf("%d\n", ans);
    }


    return 0;
}

