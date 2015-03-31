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

#define sz 550
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
    char line[sz];
    int t, n, m, len;

    gets(line);
    n=m=0;
    len = strlen(line);
    for (t=0; t<len; t++)
    {
        if(line[t]=='|') n++;
        if(line[t]=='=') break;
    }
    for (t++; t<len; t++)
    {
        if(line[t]=='|') m++;
    }
    if(abs(n-m)==0) puts(line);
    else if(abs(n-m)==2)
    {
        if(n>m)
        {
            for (t=0; t<len; t++)
            {
                if(line[t]=='|'&&line[t+1]=='|') {t++; break;}
                else printf("%c",line[t]);
            }
            for (; t<len; t++)
            {
                printf("%c",line[t]);
            }
            printf("%c",'|');

        }
        else
        {
            printf("%c",'|');
            for (t=0; t<len-1; t++)
            {
                printf("%c",line[t]);
            }
        }
    }
    else puts("Impossible");


    return 0;
}
