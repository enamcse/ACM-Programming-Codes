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

#define sz 100
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
using namespace std;


int main()
{
    int n, cost,ans;
    int flag = 0;
    cin>>n;
    if(n%2)
    {
        cost = 1+n/2;
        ans = (1+n/2)*(1+n/2)+(n/2)*(n/2);
        cout<<ans<<endl;
        for (int i = 0; i<n; i++)
        {
            for (int j = 0; j<n; j++)
            {
                if(flag) cout<<'.';
                else cout<<'C';
                flag^=1;
            }
            cout<<endl;
        }
    }
    else
    {
        ans = n*n/2;
        cout<<ans<<endl;
        for (int i = 0; i<n; i++)
        {

            for (int j = 0; j<n; j++)
            {
                if(flag) cout<<'.';
                else cout<<'C';
                flag^=1;
            }
            flag^=1;
            cout<<endl;
        }
    }
	return 0;
}
