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
//    	fread;
//	fwrite;
    #endif // ENAM
    double n;
    int m, mm=1e6, div, mo;
    bool flag;
    char line[100];
    while(~scanf("%s", line))
    {
        if(!strcmp(line, "END")) break;
        sscanf(line,"%lf", &n);
        m = (n * 1e6);
        flag = true;
        for (int i = 0; i<100; i++)
        {
            m*=3;
            div = m/mm;
            m%=mm;
            if(div==1)
            {
                flag = false;
                break;
            }
        }
        if(flag) printf("MEMBER\n");
        else printf("NON-MEMBER\n");
    }
    return 0;
}
