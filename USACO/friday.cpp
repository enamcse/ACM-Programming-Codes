/*
ID: manetsus
LANG: C++
TASK: friday
*/
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
#define fread freopen("friday.in","r",stdin)
#define fwrite freopen("friday.out","w",stdout)
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

int month[] = {31,28,31,30,31,30, 31, 31, 30, 31, 30 ,31}, days[7];

int main()
{
    fread;
    fwrite;
    int n, year = 1900, m = 0, day = 2;
    cin>>n;
    for (int j = 0; j<n; j++)
    {
        for (int i = 0; i<12; i++)
        {
            day%=7;
            days[day]++;
            if (i!=1) day+=month[i];
            else
            {
                year = 1900+j;
                if(!(year%400)||((year%100)&& !(year%4))) day+=29;
                else day+=month[i];
            }
        }
    }
    for (int i = 2; i<7; i++)
        cout<<days[i]<<" ";
    cout<<days[0]<<" "<<days[1]<<endl;
	return 0;
}
