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

#define sz 110
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

int mat[sz][sz], colsum[sz],rowsum[sz];

int main()
{
    int t, n, m, cas=1,colodd, rowodd, p, q;

    while(~scanf("%d", &n)&&n)
    {
        clr(colsum,0);
        clr(rowsum,0);
        for (int i = 0; i<n; i++)
        {
            for (int j = 0; j<n; j++)
            {
                scanf("%d", &mat[i][j]);
                colsum[j]+=mat[i][j];
                rowsum[i]+=mat[i][j];
            }
        }
        colodd = rowodd = 0;

        for (int i = 0; i<n; i++)
        {
            if((colsum[i]&1)) colodd++, q = i;
            if((rowsum[i]&1)) rowodd++, p = i;
        }

        if(colodd == 0 && rowodd == 0)
        {
            printf("OK\n");
        }
        else if(colodd == 1 && rowodd == 1)
        {
            printf("Change bit (%d,%d)\n", p+1, q+1);
        }
        else
        {
            printf("Corrupt\n");
        }
    }

    return 0;
}
