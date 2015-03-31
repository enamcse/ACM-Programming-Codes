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
#define fread freopen("a2.in","r",stdin)
#define fwrite freopen("a2.out","w",stdout)
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
    int t, n, m, cas=1,l1,l2, ind;

    char line1[10000], line2[10000], ans1[100000], ans2[100000];

    scanf("%d", &t);

    while(t--)
    {
        scanf(" %s %s", line1, line2);

        ind = 0;
        l1 = strlen(line1);
        l2 = strlen(line2);
        n = l1;
        for (int i = 0; i<l1&&i<l2; i++)
        {
            if(line1[i]!=line2[i])
            {
                n = i;
                break;
            }
        }
//        cout<<l1<<" & "<<l2<<" "<<n<<" "<<m;
        m = min(n,l2);
        n = l2 - n;
//        cout<<" "<<n<<endl;
        for (int i = 0; i<n; i++)
            ans1[ind++]='<';
        for (int i = m; i<l1; i++)
            ans1[ind++]=line1[i];
         ans1[ind++] = '*';
        ans1[ind] = '\0';
        sprintf(ans2,"*%s*", line1);
//        cout<<" :"<<ans1<<endl;
//        cout<<"::"<<ans2<<endl;
        if(strlen(ans2)<ind) puts(ans2);
        else puts(ans1);
    }

    return 0;
}
