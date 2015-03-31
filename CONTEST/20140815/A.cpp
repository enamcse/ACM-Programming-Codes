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
string a,b,  k;
bool flag;
int n,mult;

bool next_number()
{
    k = b;
    int carry=0, now;
    for (int i = n - 1; i>=0; i--)
    {
        now = (b[i]-'0')*mult+carry;
        k[i] = (now%10+'0');
        if(now/10) carry=now/10;
        else carry = 0;
    }
    b = k;

    return carry?1:0;
}

bool match()
{
    int ind=n;
    for (int i = 0; i<n; i++)
    {
        if(b[0]==a[i]) {ind = i; break;}
    }


    for (int i = ind; i<ind+n; i++)
    {

        if(b[i-ind]!=a[i]) return false;
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
        b = a = line;
        a = a+a;
        flag = true;
        n = strlen(line);
        mult = 2;
        while(1)
        {
            if(next_number()) break;
            if(!match()) {flag = false;break;}
            mult++;
        }
        if(flag) printf("%s is cyclic\n", line);
        else printf("%s is not cyclic\n", line);
    }
    return 0;
}
