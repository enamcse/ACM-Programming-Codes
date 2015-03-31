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
#include<set>

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
#define fr(i,a,b)   for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod         mods[m-1]
using namespace std;

 int mods[4] = {10,100,1000,10000}, m;

struct matrix{
     ll x[6][6];
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
    int t,cas=1;

    int k, a, b;
    long long n, answer;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d %lld %d",&a, &b, &n, &m);
        base.x[1][1]=1;
        base.x[1][2]=1;
        base.x[2][1]=1;
        base.x[2][2]=0;
        if(n<=1)
        {
            printf("Case %d:  %lld\n",cas++,n);
            continue;
        }
        matrix ans=bigmod(base,n-1,2); //n-number of baseconditions+1
        answer = b*ans.x[1][1]+a*ans.x[1][2];
        answer%=mods[m-1];
        printf("Case %d: %lld\n",cas++,answer);
    }
    return 0;
}
