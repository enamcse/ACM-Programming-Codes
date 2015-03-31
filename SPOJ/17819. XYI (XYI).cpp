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

#define sz 600
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
using namespace std;

vector<int>v[sz];
int col[sz],cas=1;
bool dfs(int x, int par)
{
    col[x]=cas;
    bool flag = true;
    for (int i = 0; i<v[x].size(); i++)
    {
//        cout<<"now = "<<x<<", parent = "<<par<<", child = "<<v[x][i]<<", child col = "<<col[i]<<", "<<endl;
        if(v[x][i]==par) continue;
        if(col[v[x][i]]==cas) return false;

        if(!dfs(v[x][i],x)) flag = false;
    }
    return flag;
}

//map<string, int>maa;

int main()
{
    int n, m, x, y, t, num;
    string a, b;
    char ina[100], inb[100];
    scanf("%d", &t);
    clr(col,0);
    while(t--)
    {
        num=1;
        bool found = false, flag = false;
        scanf("%d %d", &n, &m);
        for (int i = 0; i<=n; i++)
            v[i].clear();
        for (int i = 0; i<m; i++)
        {
            scanf("%d %d", &x, &y);
//            scanf("%s %s", ina, inb);
//            a = ina;
//            b = inb;
//            if(maa[a]>0) x = maa[a];
//            else
//            {
//                maa[a]=num++;
//                x = maa[a];
//            }
//            if(maa[b]>0) y = maa[b];
//            else
//            {
//                maa[b]=num++;
//                y = maa[b];
//            }
            v[x].pb(y);
            v[y].pb(x);
        }
        y=1;
        for (int i = 1; i<=n; i++)
        {
            if(v[i].size()>2)
            {
                if(found) {flag = true;
                break;}
                else
                {
                    found = true;
                    x = v[i].size();
                    y = i;
                }
            }
        }
//        cout<<y<<endl;
        if(flag)
        {
            printf("Case %d: NotValid\n",cas++);
        }
        else
        {
            if(dfs(y,0))
            {
                if(!found) printf("Case %d: I\n",cas++);
                else if(x==4)printf("Case %d: X\n",cas++);
                else if(x==3) printf("Case %d: Y\n",cas++);
                else printf("Case %d: NotValid\n",cas++);
            }
            else printf("Case %d: NotValid\n",cas++);
        }
    }
    return 0;
}
