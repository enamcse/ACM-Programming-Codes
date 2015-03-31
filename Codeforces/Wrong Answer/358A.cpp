#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

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
using namespace std;

int a[1000];

int main()
{
    _
    int n, x=2,p,q,lb=-inf,ub=inf;
    bool flag = true;
    scanf("%d",&n);
    if(n<=3)
    {
        while(n--)scanf("%*d");
        printf("no");
    }
    else
    {
        for (int i = 0; i<n; i++)
            scanf("%d",&a[i]);
        if(a[0]<a[1])
        {
            lb = a[0];
            ub = a[1];
        }
        else
        {
            lb = a[1];
            ub = a[0];
        }
        while(x<n)
        {
//            if(x==n-1)
//            {
//                p = a[x];
//                if(p>=lb&&p<=ub) break;
//                else flag = false;
//                break;
//            }
//            p = a[x]>a[x+1]?a[x]:a[x+1];
//            q = a[x]>a[x+1]?a[x]:a[x+1];
            p = a[x];
            if(p>=lb&&q<=ub)
            {
                lb = p;
                ub = q;
            }
            else if(p<lb)
            {
                lb = p;

            }
//            {
//                flag = false;
//                break;
//            }
            x++;
        }
        if(flag)printf("no");
        else printf("yes");
    }
    return 0;
}
