#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <string>
#include <string.h>

using namespace std;

#define clr(y,z) memset(y,z, sizeof(y))
#define cntbit(mask) _builtin_popcount(mask)
#define fs first
#define sc second
#define pb push_back
#define pp pop_back

char line[100];
string a,b,  k, pp;
bool flag;
int n,mult;

bool next_number()
{
    k = pp;
    int carry=0, now;
    for (int i = n - 1; i>=0; i--)
    {
        now = (pp[i]-'0')*mult+carry;
        k[i] = (now%10+'0');
        if(now/10) carry=now/10;
        else carry = 0;
    }
    b = k;

    return carry?1:0;
}

int actual[10];

bool match()
{
    int ind[10];

    for (int i = 0; i<10; i++)
            ind[ i ]=0;

    for (int i = 0; i<n; i++)
    {
        ind[ b[i] - '0' ]++;
    }

    for (int i = 0; i<10; i++)
    {
        if(ind[i]!=actual[i]) return false;
    }
    return true;
}

int main()
{
#ifdef ENAM
//        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
#endif


    while(~scanf("%s", line))
    {
        pp=b = a = line;
        a = a+a;
        flag = true;
        n = strlen(line);
        mult = 2;

        for (int i = 0; i<10; i++)
            actual[ i ]=0;
        for (int i = 0; i<n; i++)
            actual[ line[i] - '0' ]++;

        for (int i = 1; i<n; i++)
        {
//            cout<<mult<<": "<<b<<endl;
            if(next_number()) {flag = false;break;}
//            cout<<a<<":: "<<b<<endl;
            if(!match()) {flag = false;break;}
            mult++;
//            cout<<mult<<"::: "<<b<<endl;
        }
        if(flag) printf("%s is cyclic\n", line);
        else printf("%s is not cyclic\n", line);
    }
    return 0;
}
