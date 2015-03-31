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

int first[sz], second[sz];


int main()
{
    int t, n, m, cas=1, cnt=0, now;
    string a, b;
    cin>>a>>b;

    n = a.length();
    m = b.length();

    for (int i = 0; i<n; i++)
        first[ a[i] - 'a' ]++;

    for (int i = 0; i<m; i++)
        second[ b[i] - 'a' ]++;

    for (int i = 0; i<26; i++)
    {
        if(second[i]&&!first[i])
        {
            cout<<"-1"<<endl;
            return 0;
        }
        now = second[i] - first[i];

        now = (now<0?second[i]:first[i]);
        cnt+=now;
    }
    if(cnt==0) cout<<"-1"<<endl;
    else cout<<cnt<<endl;
    return 0;
}
