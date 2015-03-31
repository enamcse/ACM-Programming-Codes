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
#include <stack>

#define sz 1050
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
using namespace std;

int main()
{
    int arr[sz],n, fr=0,en, fs, sn;
    bool flag = false;
    scanf("%d", &n);
    for (int i = 0; i<n; i++)
        scanf("%d", &arr[i]);
    fs=sn=0;
    en = n-1;
    while(fr!=en)
    {
        if(flag)
        {
            if(arr[fr]>arr[en])
                fs+=arr[fr++];
            else fs+=arr[en--];
            flag^=1;
        }
        else
        {
            if(arr[fr]>arr[en])
                sn+=arr[fr++];
            else sn+=arr[en--];
            flag^=1;
        }
    }
    if(flag)
    {
        if(arr[fr]>arr[en])
            fs+=arr[fr++];
        else fs+=arr[en--];
        flag^=1;
    }
    else
    {
        if(arr[fr]>arr[en])
            sn+=arr[fr++];
        else sn+=arr[en--];
        flag^=1;
    }
    printf("%d %d", sn,fs);
    return 0;
}
