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
#define mp make_pair
#define BE(a) a.begin(),a.end()
#define ll long long

struct good
{
    string name;
    ll cost;
    good() {}
    good(string line, ll b)
    {
        name = line;
        cost = b;
    }
};

bool comp(const good &a, const good &b)
{
    if(a.cost!=b.cost)return a.cost<b.cost;
    else a.name<b.name;
}

map<string,ll>g;
vector<good>res;

ll n,m, t, b,c,k, boom;
int main()
{
//    freopen("in.txt","r", stdin);

    char line[1000], input[1000];
    string s, ss;
    scanf("%lld", &t);
    ll sum;

    while(t--)
    {
        g.clear();
        res.clear();
        gets(line);
        gets(line);
//        cout<<"@ "<<line<<endl;
        scanf("%lld %lld %lld", &m,&n,&b);
        for (int i = 0; i<m; i++)
        {
            scanf("%s %lld", input, &c);
            s = input;
            g[s] = c;
        }

        for (int i = 0; i<n; i++)
        {
//            cout<<i<< " L : "<<k<<endl;
            sum = 0;
            gets(input);
            gets(input);
            ss = input;
            scanf("%lld ", &k);
//            cout<<i<< " R : "<<k<<endl;
            for (int j = 0; j<k; j++)
            {

                scanf(" %s %lld", input, &c);
                s = input;
                sum+=( g[s]*c );
//                cout<<j<< " Rin : "<<input<<" "<<k<<endl;
            }
//            cout<<"s "<<sum<<" "<<b<<endl;
            if(sum<=b)
            {
                res.pb(good(ss,sum));
            }
        }
        boom = strlen(line);
        for (int i = 0; i<boom; i++)
        {
            printf("%c", toupper(line[i]));
        }
        puts("");

        if(res.size()!=0)
        {
            sort(res.begin(), res.end(), comp);
            boom = res.size();
            for (int i = 0; i<boom; i++)
                printf("%s\n", res[i].name.c_str());
        }
        else printf("Too expensive!\n");

        puts("");
    }



    return 0;
}
