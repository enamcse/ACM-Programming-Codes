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

int month[] ={31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
    #ifdef ENAM
//    	fread;
//	fwrite;
    #endif // ENAM
    int n=0,cas=1,d=2,m=1,y=1900,mm=1,yy=2001;
    bool t=false;
    while(m<mm||y<yy)
    {
//        cout<<m<<" "<<y<<" "<<d<<endl;
        if(m == 2)
        {
            if(y%400)
            {
                if(y%100)
                {
                    if(y%4) d+=month[1];
                    else d+=29;
                }
                else d+=month[1];
            }
            else d+=29;
        }
        else d+=month[m-1];

        m++;
        if(t)d%=7;
        if(d==1) n++;
        if(m==13)
        {
            m=1;
            y++;
            t=true;
        }
    }
    cout<<n<<endl;

    return 0;
}
