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
#include <climits>

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

struct fib
{
    int seq[205];
} fibo[5000];


int main()
{
#ifdef ENAM
//    	fread;
//    fwrite;
#endif // ENAM
    int t, n, m, cas=1;
    int now, carry;
    for (int i = 1; i<205; i++)
    {
        fibo[1].seq[i] = 0;
        fibo[2].seq[i] = 0;
    }
    fibo[1].seq[0] = fibo[2].seq[0] = 1;

    for (int i = 3; i<5000; i++)
    {
        carry = 0;
        for (int j = 0; j<205; j++)
        {
            now = carry + fibo[i-1].seq[j] + fibo[i - 2].seq[j];

            fibo[i].seq[j]=now%100000;
            carry = now/100000;
        }
        if(fibo[i].seq[199]>=10000)
        {
            cout<<i<<endl;
            break;
        }
    }

    return 0;
}
