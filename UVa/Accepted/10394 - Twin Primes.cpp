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

#define sz 20002000
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

map<int, pair<int,int> >m;
bool siv[sz];
int primes[sz], cnt;

void seive()
{
    int len = sqrt(sz);
    for (int i = 3; i<=len; i+=2)
    {
        if(siv[i]==false)
        {
            for (int j = i*i; j<sz; j+=i+i)
                siv[j] = true;
        }
    }
    primes[cnt++] = 2;
    for (int i = 3; i<sz; i+=2)
        if(!siv[i]) primes[cnt++] = i;
    return;
}

int main()
{
    #ifdef ENAM
    	fread;
	fwrite;
    #endif // ENAM
    seive();
    cnt--;
    int now=1;
    for (int i = 0; i<cnt; i++)
    {
        if(primes[i]+2==primes[i+1])
            m[now++]= make_pair(primes[i], primes[i+1]);
    }
    int n;
    while(scanf("%d", &n)==1)
        printf("(%d, %d)\n", m[n].first, m[n].second);
    return 0;
}
