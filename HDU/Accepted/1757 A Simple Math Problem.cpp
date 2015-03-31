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

#define sz 100
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
#define mod m
using namespace std;

ll m;

struct matrix{
     ll x[12][12];
};
matrix base,zero;

matrix matmult(matrix &a,matrix &b,int n)//m*n and n*r matrix  //1 based
{
    matrix ret;
    int i,j,k;
    fr(i,1,n)
    fr(j,1,n)
    {
        ret.x[i][j]=0;
        fr(k,1,n)
            ret.x[i][j]=ret.x[i][j]+(a.x[i][k]*b.x[k][j])%mod; //we can reduce complexity here
        ret.x[i][j]%=mod;
    }
    return ret;
}

matrix bigmod(matrix b,long long p,int n) //have to pass n
{
    matrix xx=zero;
    int i;
    fr(i,1,n)  xx.x[i][i]=1;
    matrix power=b;
    while(p)
    {
        if((p&1)==1) xx=matmult(xx,power,n);
        power=matmult(power,power,n);
        p/=2;
    }
    return xx;
}


int main()
{
    long long n,answer;
    ll a[10];

    while(scanf("%I64d %I64d", &n, &m)==2)
    {

        for (int i = 1; i<=10; i++)
            for (int j = 1; j<=10; j++)
                base.x[i][j]=0;

        for (int i = 1; i<=10; i++)
        {
            scanf("%I64d", &a[i-1]);
            base.x[1][i] = a[i-1];
        }

        for (int i = 2; i<=10; i++)
            base.x[i][i-1] = 1;

        if(n<10)
        {
            printf("%I64d\n",n);
            continue;
        }
        matrix ans=bigmod(base,n-9,10); //n-number of baseconditions+1
        answer=0;
        for (int i =1; i<=10; i++)
        {
            answer+=(((10-i) * ans.x[1][i])%m);
            answer%=m;
        }

        printf("%I64d\n",(answer%m));
    }
    return 0;
}
