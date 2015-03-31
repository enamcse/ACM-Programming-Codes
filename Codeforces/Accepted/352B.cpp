#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

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

set<int>s;
map<int, vector<int> >m;
vector<int>series;
int main()
{
    _
    int n, x,valid=0, d,diff;
    scanf("%d", &n);
    for (int i = 0; i<n; i++)
    {
        scanf("%d", &x);
        s.insert(x);
        m[x].pb(i+1);
    }
    set<int>::iterator it;
    for (it=s.begin(); it!=s.end(); it++)
    {
        x = m[*it].size();
        if(x==1)
        {
            series.pb(*it);
            series.pb(0);
            valid++;
        }
        else if(x==2)
        {
            series.pb(*it);
            series.pb(m[*it][1]-m[*it][0]);
            valid++;
        }
        else
        {
            diff = m[*it][1]-m[*it][0];
            bool flag = true;
            for (int i =2; i<x; i++)
            {
                d = m[*it][i]-m[*it][i-1];
                if(d!=diff)
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                series.pb(*it);
                series.pb(diff);
                valid++;
            }
        }
    }
    printf("%d\n", valid);
    x=0;
    for (int i = 0; i<valid; i++,x+=2)
    {
        printf("%d %d\n", series[x], series[x+1]);
    }
    return 0;
}
