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

#define sz 100055
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

int values[sz], stree[(int)(sz*3.5)],now;


struct querys
{
    int start, ends, val;
    querys() {}
    querys(int a, int b)
    {
        start = a;
        ends = b;
    }
};

struct work
{
    int pos, mark, it;
    work() {}
    work(int a, int b, int c)
    {
        pos = a;
        mark = b;
        it = c;
    }
};

querys qq[sz/2];

vector<work>v;

void update(int ind, int LB, int UB, int P,int val)
{
    if(UB==LB)
    {
        stree[ind] = val;
        return;
    }
    int mid = ((LB+UB)>>1), m = (ind<<1);
    if(P<=mid) update(m, LB,mid, P,val);
    else update(m+1, mid+1, UB, P,val);
    stree[ind] = stree[m] + stree[m+1];
    return;
}

int query(int ind, int LB, int UB, int P, int Q)
{
    if(LB>Q||UB<P) return 0;
    if(LB>=P&&UB<=Q) return stree[ind];
    ll mid = ((UB+LB)>>1);
    return (query((ind<<1), LB, mid, P, Q)+query((ind<<1)+1,mid+1, UB, P,Q));
}

map<int, int>mps;

bool comp(work a, work b)
{
    if(a.pos==b.pos)return a.mark<b.mark;
    else return a.pos<b.pos;
}

int main()
{
    int t, n, q, cas=1, total;
    scanf("%d", &t);

    while(t--)
    {
        v.clear();
        mps.clear();
        clr(stree,0);
        now = 1;
        scanf("%d %d", &n, &q);
        for (int i = 0; i<n; i++)
            scanf("%d", &values[i]),v.pb(work(i+1,0,-1));

        for (int i = 0; i<q; i++)
            scanf("%d %d", &qq[i].start,&qq[i].ends), v.pb(work(qq[i].ends,1,i));

        total = q+n;
        sort(v.begin(), v.end(), comp);

        for (int i = 0; i<v.size(); i++)
        {

            if(v[i].mark)
                qq[ v[i].it ].val = query(1,1,total,qq[ v[i].it ].start ,qq[ v[i].it ].ends );
            else
            {
                if(mps[ values[ v[i].pos - 1 ] ]) update(1,1,total,mps[ values[ v[i].pos - 1 ] ],0);
                mps[ values[ v[i].pos - 1 ] ]=now;
                update(1,1,total,now,1);
                now++;
            }
        }
        printf("Case %d:\n",cas++);
        for (int i = 0; i<q; i++)
            printf("%d\n",qq[i].val);
    }
    return 0;
}
/*
1

8 5
1 1 1 2 3 5 1 2
1 8
2 3
3 6
4 5
4 8
*/
