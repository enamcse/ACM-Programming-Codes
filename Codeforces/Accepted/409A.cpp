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

#define sz 100
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
using namespace std;

int main()
{
    char line1[30], line2[30];
    cin>>line1>>line2;
    int n, m, cnt1=0,cnt2=0;
    n = strlen(line1);

    for (int i = 0; i<n; i+=2)
    {
        if(line1[i]==line2[i]) ;
        else if ((line1[i]=='('&&line2[i]=='8')|| (line1[i]=='8'&&line2[i]=='[')|| (line1[i]=='['&&line2[i]=='(')) cnt1++;
        else cnt2++;
    }


    printf("%s",(cnt1==cnt2?"TIE":(cnt1>cnt2?"TEAM 1 WINS":"TEAM 2 WINS")));

    return 0;
}
