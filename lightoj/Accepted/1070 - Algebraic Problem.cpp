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

using namespace std;

struct matrix{
     unsigned long long x[6][6];
};
matrix base,zero;

matrix matmult(matrix &a,matrix &b,unsigned long long n)//m*n and n*r matrix  //1 based
{
    matrix ret;
    unsigned long long i,j,k;
    fr(i,1,n)
    fr(j,1,n)
    {
        ret.x[i][j]=0;
        fr(k,1,n)
            ret.x[i][j]=ret.x[i][j]+(a.x[i][k]*b.x[k][j]); //we can reduce complexity here
        ret.x[i][j];
    }
    return ret;
}

matrix bigmod(matrix b,unsigned long long p,unsigned long long n) //have to pass n
{
    matrix xx=zero;
    unsigned long long i;
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
    unsigned long long t,cas=0,p,q;
    unsigned long long n, answer;
    scanf("%llu",&t);
    while(t--)
    {
        scanf("%llu %llu %llu",&p, &q, &n);
        base.x[1][1]=p;
        base.x[1][2]=-q;
        base.x[2][1]=1LL;
        base.x[2][2]=0LL;

        if(n<=0)
        {
            printf("Case %llu: %lld\n",++cas, 2LL);
            continue;
        }
        else if (n==1)
        {
            printf("Case %llu: %llu\n",++cas, p);
            continue;
        }
        matrix ans=bigmod(base,n-1,2); //n-number of baseconditions+1
        answer = (ans.x[1][1]*p)+(ans.x[1][2]*2);
        printf("Case %llu: %llu\n",++cas, answer);
    }
    return 0;
}
