/**
* H:\Dropbox\Code\UVa\12545 - Bits Equalizer.cpp
* Created on: 2015-01-25-19.43.17, Sunday
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
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>


#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define chng(a,b) a^=b^=a^=b;
#define clr(y,z) memset(y,z,sizeof(y))
#define cntbit(mask) __builtin_popcount(mask)
#define fread freopen("input.txt", "r", stdin)
#define fread freopen("output.txt", "w", stdout)
#define inf (1e9)
#define mod 1000000007
#define ll long long
#define pb push_back

using namespace std;


int main()
{
    _
    int t, cas=1,ans, n, x, y;

    string a, b;

    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        n = a.size();
        ans=x = y = 0;

        for (int i = 0; i<n; i++)
        {
            if(a[i]!='1') x++;
            if(b[i]!='1') y++;
            if(a[i]=='?') ans++;
        }

        cout<<"Case "<<cas++<<": ";
        if(y>x)
        {
            cout<<"-1\n";
            continue;
        }

        for (int i = 0; i<n; i++)
        {
            if(a[i]=='0'&&b[i]=='1')
            {
                int j = i+1;
                for (; j<n; j++)
                    if(a[j]=='1'&&b[j]=='0')
                    {
                        break;
                    }
                if(i!=n) swap(a[i], a[j]);

                ans++;
            }
            else if(a[i]=='1'&&b[i]=='0')
            {
                int j = i+1;
                for (; j<n; j++)
                    if(a[j]=='0'&&b[j]=='1')
                    {
                        break;
                    }
                if(i!=n)
                {
                    swap(a[i], a[j]);
                    ans++;
                    continue;
                }
                j = i+1;
                for (; j<n; j++)
                    if(a[j]=='?'&&b[j]=='1')
                    {
                        break;
                    }
                swap(a[i], a[j]);
                ans++;
            }
        }
        cout<<ans<<"\n";

    }


    return 0;
}

/*
3
01??00
001010
01
10
110001
000000
*/
