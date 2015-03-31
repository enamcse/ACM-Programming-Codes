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

int tttt[sz][5];

int m;

void rec(int painter, int pos)
{
    if(pos==m) return;
    if(pos) tttt[pos][painter] = max(tttt[pos][painter-1],tttt[pos-1][painter]) + tttt[pos][painter];
    else tttt[pos][painter] = tttt[pos][painter-1] + tttt[pos][painter];
    rec(painter,pos+1);
    return;
}

int main()
{
#ifdef ENAM
    fread;
    fwrite;
#endif // ENAM
    int n, cas=1;

    scanf("%d %d", &m, &n);
    for (int i =0; i<m; i++)
        for (int j = 0; j<n; j++)
            scanf("%d", &tttt[i][j]);
    for (int i = 1; i<m; i++)
        tttt[i][0]+=tttt[i-1][0];

    for (int i = 1; i<n; i++)
        rec(i,0);
    m--;
    for (int i = 0; i<m; i++)
        printf("%d ", tttt[i][n-1]);
    printf("%d", tttt[m][n-1]);
    return 0;
}
