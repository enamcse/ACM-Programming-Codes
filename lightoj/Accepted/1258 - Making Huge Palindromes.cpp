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

#define sz 1000055
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

char input[sz];

//KMP starts
string line;
int overlap[(sz<<1)];
int kmp()
{
    int len = line.size(), v;
    clr(overlap,0);
    for (int i = 1; i<len; i++)
    {
        v = overlap[i-1];

        while(line[v]!=line[i] && v>0)
            v = overlap[v-1];
        if(line[v]==line[i]) overlap[i] = v+1;
        else overlap[i] = v;
    }

    return overlap[len - 1];
}
//KMP ends


int main()
{
    #ifdef ENAM
    	fread;
	fwrite;
    #endif // ENAM
    int t, n, m, cas=1;
    string temp;
    scanf("%d", &t);

    while(t--)
    {
        scanf("%s", input);
        temp = line = input;
        reverse(line.begin(),line.end());
        line =  line + '#' + temp;
        n=line.size()-1;
        printf("Case %d: %d\n", cas++, n-kmp());
    }

    return 0;
}