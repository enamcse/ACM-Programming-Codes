/**
* H:\Dropbox\Code\SPOJ\21360. Suffix Equal Prefix(SUFEQPRE).cpp
*
* Created on: 2014-10-18-00.38.36, Saturday
* Author: Enamul Hassan
* Verdict: NOT SOLVED
**/

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

#define sz 1000005
#define pb(a) push_back(a)
#define pp pop_back()
#define all(a) a.begin(),a.end()
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
int LPS[sz];
char pat[sz];
int plen, slen, res;

void computeLPSArray()
{
    int i, len;
    LPS[0] = len = 0;
    i = 1;
    while(i<plen)
    {
        if(pat[i]==pat[len])
        {
            len++;
            LPS[i] = len;
//            res++;
            i++;
        }
        else
        {
            if(len!=0)
            {
                len = LPS[len-1];
            }
            else
            {
                LPS[i] = 0;
                i++;
            }
        }
    }
//    for (int i = 0; i<plen; i++)
//        printf("%d ", LPS[i]);
//        puts("");

    for (int i = plen-1; LPS[i]; i=LPS[i]-1)
        res++;
}



int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1;
    char line[sz];
    scanf("%d", &t);

    while(t--)
    {
        res=0;
        scanf("%s", pat);
        plen = strlen(pat);
//        reverse(all(pat));
        computeLPSArray();
        printf("Case %d: %d\n",cas++, res);
    }


    return 0;
}
