#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <map>
#include <list>
#include<set>
#define sz 100
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
using namespace std;

int main()
{
    ll t, caseno=1, x, y, n, w,cnt,pos,mins;
    set<ll>s;
    scanf("%lld", &t);

    while(t--)
    {
        scanf("%lld %lld", &n, &w);
        s.clear();
        for (int i = 0; i<n; i++)
        {
            scanf("%lld %lld", &x, &y);
            s.insert(y);
        }

        set<ll>::iterator it;
        it = s.begin();
        y = *it;
        pos = y;
        if(s.size()==1)
        {
            printf("Case %lld: 1\n", caseno++);
            continue;
        }
        for (it++, cnt=1; it!= s.end(); it++)
        {
            if(*it == y) continue;
            x = y;
            y = *it;
//            cout<<" "<<x<<" "<<y<<endl;
            it++;
            x = y - x;
//            x=x<0?-x:x;
//            cout<<"size = "<<x-(w+pos)<<endl;
            if(x>(w+pos))
            {
                pos=y;
                cnt++;
            }
        }
        mins= cnt;
        it = s.end();
        y = *it;
        pos = y;
        for (it--, cnt=1; it!= s.begin(); it--)
        {
            if(*it == y) continue;
            x = y;
            y = *it;
//            cout<<" "<<x<<" "<<y<<endl;
            it++;
            x = y - x;
//            x=x<0?-x:x;
//            cout<<"size = "<<x-(w+pos)<<endl;
            if(x<(pos-w))
            {
                pos=y;
                cnt++;
            }
        }
        mins = mins<cnt?mins:cnt;
        printf("Case %lld: %lld\n", caseno++, mins);
    }
    return 0;
}
