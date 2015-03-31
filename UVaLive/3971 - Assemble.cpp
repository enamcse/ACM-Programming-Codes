#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <string>
#include <string.h>

using namespace std;

#define clr(y,z) memset(y,z, sizeof(y))
#define cntbit(mask) _builtin_popcount(mask)
#define fs first
#define sc second
#define pb push_back
#define pp pop_back
#define chg(a, b) a^=b^=a^=b
#define sz 1005
#define inf (1e9)
#define ll long long

struct prod{
    int type, name, price, quality;
    prod(){}
    prod(int a, int b, int c, int d)
    {
        type = a;
        name = b;
        price = c;
        quality = d;
    }
};

int c1,c2;
map<string,int>tt,nn;

int flag[sz];
int qual[sz];

vector<prod>v;


bool compPrice(prod const &a, prod const &b)
{
    return a.price<b.price;
}

bool compType(prod const &a, prod const &b)
{
    if(a.type==b.type)a.price==b.price;
    return a.type<b.type;
}

bool compQuality(prod const &a, prod const &b)
{
    return a.quality<b.quality;
}

set<int>lev;

int main()
{
    #ifdef ENAM
//        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif
    int t, n,m, w, z,x, y, est,q;
    string s1,s2;
    char line1[1000],line2[1000];
    scanf("%d", &t);

    while(t--)
    {
        clr(flag,-1);
        est=c1=c2=0;
        v.clear();
        tt.clear();
        nn.clear();
        lev.clear();
        q=inf;
        scanf("%d %d", &n, &m );
        for (int i = 0; i<n; i++)
        {
            scanf("%s %s %d %d", line1, line2, &x, &y);
            s1 = line1;
            s2 = line2;
            if(tt.find(s1)==tt.end()) tt[s1]=c1++;
            w = tt[s1];
            if(nn.find(s2)==nn.end()) nn[s2]=c2++;
            z = nn[s2];
            v.pb(prod(w,z,x,y));
            lev.insert(y);
        }
        vector<int>levels(lev.begin(), lev.end());

        int kkk = levels.size(), j;
        bool flags;
        for (j = 0; j<kkk; j++)
        {
            clr(flag,-1);
            flags = false;
            for (int i = 0; i<n; i++)
            {
                if(v[i].quality>=levels[j])
                {
                    if( flag[ v[i].type ] == -1) flag[ v[i].type ] = v[i].price;
                    else if (v[i].price<flag[ v[i].type ]) flag[ v[i].type ] = v[i].price;
                }
            }
            ll nows=0;
            for (int i = 0; i<c1; i++)
            	if(flag[i]==-1) { flags = true;break;}
            	else nows+= flag[i];

            if(flags||nows>m) break;
        }

        int mn = inf;

        printf("%d\n", levels[j-1]);


    }


    return 0;
}
