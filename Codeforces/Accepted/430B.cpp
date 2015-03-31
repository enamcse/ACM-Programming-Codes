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

int n, k, x, p;

int rec(vector<int>v, int pos)
{
    int cnt = 0;
    bool flag = true;
    for (int i = pos; i<n; i++)
    {
        if(v[i]==x) cnt++;
        else break;
    }
    if(cnt<2) return 0;
    int pre=-1;
    while(flag)
    {

        flag = false;
        while(cnt--) v.erase(pos+v.begin());
        cnt=0;
        for (int i = 0; i<v.size(); i++)
        {
            if(pre==v[i])cnt++;
            else if(cnt>=3) {break;}
            else pre=v[i],cnt=1,pos=i;
        }
        if(cnt>=3) {flag =true;}
    }
    return n - v.size();
}


int main()
{
#ifdef ENAM
//    fread;
//    fwrite;
#endif // ENAM
    int mn = 0;
    vector<int>u,v;
    scanf("%d %d %d",&n,&k, &x);

    for (int i = 0; i<n; i++)
    {
        scanf("%d",&p);
        v.pb(p);
    }

    for (int i = 0; i<n; i++)
    {
        if(v[i]==x){u=v; mn = max(mn, rec(u,i));}
    }
    printf("%d", mn);


    return 0;
}
