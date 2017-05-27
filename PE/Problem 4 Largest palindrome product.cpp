#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>
#include <cctype>
#define sz 100
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
using namespace std;

bool palindrome(char a[20])
{
    int len = strlen(a);
    for (int i = 0; i<len/2; i++)
    {
        if(a[i]!=a[len-1-i])return false;
    }
    return true;
}

int main()
{
    ll n, ma=0;
    char num[20];
    for (int i=100;i< 1000; i++)
        for (int j = 100; j<1000; j++)
        {
            n = i*j;
            itoa(n,num,10);
            if(palindrome(num)) ma = ma>n?ma:n;
        }
        cout<<ma;
    return 0;
}
