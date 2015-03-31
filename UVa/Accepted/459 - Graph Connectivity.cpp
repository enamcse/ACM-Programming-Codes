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

#define sz 30
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
#define p_(a)    cout<<a<<endl
#define p__(a,b) cout<<a<<" "<<b<<endl
#define p___(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
using namespace std;

map<char,set<char> >m;

bool flag[sz];

void dfs(char c)
{
    flag[c-'A']=true;
    for (set<char>::iterator i=m[c].begin(); i!=m[c].end(); i++)
        if(!flag[*i-'A']) dfs(*i);
    return;
}

int main()
{
    int t;
    int cnt, a, b;
    char line[10], ch, last;
    scanf("%d%*c%*c", &t);

    while(t--)
    {
        scanf("%c%*c", &last);
        cnt = 0;
        for (char i = 'A'; i<=last; i++)
            m[i].clear();
        clr(flag,0);
        while(gets(line))
        {
            if(line[0]=='\0') break;
            a = line[0];
            b = line[1];
            m[a].insert(b);
            m[b].insert(a);
        }
        for (char i = 'A'; i<=last; i++)
        {
            if(!flag[i-'A']) cnt++;
            dfs(i);
        }

        printf("%d\n", cnt);
        if(t) puts("");
    }
	return 0;
}
