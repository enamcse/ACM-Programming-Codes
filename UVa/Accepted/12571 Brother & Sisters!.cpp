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

bool ok[255];

int main()
{
    _

    int t, n, q, num, ind,mx, nd;
    scanf("%d", &t);
    while(t--)
    {
        clr(ok,false);
        scanf("%d %d", &n, &q);
        for (int i = 0; i<n; i++)
        {
            scanf("%d", &num);
            ok[(num&255)] = true;
        }
        for (int i =0; i<q; i++)
        {
            scanf("%d", &num);
            ind = 232;
            mx=0;
            while(ind--)
            {
                nd  =(ind&num);
                if(nd>mx&&ok[nd]==true) mx = nd;
            }
            printf("%d\n", mx);
        }
    }

    return 0;
}
