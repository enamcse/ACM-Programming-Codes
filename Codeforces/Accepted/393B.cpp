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

#define sz 200
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

double W[sz][sz], A[sz][sz], B[sz][sz];


int main()
{
    int n, m, cas=1, num;
    scanf("%d", &n);
    double haf;
    for (int i = 0; i<n; i++)
        for (int j = 0; j<n; j++)
        {
            scanf("%d", &num);
            W[i][j] = num;
        }

    for (int i = 0; i<n; i++)
        A[i][i] = W[i][i];


    for (int i = 0; i<n; i++)
        for (int j = 0; j<n; j++)
        {
            if(i==j) continue;

            haf=(W[i][j]+W[j][i])/2;

            A[i][j] = A[j][i] = haf;

            B[i][j] = W[i][j] - A[i][j];
            B[j][i] = -B[i][j];
        }

    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<n; j++)
        {
            printf("%.8lf", A[i][j]);
            if(j!=n-1)  printf(" ");
        }
        puts("");
    }

    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<n; j++)
        {
            printf("%.8lf", B[i][j]);
            if(j!=n-1)  printf(" ");
        }
        puts("");
    }

    return 0;
}
