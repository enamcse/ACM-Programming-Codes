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

set< pair<int, int> > s;
vector<pair<int, int> >vv;

double dist(pair<int,int>p, pair<int,int>q )
{
    double a = p.first - q.first;
    double b = p.second - q.second;
    return sqrt(a*a+b*b);
}

double check(int i, int j, int k, int l)
{
//    cout<<i<<"::"<<j<<"::"<<k<<"::"<<l<<"::"<<endl;
    return dist(vv[i],vv[j])+dist(vv[k],vv[j])+dist(vv[k],vv[l]);
}


int main()
{
#ifdef ENAM
//    fread;
//    fwrite;
#endif // ENAM
    int t, n, m, cas=1;
    cin>>n>>m;
    pair<int,int> points[4];
    double mx= 0.0, temp;

    for (int i = 0; i<=min(1,n); i++)
        for (int  j = 0; j<=min(1,m); j++)
            s.insert(make_pair(i,j));

    for (int i = 0; i<=min(1,n); i++)
        for (int  j = m; j>= max(0,m-1); j--)
            s.insert(make_pair(i,j));

    for (int i = n; i>=max(0,n-1); i--)
        for (int  j = 0; j<=min(1,m); j++)
            s.insert(make_pair(i,j));

    for (int i = n; i>=max(0,n-1); i--)
        for (int  j = m; j>= max(0,m-1); j--)
            s.insert(make_pair(i,j));

    vector<pair<int, int> >v(s.begin(),s.end());
    vv = v;
    int len = v.size();

    for (int i = 0; i<len; i++)
    {
        for (int j=0; j<len; j++)
        {
            if(i==j)continue;
            for (int k = 0; k<len; k++)
            {
                if(i==k||j==k) continue;
                for (int l = 0; l<len; l++)
                {
                    if(i==l||j==l||k==l) continue;
                    temp =check(i,j,k,l);
                    if(temp-mx>1e-6){
                        points[0] = vv[i];
                        points[1] = vv[j];
                        points[2] = vv[k];
                        points[3] = vv[l];
                        mx = temp;
                    }
                }
            }
        }
    }
//    cout<<vv.size()<<":"<<endl;
    for (int i = 0; i<4; i++)
        cout<<points[i].first<<" "<<points[i].second<<endl;



    return 0;
}
