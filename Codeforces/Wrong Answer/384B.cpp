//Wrong Answer
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


struct data
{
    int x,y;
    data() {};
    data(int a, int b)
    {
        x = a;
        y = b;
    }
};

bool comp(data a,data b)
{
    return a.x<b.x;
}
bool comp2(data a,data b)
{
    return a.x>b.x;
}

int main()
{
    int n,m,x,dd;

    vector<data>v[1000];

    scanf("%d %d %d", &n, &m, &dd);
    if(dd)
    {
        for (int i = 0; i<n; i++)
        {
            for (int j = 0,k=m-1; j<m; j++,k--)
            {
                scanf("%d", &x);
                v[i].pb(data(x,k));
            }
            sort(v[i].begin(),v[i].end(),comp2);


//            for (int j = 0; j<m; j++)
//            {
//                printf("(%d %d) ", v[i][j].x, v[i][j].y);
//            }
//            cout<<endl;
        }

        data temp;
        set< pair<int,int> >s;
        for (int i = 0; i<n; i++)
        {
            for (int j = 0,z = m-1,k; j<m; j++,z--)
            {
//                cout<<j<<" "<<z<<": ";
                if(v[i][j].y!=z)
                {
//                    cout<<i<<" "<<j<<" "<<z<<":: ";
                    for (k = j+1; k<m; k++)
                        if(v[i][k].y==z) break;
                    temp = v[i][j];
                    v[i][j] = v[i][k];
                    v[i][k] = temp;
//                    cout<<k<<"::: ";
                    s.insert(make_pair(k+1,j+1));
                }
//                cout<<endl;
            }
//            cout<<endl;
        }
        x = s.size();
        printf("%d\n",x);
        pair<int,int>p;
        for (set< pair<int,int> > :: iterator it = s.begin(); it!=s.end(); it++)
        {
            p = *it;
            printf("%d %d\n",p.first,p.second);
        }
        return 0;
    }
    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<m; j++)
        {
            scanf("%d", &x);
            v[i].pb(data(x,j));
        }
        sort(v[i].begin(),v[i].end(),comp);
    }
    data temp;
    set< pair<int,int> >s;
    for (int i = 0; i<n; i++)
    {
        for (int j = 0,k; j<m; j++)
        {
            if(v[i][j].y!=j)
            {
                for (k = j+1; k<m; k++)
                    if(v[i][k].y==j) break;
                temp = v[i][j];
                v[i][j] = v[i][k];
                v[i][k] = temp;
                s.insert(make_pair(k+1,j+1));
            }
        }
    }
    x = s.size();
    printf("%d\n",x);
    pair<int,int>p;
    for (set< pair<int,int> > :: iterator it = s.begin(); it!=s.end(); it++)
    {
        p = *it;
        printf("%d %d\n",p.second,p.first);
    }


    return 0;
}









