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

int main()
{
#ifdef ENAM
    	fread;
	fwrite;
#endif // ENAM
    int t, n, m, cas=1, k, len, mx=0, p;

    char line[1000];

    scanf("%s %d", line, &k);
    n = 1;
    len = strlen(line);
    t = (len+k);
    m = t/2;
    mx = ((k>>1)<<1);
    while(n<=m)
    {

        for (int j = 0; j<len; j++)
        {
            p = 0;
            for (int i = j; i<j+n; i++)
            {
                if(i>=len&&i+n<t)
                {
                    p++;
                }
                else if(i<len&&i+n>=len&&i+n<t) p++;
                else if(i+n<len)
                {
                    if(line[i]==line[i+n]) p++;
                    else break;
                }
                else break;
            }
            if(n==p)mx = max(mx, p*2);
        }
        n++;
    }

    printf("%d", mx);

    return 0;
}
/*
ngkdgsdxouojadjqzgxewuuyxdlxulgrblxpkyzhgmkeatmhvbdelmxxrqtsarfvotcxfuiqsxbnczbadelhxtlfwrnbisayeveiejvycllhkictyyriqseznziyurlgiejvycllhkictyyriqseznziyurlgwiubyvqfmabhstqalicamyholkqlvtjfhcfbyr
133
*/
