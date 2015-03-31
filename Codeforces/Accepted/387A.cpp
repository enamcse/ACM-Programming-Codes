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
    int h, m, h2, m2, total, total2,rem ;
    scanf("%d:%d", &h, &m);scanf("%d:%d", &h2, &m2);
    total = h*60+m;
    total2 = h2*60+m2;
    rem = total - total2;
    if(rem>=0)
    {
        h = rem/60;
        m= rem%60;
    }
    else
    {
        rem+= (24*60);
        h = rem/60;
        m= rem%60;
    }
    printf("%02d:%02d", h, m);


	return 0;
}

























//everybody needs header to write a code, but I need a footer too! :)
