#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <algorithm>
#include <bitset>

using namespace std;

#define inf 1e9
#define pb push_back
#define pp pop_back
#define clr(y,z) memset(y, z, sizeof(y))
#define mpp make_pair
#define BE(a) a.begin(),a.end()
#define ll long long
#define sz 10005

int in[sz];
ll n;
map<int,int>mp;
vector<pair<int,int> >s;


int main()
{
    int u, v, m, cas=1;
    int root, wrong;


    while(~scanf("%d %d", &u, &v))
    {
        if(u==-1&&v==-1) break;
        else if(u==0&&v==0) {printf("Case %d is a tree.\n", cas++);continue;}
        clr(in,0);
        n=0;
        mp.clear();
        s.clear();
        while(1)
        {
            if(u==0&&v==0) break;
            if(mp.find(u)==mp.end())
            {
                mp[u]=n++;
            }
            u = mp[u];
            if(mp.find(v)==mp.end())
            {
                mp[v]=n++;
            }
            v = mp[v];
            s.pb(mpp(u,v));
            scanf("%d %d", &u, &v);
        }
        root = 0;
        wrong = false;
        if(s.size()!=(n-1)) wrong = true;


        for (vector<pair<int,int> >::iterator i = s.begin(); i!=s.end(); i++)
        {
            in[ (*i).second ]++;
        }

        for (int i = 0; i<n; i++)
        {
            if(in[i]==0) root++;
            else if(in[i]>1)
            {
                wrong = true;
                break;
            }
        }
        if(root!=1) wrong = true;
        if(wrong)printf("Case %d is not a tree.\n", cas++);
        else printf("Case %d is a tree.\n", cas++);
    }



    return 0;
}
