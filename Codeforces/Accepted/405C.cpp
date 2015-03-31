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

#define sz 1055
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

int board[sz][sz];

int main()
{
    int t, n, m, cas=1,q, res=0;
    string s="";

    scanf("%d", &n);

    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<n; j++)
        {
            scanf("%d", &board[i][j]);
            if(i==j) res+=board[i][i];
        }
    }

    scanf("%d", &q);

    for (int i = 0; i<q; i++)
    {
        scanf("%d", &m);
        if(m==1||m==2)
        {
            scanf("%d", &m);
            m--;
            if(board[m][m])
            {
                board[m][m]=0;
                res--;
            }
            else
            {
                board[m][m]=1;
                res++;
            }
        }
        else
        {
            if((res&1)) s+="1";
            else s+="0";
        }
    }

    printf("%s", s.c_str());


    return 0;
}
