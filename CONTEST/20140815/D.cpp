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
#define chg(a, b) a^=b^=a^=b
#define sz 100005
#define inf (1e9)
#define ll long long


int main()
{
    #ifdef ENAM
//        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif
    char a[50], b[50];
    ll sum1, sum2, temp;
    int len1, len2;
    while(~scanf(" %s", a, b))
    {
        sum1 =0;
        sum2 =0;
        if(!strcmp(a,"-1")&&!strcmp(b,"-1")) break;
        len1 = strlen(a);
//        len2 = strlen(b);

        for (int i = 0; i<len1; i++)
        {
            temp = 0;

            for (int j = 1; j<len1-i; j++)
            {
                temp+=((pow(10,j-1) * 45 ));
            }

            for (int j = '0'; j<='9'; j++)
            {
                if(j<a[i])
                {
                    sum1+=(temp+ ((pow(10,len1-i-1)* (j - '0') ) *(j - '0')));
                    cout<<j<<" :O: "<<((pow(10,len1-i-1) ) * (j - '0'))<<":"<<endl;
                }
                else
                {
                    sum1+=(a[i] - '0');
                    break;
                }
            }

        }

        cout<<temp<<" O "<<sum1<<":"<<endl;

//        for (int i = 0; i<len2; i++)
//        {
//            temp = 0;
//
//            for (int j = 1; j<len2-i; j++)
//            {
//                temp+=((pow(10,j-1) * 45 ));
//            }
//
//            for (int j = '0'; j<='9'; j++)
//            {
//                if(j<b[i])
//                {
//                    sum2+=(temp+(j - '0'));
//                }
//                else
//                {
//                    sum2+=(b[i] - '0');
//                    break;
//                }
//            }
//        }
//        cout<<sum2<<":"<<endl;
//
//
//        printf("%lld\n", sum2-sum1);
    }


    return 0;
}
