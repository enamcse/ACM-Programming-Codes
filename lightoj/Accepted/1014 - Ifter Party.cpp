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

set<int>s;

int main()
{
    int t, cas=1, p, l, n, len, div;
    scanf("%d", &t);
    while(t--)
    {
        s.clear();
        scanf("%d %d", &p, &l);
        n = p - l;
        len = sqrt(n);
        if(l==0) s.insert(1);
        if(n>l)s.insert(n);
        for (int i = 2; i<=len; i++)
        {
            div = n;
            if(div%i==0)
            {
                if(i>l)s.insert(i);
                div/=i;
                if(div>l)s.insert(div);
            }
        }
        if(s.empty()) printf("Case %d: impossible\n", cas++ );
        else
        {
            printf("Case %d:", cas++ );
            for (set<int>::iterator it = s.begin(); it!=s.end(); it++)
                printf(" %d", *it );
                printf("\n");
        }
    }
	return 0;
}
