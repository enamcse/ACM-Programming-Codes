#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 100
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
using namespace std;

int main()
{
    _
    int n, sum=0, zero=0, five=0, x;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &x);
        if(x==5) five++;
        else zero++;
        sum+=x;
    }
    if(zero==0)
    {
        printf("-1");
    }
    else
    {
        while(sum%9!=0)
        {
            five--;
            sum-=5;
        }
        if(five==0) {printf("0");return 0;}
        while(five--)printf("5");
        while(zero--)printf("0");
    }
    return 0;
}
