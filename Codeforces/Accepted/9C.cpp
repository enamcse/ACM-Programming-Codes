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

#define sz 55
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

int comp(string a, string b)
{
    return a<=b;
}

int main()
{
    int n=1, len, up=0;
    string input, output;
    cin>>input;
    len = input.size();
    output=input;
    for (int i = 0; i<len; i++)
        output[i]='0';
    for (int j = 0; j<len; j++)
        up|=(1<<j);
    while(n<=up)
    {
        for (int i = len-1, j = 0; i>=0; i--,j++)
        if((n&(1<<j)))output[i]='1';
        else output[i]='0';
        if(comp(output,input))n++;
        else break;
    }
    cout<<n-1<<endl;

    return 0;
}
