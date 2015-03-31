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

string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November" , "December"};
ll cum[] = {0,31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30 , 31},i,j;
int main()
{
    fr(i,1,11) cum[i]+=cum[i-1];
    char first[2][10];
    string str;
    ll n, m[2],y[2],d[2], t, cas=1,leap[2], rest[2];
    scanf("%lld", &t);
    while(t--)
    {
        fr(i,0,1)
        {
            scanf("%s %lld, %lld", first[i], &d[i],&y[i]);
            str = first[i];
            fr(j,0,11)
                if(str==months[j])
                {
                    m[i] = j+1;
                    break;
                }

            leap[i] = (y[i]/400)*97;
            rest[i] = y[i]%400;
//            print2(rest[i],leap[i]);
            leap[i] += (rest[i]/100)*24;
            rest[i] = y[i]%100;
//            print2(rest[i],leap[i]);
            leap[i] += (rest[i]/20)*5;
            rest[i] = y[i]%20;
//            print2(rest[i],leap[i]);
            leap[i] += (rest[i]/4);
            rest[i] = y[i]%4;
//            print2(rest[i],leap[i]);
            if(!(y[i]%400)||(y[i]%100&&!(y[i]%4)))
            {
                d[i] += cum[m[i]-1];
                if(i==0)
                {
                    if(d[i]<=60) leap[i]--;
                }
                else
                {
                    if(d[i]<60) leap[i]--;
                }
            }
        }
        printf("Case %lld: %lld\n",cas++,(leap[1]-leap[0]));
    }
	return 0;
}
