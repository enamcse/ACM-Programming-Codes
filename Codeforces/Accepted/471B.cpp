//Verdict: AC after contest
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

vector< pair<int,int> >v;



vector<int>p,pp,ppp;


int main()
{
#ifdef ENAM
//        fread;
//    fwrite;
#endif // ENAM
    int n, m, tw=0, cnt=1;

    scanf("%d", &n);

    for (int i = 0; i<n; i++)
    {
        scanf("%d", &m);
        v.pb(make_pair(m,i+1));
    }

    sort(v.begin(), v.end());

    bool flag = false;
    vector<int>now;
    now.pb(v[0].second);
    cnt = 1;
    for (int i = 1; i<n; i++)
    {
        if(v[i].first==v[i-1].first && i != n -1)
            cnt++,now.pb(v[i].second);
        else
        {
            if(i==n-1)
            {
                if(v[i].first==v[i-1].first) cnt++,now.pb(v[i].second);
                else flag = true;
            }

            if(cnt>2)
            {
                for (int j = 0; j<now.size(); j++) p.pb(now[j]);
                next_permutation(now.begin(), now.end());
                for (int j = 0; j<now.size(); j++) pp.pb(now[j]);
                next_permutation(now.begin(), now.end());
                for (int j = 0; j<now.size(); j++) ppp.pb(now[j]);
                tw = 2;
            }
            else if(cnt == 2 && !tw)
            {
                for (int j = 0; j<now.size(); j++) p.pb(now[j]);
                next_permutation(now.begin(), now.end());
                for (int j = 0; j<now.size(); j++)pp.pb(now[j]);
                next_permutation(now.begin(), now.end());
                for (int j = 0; j<now.size(); j++) ppp.pb(now[j]);
                tw++;
            }
            else if(cnt == 2)
            {
                for (int j = 0; j<now.size(); j++) pp.pb(now[j]);
                next_permutation(now.begin(), now.end());
                for (int j = 0; j<now.size(); j++) ppp.pb(now[j]);
                next_permutation(now.begin(), now.end());
                for (int j = 0; j<now.size(); j++) p.pb(now[j]);
                tw++;
            }
            else
            {
                p.pb(now[0]);
                pp.pb(now[0]);
                ppp.pb(now[0]);
            }

            if(flag)
            {
                p.pb(v[i].second);
                pp.pb(v[i].second);
                ppp.pb(v[i].second);
            }
            now.clear();
            now.pb(v[i].second);
            cnt=1;
        }
    }
    if(tw>=2)
    {
        puts("YES");
        for (int i = 0; i<n; i++)
            if(i) printf(" %d", p[i]);
            else printf("%d", p[i]);
        puts("");
        for (int i = 0; i<n; i++)
            if(i) printf(" %d", pp[i]);
            else printf("%d", pp[i]);
        puts("");
        for (int i = 0; i<n; i++)
            if(i) printf(" %d", ppp[i]);
            else printf("%d", ppp[i]);
        puts("");
    }
    else puts("NO");
    return 0;
}
