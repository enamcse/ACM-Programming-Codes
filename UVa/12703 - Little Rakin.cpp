/**
* H:\Dropbox\Code\UVa\12703 - Little Rakin.cpp
* Created on: 2015-01-25-19.19.01, Sunday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <vector>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define all(v) v.begin(),v.end()
#define clr(y,z) memset(y,z,sizeof(y))
#define inf (1e9)
#define mod 1000000007
#define ll long long
#define pb push_back
#define SZ(a) ((int)a.size())
#define sqr(a) ((a)*(a))
#define sz 1205
#define fread freopen("input.txt","r", stdin)
#define fwrite freopen("output.txt","w", stdout)

using namespace std;

bool siv[sz+5];
int cnt, prime[sz+5];

void seive()
{
    int sq = sqrt(1205);


    for (int i = 3; i<=sq; i+=2)
        if(!siv[i])
            for (int j = i*i; j<sz; j+=i+i)
                siv[j] = true;

    prime[cnt++] = 2;

    for (int i = 3; i<sz; i+=2)
        if(!siv[i]) prime[cnt++]=i;

    return;
}
ll factor[50][200];


int main()
{
    #ifdef ENAM
//    fread
//    fwrite
    #endif // ENAM
    _
    seive();
    int t, n, a, b;
    cin>>t;

    while(t--)
    {
        cin>>n>>a>>b;

        clr(factor,0);


        for (int i = 0; prime[i]<=a; i++)
        {
            if(a%prime[i]==0)
            {
                while(a%prime[i]==0)
                {
                    factor[0][i]++;
                    a/=prime[i];
                }
            }
        }

        for (int i = 0; prime[i]<=b; i++)
        {
            if(b%prime[i]==0)
            {
                while(b%prime[i]==0)
                {
                    factor[1][i]++;
                    b/=prime[i];
                }
            }
        }

        for (int i = 0; i<n; i++)
        {
            for (int j = 0; j<cnt; j++)
            {
                if(i!=0)factor[i+1][j]+=factor[i][j];
                factor[i+2][j]+=factor[i][j];
            }

        }

        for (int i  = 0; i<cnt; i++)
            if(factor[n][i])cout<<prime[i]<<" "<<factor[n][i]<<"\n";
        cout<<"\n";
    }


    return 0;
}
