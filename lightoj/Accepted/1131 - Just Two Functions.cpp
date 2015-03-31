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

struct matrix
{
    ll x[8][8];
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
    int t,cas=0;
    ll a[2][3], b[2][3],q;
    scanf("%d", &t);

    long long n, ans1, ans2;
    while(t--)
    {
        for (int i =0; i<2; i++)
            for (int j = 0; j<3; j++)
                scanf("%lld", &a[i][j]);

        for (int i =0; i<2; i++)
            for (int j = 0; j<3; j++)
                scanf("%lld", &b[i][j]);
        scanf("%lld", &m);
        scanf("%lld", &q);
        printf("Case %d:\n",++cas);

        for (int i = 1; i<=6; i++)
            for (int j = 1; j<=6; j++)
                base.x[i][j]=0;

        base.x[1][1]=a[0][0];
        base.x[1][3]=a[0][1];
        base.x[1][6]=a[0][2];
        base.x[2][2]=a[1][0];
        base.x[2][4]=a[1][1];
        base.x[2][5]=a[1][2];

        for (int i = 3; i<=6; i++)
            base.x[i][i-2]=1;

        for (ll i =0; i<q; i++)
        {
            scanf("%lld", &n);
            if(n<3)
            {
                printf("%lld %lld\n",b[0][n]%m,b[1][n]%m);
                continue;
            }
            matrix ans=bigmod(base,n-2,6); //n-number of baseconditions+1

            ans1 = ((ans.x[1][1]*b[0][2])%m+(ans.x[1][2]*b[1][2])%m+(ans.x[1][3]*b[0][1])%m+(ans.x[1][4]*b[1][1])%m+(ans.x[1][5]*b[0][0])%m+(ans.x[1][6]*b[1][0])%m)%m;
            ans2 = ((ans.x[2][1]*b[0][2])%m+(ans.x[2][2]*b[1][2])%m+(ans.x[2][3]*b[0][1])%m+(ans.x[2][4]*b[1][1])%m+(ans.x[2][5]*b[0][0])%m+(ans.x[2][6]*b[1][0])%m)%m;
            printf("%lld %lld\n", ans1, ans2);
        }

    }
    return 0;
}
