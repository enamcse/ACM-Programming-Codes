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

#define sz 7005
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

int day[sz];

int main()
{
    #ifdef ENAM
//    	fread;
//	fwrite;
    #endif // ENAM
    int t, n, m=0, cas=1, v, x, y, rep=0;

    scanf("%d %d", &n, &v);

    for (int i = 0; i<n; i++)
    {
        scanf("%d %d", &x, &y);
        day[x]+=y;
    }

    for (int i = 0; i<sz; i++)
    {
        if(rep)
        {
            if(rep>v) m+=v, rep = day[i];
            else
            {
                rep+=day[i];
                if(rep>v) m+=v, rep-=v;
                else m+=rep, rep=0;
            }
        }
        else
        {
            if(day[i]>v) m+=v, rep = day[i]-v;
            else m+=day[i];
        }
    }


    printf("%d", m);

    return 0;
}