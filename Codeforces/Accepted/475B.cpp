//Verdict: SOLVED
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

#define sz 100005
#define pb(a) push_back(a)
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e9)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define fr(i,a,b) for(i=a;i<=b;i++)
#define mod 1000000007
#define sf scanf
#define pf printf
using namespace std;

int rr[] ={0,0,1,-1};
int cc[] = {1,-1,0,0};

char line1[100], line2[100];
int t, n, m, cas=1;
int col[200][200];

void dfs(int a, int b)
{
    if(a<0||b<0||a>=n||b>=m||col[a][b]!=-1) return;
    col[a][b]=1;
    if(line1[a]=='>') dfs(a,b+1);
    else dfs(a,b-1);
    if(line2[b]=='v') dfs(a+1,b);
    else dfs(a-1,b);
    return;
}

bool check()
{
    for (int i = 0; i<n; i++)
        for (int j = 0; j<m; j++)
            if(col[i][j]==-1) return true;
        return false;
}

int main()
{
    #ifdef ENAM
//        fread;
//    fwrite;
    #endif // ENAM

    bool flag = true;
    cin>>n>>m>>line1>>line2;

    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<m; j++)
        {
            clr(col,-1);
            dfs(i,j);
            if(check())
            {
                flag = false;
                break;
            }

        }
        if(!flag) break;
    }

    if(flag) cout<<"YES";
    else cout<<"NO";


    return 0;
}
