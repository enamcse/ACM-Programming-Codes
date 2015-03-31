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

int occ[26];

int main()
{
    int t, n, mn, cas=1;
    string s;
    cin>>s;

    n = s.size();
    for (int i = 0; i<n; i++)
        occ[ s[i] - 'a' ]++;
    t=occ['n'-'a'];
    t-=3;
    while(t>0) occ['n'-'a']++,t-=2;
    mn = occ['n'-'a']/3;
    mn = min(mn,occ['e'-'a']/3 );
    mn = min(mn,occ['i'-'a'] );
    mn = min(mn,occ['t'-'a'] );
    cout<<mn;



    return 0;
}
