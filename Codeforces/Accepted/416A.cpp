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

int main()
{
    #ifdef ENAM
    	fread;
	fwrite;
    #endif // ENAM
    int t, n, m, cas=1, mn=-2e9, mx = 2e9;
    char line[5], an;
    scanf("%d", &n);
    for (int i = 0; i<n; i++)
    {
        scanf("%s %d %c", line, &m,&an);
        if(strlen(line)==1)
        {
            if(line[0]=='>')
            {
                if(an=='Y') mn = max(m+1,mn);
                else mx = min(m,mx);
            }
            else
            {
                if(an=='Y') mx = min(m-1,mx);
                else mn = max(m,mn);
            }
        }
        else
        {
            if(line[0]=='>')
            {
                if(an=='Y') mn = max(m,mn);
                else mx = min(m-1,mx);

            }
            else
            {
                if(an=='Y') mx = min(m,mx);
                else mn = max(m+1,mn);
            }
        }
    }

    if(mn>mx)
    {
        printf("Impossible\n");
    }
    else
    {
        ll k = ((ll)mn+(ll)mx)/2L;
        m = (int)k;
        printf("%d\n", m);
    }
    return 0;
}
