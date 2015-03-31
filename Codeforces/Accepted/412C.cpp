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

#define sz 100005
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

int line[sz];
char input[sz];

int main()
{
#ifdef ENAM
    fread;
    fwrite;
#endif // ENAM
    int t, n, cas=1, len;

    scanf("%d", &n);

    for (int i = 0; i<n; i++)
    {
        scanf("%s", input);
        if(!i)len = strlen(input);
        for (int j = 0; j<len; j++)
        {
            if(input[j]!='?')
            {
                if(line[j]!=inf)
                {
                    if(line[j]!=(int)(input[j]-'a'+1) && line[j]!=0)
                    {
                        line[j] = inf;
                    }
                    else line[j]=(int)(input[j]-'a'+1);
                }
            }
        }
    }
    for (int i = 0; i<len; i++)
    {
        if(line[i]!= inf &&line[i]!=0  ) printf("%c",(char)(line[i]+'a'-1));
        else if(line[i]!= inf) printf("a");
        else printf("?");
    }

    return 0;
}
