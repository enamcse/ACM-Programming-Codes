#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>
#include <cctype>
#include <map>
#include <list>
#include<set>

#define sz 10000
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define inf (1<<30-1)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
using namespace std;

int main()
{
    int t, x,y, len, carry, sum,i;
    char a[sz],b[sz];
    bool flag;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s %s", a, b);
        x = strlen(a);
        y = strlen(b);
        len = x<y?x:y;
        carry = 0;
        flag = false;
        for (i = 0; i<len; i++)
        {
            sum = (a[i]+b[i]-'0'-'0')+carry;
            if(sum>9)
            {
                carry = 1;
                sum%=10;
            }
            else carry = 0;
            if(sum>0) flag = true;
            if(flag) printf("%c", (char)(sum+'0'));
        }
        if(x>y)
        {
            while(carry&&i<x)
            {
                sum = (a[i++]-'0')+carry;
                if(sum>9)
                {
                    carry = 1;
                    sum%=10;
                }
                else carry = 0;
                if(sum>0) flag = true;
                if(flag)printf("%c", (char)(sum+'0'));
            }
            if(carry) printf("%c", '1');
                else while(i<x)
                {
                    if(a[i]>'0') flag = true;
                        if(flag)printf("%c", a[i++]);
                    }
        }
        else if (y>x)
        {
            while(carry&&i<y)
            {
                sum = (b[i++]-'0')+carry;
                if(sum>9)
                {
                    carry = 1;
                    sum%=10;
                }
                else carry = 0;
                if(sum>0) flag = true;
                if(flag)printf("%c", (char)(sum+'0'));
            }
            if(carry) printf("%c", (char)(sum+'1'));
            else while(i<y)
                {
                    if(b[i]>'0') flag = true;
                    if(flag)printf("%c", b[i++]);
                }
        }
        else if(carry) printf("%c", '1');
        printf("%c", '\n');
    }
    return 0;
}
