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
    int t, n, r, p, q, twos, fives, cas=1, k, x;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d %d",&n,&r,&p,&q);
        twos=fives=0;
        k = n;
        while(k)
        {
            k>>=1;
            twos+=k;
        }
        k = r;
        while(k)
        {
            k>>=1;
            twos-=k;
        }
        k = n-r;
        while(k)
        {
            k>>=1;
            twos-=k;
        }

        k = n;
        while(k)
        {
            k/=5;
            fives+=k;
        }
        k = r;
        while(k)
        {
            k/=5;
            fives-=k;
        }
        k = n-r;
        while(k)
        {
            k/=5;
            fives-=k;
        }

        k=p;
        x=0;
        while(k%2==0)
        {
            x++;
            k>>=1;
        }
        twos+=(x*q);
        k=p;
        x=0;
        while(k%5==0)
        {
            x++;
            k/=5;
        }
        fives+=(x*q);
        printf("Case %d: %d\n", cas++, min(twos, fives));
    }
	return 0;
}