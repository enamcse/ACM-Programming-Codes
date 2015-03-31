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

int sq[sz];

map<int,int>mps;

int main()
{
    int t, n, m, cas=1,x,y,px,py,temp, xx,yy, f_i=0, f_j, otivuj,s_i=0, s_j;

    for (int i = 1; i<sz; i++)
    {
        sq[i]=i*i;
        mps[sq[i]]=i;
    }

    cin>>x>>y;
    px = x*x;
    py = y*y;

    otivuj = px + py;
    if(x==y)
    {
        for (int i = 1; px>sq[i]; i++)
        {
            xx = px - sq[i];
            if(xx == sq[i]) continue;
            if(mps[xx])
            {
                f_i = i;
                f_j = mps[xx];
                break;
            }
        }

        if(f_i!=0)
        {

            cout<<"YES"<<endl;
            cout<<"0 0"<<endl;
            cout<<f_i<<" "<<f_j<<endl;
            cout<<-f_j<<" "<<f_i<<endl;
        }
        else cout<<"NO"<<endl;
    }
    else
    {
        for (int i = 1; px>sq[i]; i++)
        {
            xx = px - sq[i];
            if(xx == sq[i]) continue;
            if(mps[xx])
            {
                f_i = i;
                f_j = mps[xx];
                for (int j = 1; py>sq[j]; j++)
                {
                    yy = py - sq[j];

                    if(yy == sq[j]) continue;
                    if(mps[yy])
                    {
                        s_j = mps[yy];
//                        cout<<f_i<<" "<<f_j<<" : "<<j<<" "<<s_j<<" "<<otivuj<<" "<<((f_i+j)*(f_i+j)+(f_j-s_j)*(f_j-s_j)) <<endl;

                        if(f_j==s_j) continue;
                        if(((f_i+j)*(f_i+j)+(f_j-s_j)*(f_j-s_j))!=otivuj) continue;
                        s_i = -j;
                        break;
                    }
                }
                if(s_i!=0)break;
            }
        }

        if(s_i!=0)
        {
            cout<<"YES"<<endl;
            cout<<"0 0"<<endl;
            cout<<f_i<<" "<<f_j<<endl;
            cout<<s_i<<" "<<s_j<<endl;
        }
        else cout<<"NO"<<endl;
    }

    return 0;
}
