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

#define sz 1000010
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

int num[sz];

int main()
{
    int t  = 500000, n, m, cas=1, s = 1000000, k;
    vector<int>ans;
    vector<int>input;
    scanf("%d", &n);
    for (int i = 0; i<n; i++)
    {
        scanf("%d", &m);
        num[m]=1;
        input.pb(m);
    }
    int j=1;
    for (int i = 0; i<n; i++)
    {
        if(num[input[i]]==2) continue;
        if(num[s-input[i]+1]==0)
        {
            ans.pb(s-input[i]+1);
            num[ s-input[i]+1 ] = 1;
        }
        else
        {
            num[s-input[i]+1] = 2;
            for (; j<=t; j++)
                if(!num[j]&&!num[s-j+1])
                {
                    ans.pb(j);
                    num[ j ] = 1;
                    ans.pb(s-j+1);
                    num[ s-j+1 ] = 1;
                    break;
                }
        }
    }
    n = ans.size();
    printf("%d\n", n);
    for (int i = 0; i<n; i++)
    {
        printf("%d ", ans[i]);
    }



    return 0;
}
