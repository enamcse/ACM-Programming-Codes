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
#define mod 4294967296
using namespace std;

struct matrix{
     ll x[sz][sz];
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
ll nCr[sz][sz];

void calc_nCr()
{
    for (int i = 0; i<51; i++)
        for (int j = 0; j<=i; j++)
            if(j==0) nCr[i][j] = 1;
            else if(j==1) nCr[i][j] = i;
            else nCr[i][j] = nCr[i-1][j]+nCr[i-1][j-1];
    return;
}

void build_base(int k)
{
    base = zero;
    base.x[1][1] = 1;

    for (int i = 2; i<=k+2; i++)
        base.x[1][i] = nCr[k][i-2];

    for (int i = 2; i<=k+2; i++)
    {
        for (int j = i; j<=k+2; j++)
        {
            base.x[i][j] = nCr[k+2-i][j-i];
        }
    }
    return;
}

int main()
{
    int t,cas=0;
    scanf("%d", &t);
    int k;
    calc_nCr();
    long long n, result;
    while(t--)
    {
        scanf("%lld %d", &n, &k);
        printf("Case %d: ",++cas);
        build_base(k);
        if(n<=1)
        {
            printf("1\n");
            continue;
        }
        matrix ans=bigmod(base,n-1,k+2); //n-number of baseconditions+1
        result=0;
        for (int i = 1; i<=k+2; i++)
        {
            result=(result+ans.x[1][i])%mod;
        }
        printf("%lld\n", result);
    }
    return 0;
}

