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

#define sz 105
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

bool score[sz][sz], prob[sz], per[sz];

int main()
{
    int t, n, m, cas=1, cnt;
    bool flag;
    while(~scanf("%d %d", &n, &m) && (n||m) )
    {
        for (int i = 0; i<m; i++)
            prob[i]=false;

          for (int i = 0; i<n; i++)
            per[i]=false;

        for (int i = 0; i<n; i++)
            for (int j = 0; j<m; j++)
            {
                scanf("%d", &t);
                score[i][j] = t;
                prob[j]|=score[i][j];   ///problems
                per[i]|=score[i][j];    ///persons
            }
        ///Nobody solved all the problems.
        cnt = 1;
        for (int i = 0; i<n; i++)
        {
            flag = true;
            for (int j = 0; j<m; j++)
                if(score[i][j]==false)
                {
                    flag = false;
                    break;
                }
            if(flag)
            {
                cnt--;
                break;
            }
        }
        cnt++;


        ///There is no problem solved by everyone.
        for (int i = 0; i<m; i++)
        {
            flag = true;
            for (int j = 0; j<n; j++)
                if(score[j][i]==false)
                {
                    flag = false;
                    break;
                }
            if(flag)
            {
                cnt--;
                break;
            }
        }
        flag = true;
        ///Every problem was solved by at least one person (not necessarily the same).
        for (int i = 0; i<m; i++)
        {
            if(!prob[i])
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            cnt++;
        }
        ///Everyone solved at least one problem (not necessarily the same).
        flag = true;
        for (int i = 0; i<n; i++)
        {
            if(!per[i])
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            cnt++;
        }

        printf("%d\n", cnt);

    }

    return 0;
}
