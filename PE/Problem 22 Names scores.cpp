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
#define fread freopen("names.txt","r",stdin)
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

struct name{
    string nam;
    int val;
    name(char a[], int vin)
    {
         nam  = a;
         val = vin;
    }
};

vector<name>v;

bool comp(name a, name b)
{
    return a.nam<b.nam;
}


int main()
{
    #ifdef ENAM
    	fread;
	fwrite;
    #endif // ENAM

    int t=0, n, m=0, cas=0;
    bool flag = false;
    char naming[100000], line[100];
    gets(naming);
    n = strlen(naming);
    ll ans=0;

    while( t<n )
    {

        if(naming[t]=='\"')
        {
            flag^=1;
            if(flag == false)
            {
                line[cas] = '\0';
                v.pb(name(line,m));
                cas = m = 0;
            }
        }
        else if(flag)
        {
            line[cas++] = naming[t];
            m+=(naming[t]-'A'+1);
        }
        t++;
    }
    sort(v.begin(), v.end(), comp);
    for (int i = 0; i<v.size(); i++)
        ans+=(v[i].val * (ll) (i + 1) );
    cout<<ans<<endl;



    return 0;
}
