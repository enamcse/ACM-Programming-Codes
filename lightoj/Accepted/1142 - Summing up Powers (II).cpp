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
#define mod 10
using namespace std;

int m;

struct matrix
{
    ll x[31][31];
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

matrix matadd(matrix &a,matrix &b,int n)//m*n and n*r matrix  //1 based
{
    matrix ret;
    int i,j;
    fr(i,1,n)
    fr(j,1,n)
    {
        ret.x[i][j]=(a.x[i][j]+b.x[i][j])%mod; //we can reduce complexity here
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

matrix solve(matrix a, int po, int n)
{
    if(po==1) return a;
    //int m=po/2;
    matrix ret = solve(a,(po>>1),n);
    matrix big = bigmod(base,(po>>1),n);
    big = matmult(ret,big,n);
    ret = matadd(ret,big,n);

    if(po&1)
    {
        big = bigmod(base,po,n);
        ret = matadd(ret,big,n);
    }
    return ret;
}

int main()
{
    int t,cas=0;
    scanf("%d", &t);

    int n, m;
    while(t--)
    {
        scanf("%d %d", &n, &m);
        printf("Case %d:\n",++cas);
        int i,j;
        fr(i,1,n)
        fr(j,1,n)
        scanf("%lld", &base.x[i][j]);

        matrix ans=solve(base,m,n); //n-number of baseconditions+1

        fr(i,1,n)
        {
            fr(j,1,n)
            printf("%lld", ans.x[i][j]);
            printf("\n");
        }
    }
    return 0;
}
