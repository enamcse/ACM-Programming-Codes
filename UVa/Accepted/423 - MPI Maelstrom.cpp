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

#define sz 100
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<28-1)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
using namespace std;

int mat[sz][sz];

int main()
{
    int n, mn;
    char line[sz];
    scanf("%d", &n);
    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<i; j++)
        {
            scanf("%s", line);
            if(line[0]=='x') mat[i][j]=mat[j][i]=inf;
            else
            {
                sscanf(line,"%d", &mat[i][j]);
                mat[j][i]=mat[i][j];
            }
        }
    }
    //Floyed-Warshall
    for (int k = 0; k<n; k++)
        for (int i = 0; i<n; i++)
            for (int j = 0; j<n; j++)
                mat[i][j]=min(mat[i][j], mat[i][k]+mat[k][j]);
    mn = 0;
    for (int i=0; i<n; i++)
        mn=max(mn,mat[0][i]);
    printf("%d\n", mn);
	return 0;
}
