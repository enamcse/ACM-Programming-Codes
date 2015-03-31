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

char line[sz];



int main()
{
    #ifdef ENAM
    	fread;
	fwrite;
    #endif // ENAM
    int t, n, m, cas=1;
    bool flag = true;
    scanf("%s", line);

    m = n = strlen(line);
    if(n^1) {n>>=1;n++;}
    else n>>=1;
    if(m==1)
    {
        int i = 0;
        if((line[i]>='B'&&line[i]<='G') || (line[i]>='J'&&line[i]<='L') || (line[i]>='P'&&line[i]<='S') || line[i]=='N'||line[i]=='Z')

            flag = false;

        else if((line[i]>='a'&&line[i]<='h') || (line[i]>='j'&&line[i]<='k') || (line[i]>='m'&&line[i]<='n')|| (line[i]>='p'&&line[i]<='u') || line[i]=='y'||line[i]=='z')
            flag = false;

    }
    else
    for (int i = 0; i<n; i++)
    {
        if(line[i]!=line[m-i-1])
        {
            flag = false;
            break;
        }
        if((line[i]>='B'&&line[i]<='G') || (line[i]>='J'&&line[i]<='L') || (line[i]>='P'&&line[i]<='S') || line[i]=='N'||line[i]=='Z')
        {
            flag = false;
            break;
        }
        else if((line[i]>='a'&&line[i]<='h') || (line[i]>='j'&&line[i]<='k') || (line[i]>='m'&&line[i]<='n')|| (line[i]>='p'&&line[i]<='u') || line[i]=='y'||line[i]=='z')
        {
            flag = false;
            break;
        }
    }

    if(flag) printf("YES");
    else printf("NO");

    return 0;
}
