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

#define sz 50005
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

vector<int>dot, att;
int p,q;
int main()
{
    #ifdef ENAM
//    	fread;
//	fwrite;
    #endif // ENAM
    int t, n,  cas=1;

    char line[5000];

    cin>>line;

    n = strlen(line);


    for (int i = 1; i<n-2; i++)
    {
        if(line[i]=='d'&&line[i+1]=='o'&&line[i+2]=='t'&&i<n-3) dot.pb(i);
        else if(line[i]=='a'&&line[i+1]=='t'&&att.size()<1) att.pb(i);
    }

    dot.pb(n);
    att.pb(n);

    for (int i = 0; i<n; i++)
    {
        if(i==dot[p])
        {
            printf(".");
            i+=2;
            p++;
        }
        else if(i==att[q])
        {
            printf("@");
            q++;
            i++;
        }
        else printf("%c", line[i]);
    }


    return 0;
}
