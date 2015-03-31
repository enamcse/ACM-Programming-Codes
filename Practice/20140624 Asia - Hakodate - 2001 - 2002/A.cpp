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

vector<int>cube, tetrahed, total;

int main()
{
    #ifdef ENAM
//    	fread;
//	fwrite;
    #endif // ENAM
    int t, n, m, cas=1;

    for (int i = 0; i*i*i<=151200; i++)
        cube.pb(i*i*i);

    total = cube;

    for (int i = 0; (i*(i+1)*(i+2))/6<=151200; i++)
        tetrahed.pb((i*(i+1)*(i+2))/6), total.pb((i*(i+1)*(i+2))/6);

    for (int i = 0; i<cube.size(); i++)
        for (int j = 0; j<tetrahed.size(); j++)
            total.pb(cube[i]+tetrahed[j]);

    sort(total.begin(), total.end());

    while(~scanf("%d", &n)&&n)
    {
        m = lower_bound(total.begin(), total.end(), n) - total.begin();
        if(binary_search(total.begin(), total.end(), n))printf("%d\n", n);
        else printf("%d\n", total[m-1]);
    }



    return 0;
}
