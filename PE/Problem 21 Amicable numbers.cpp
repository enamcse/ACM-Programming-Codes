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

set<int>s;


int main()
{
    #ifdef ENAM
//    	fread;
//	fwrite;
    #endif // ENAM
    int cnt=0;

    for (int i = 2; i<10000; i++)
    {
        int sum1=0;
        for (int j = 1; j<i; j++)
            if(i%j==0) sum1+=j;

        int sum2=0;
        for (int j = 1; j<sum1; j++)
            if(sum1%j==0) sum2+=j;
        if(i==sum2&& sum1!=sum2)
        {
            s.insert(sum1);
            s.insert(sum2);
        }
    }

    for (set<int>::iterator it=s.begin(); it!=s.end(); it++) cnt+=*it;


    cout<<cnt<<endl;


    return 0;
}
