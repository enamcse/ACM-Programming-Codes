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

#define sz 50
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

int cnt, prev;

int main()
{
    #ifdef ENAM
//    	fread;
//	fwrite;
    #endif // ENAM
    int t, m, now;
    char line[sz];
    cin>>line;
    m = strlen(line);
    for (int i = 0; i<m; i++)
    {
        t = line[i]-'0';
        cout<<t<<" : "<<prev<<endl;
        if(t>prev)
        {
            now = t - prev;
            int a = (m-i)*now;
            int b = (m-i+1) + (prev+11-t)*(m-i);
            cout<<a<<"/"<<b<<endl;
            if(a<=b)
            {
                cnt+=a;
                prev+=now;
            }
            else
            {
                prev+=(t-prev-10);
                cnt+=b;
            }

        }
        else if(t<prev)
        {
            now = prev-t;
            cnt+=(m-i)*now;
            prev-=now;
        }
    }
    cout<<cnt<<endl;

    return 0;
}
