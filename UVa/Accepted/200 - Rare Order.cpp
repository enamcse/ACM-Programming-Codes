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

#define sz 1000
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
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
using namespace std;

char str[22][sz];
int used[27];

int main()
{
    int len, s=0;
    char line[sz];
    clr(str,0);
    while(~scanf("%s", line)&&strcmp(line,"#"))
    {

        len = strlen(line);
        for (int i = 0; i<len; i++)
            str[i][s]=line[i];
        s++;
    }

    for (int i = 0; i<20; i++)
    {
        for (int j=0; j<s; j++)
        {
            if(isalpha(str[i][j]))
            if(!used[str[i][j]-'A'])
            {
                used[str[i][j]-'A']++;
                printf("%c", str[i][j]);
            }
        }
    }
    puts("");

	return 0;
}
