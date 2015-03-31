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
#define pp() pop_back()
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

int main()
{
    int n,t,cas=1,x,p,q,r;
    int cand[sz][sz],comp[sz][sz];
    stack<int>qq;
    int conn[sz];
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);

        for (int i = n-1; i>=0; i--)
        {
            qq.push(i);
            conn[i]=-1;
        }

        for (int i = 0; i<n; i++)
        {
            for (int j = 0; j<n; j++)
            {
                scanf("%d", &cand[i][j]);
                cand[i][j]-=(n+1);
            }
        }

        for (int i = 0; i<n; i++)
        {
            for (int j = 0; j<n; j++)
            {
                scanf("%d", &comp[i][j]);
                comp[i][j]--;
            }
        }

        while(!qq.empty())
        {
            x = qq.top();
            qq.pop();
            int k = 0;
            while(cand[x][k]==-1) k++;
            p = cand[x][k];
//            cout<<x<<" "<<k<<" "<<p<<" "<<qq.size()<<endl;
//            getchar();
            if(conn[p]==-1) conn[p] = x;
            else
            {
                for (int i = 0; i<n; i++)
                    if(comp[p][i]==conn[p])
                    {
                        q = i;
                        break;
                    }
                for (int i = 0; i<n; i++)
                    if(comp[p][i]==x)
                    {
                        r = i;
                        break;
                    }

                if(r<q)
                {
                    qq.push(conn[p]);
                    conn[p] = x;
                }
                else qq.push(x);
            }
            cand[x][k]=-1;
        }

        printf("Case %d:",cas++);
        for (int i = 0; i<n; i++) printf(" (%d %d)", conn[i]+1,n+i+1);
        printf("\n");
    }

	return 0;
}
/*
1
3
4 5 6
4 5 6
4 5 6
1 2 3
1 2 3
1 2 3
*/
