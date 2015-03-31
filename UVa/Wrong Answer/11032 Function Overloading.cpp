#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

long long fun(long long a, long long b);
long long fun(long long a);
long long sod(long long i);

int main()
{
    long long t,caseno=1, a, b;
    char input;

    cin>>t;
    while(t--)
    {
        cin>>a;
        input = getchar();
        if(input==' ')
        {
            cin>>b;
            cout<<"Case "<<caseno++<<": "<<fun(a,b)<<endl;
        }
        else
        {
            cout<<"Case "<<caseno++<<": "<<fun(a)<<endl;
        }
    }
    return 0;
}


long long fun(long long a, long long b)
{
    long long ans = 0;
    long long i, j, cnt;
    for(i=a; i<=b; i++)
    {
        cnt = 0;
        for(j=1; j<=i; j++)
        {
            if( j + sod(j) == i ) cnt++;
        }
        if( cnt == 0 ) ans++;
    }
    return ans;
}

long long fun(long long a)
{
    long long i;
    for(i=1; i<=a; i++)
    {
        if( i + sod(i) == a )
        {
            return i;
        }
    }
    return -1;
}

long long sod(long long i)
{
    long long remain, sum;
    sum = 0;
    remain = i;
    while(remain)
    {
        sum += remain%10;
        remain/=10;
    }
    return sum;
}
