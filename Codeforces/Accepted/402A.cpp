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

int main()
{
    int t, n, m, cas=1, k, v, b,a;
    cin>>k>>a>>b>>v;
    n=0;
    m=a;

    while(m>0)
    {
        if(m<=v)
        {
            n++;
            break;
        }
        if(b<k-1)
        {
            if(b>0)
            {
                m-=((b+1)*v);
                b=0;
                n++;
            }
            else
            {
                m-=v;
                n++;
            }
        }
        else
        {
            n++;
            m-=(k*v);
            b-=(k-1);
        }

    }
    cout<<n;
    return 0;
}
