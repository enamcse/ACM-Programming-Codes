#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 1000005
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
using namespace std;

vector<int>v;


int main()
{
    int n, q,x,cas=1;
    while(~scanf("%d %d", &n, &q)&&(n||q))
    {
        v.clear();
        for (int i = 0; i<n; i++)
        {
            scanf("%d", &x);
            v.pb(x);
        }

        sort(v.begin(), v.end());
        printf("CASE# %d:\n",cas++);
        for (int i = 0; i<q; i++)
        {
            scanf("%d", &x);
            if(binary_search(v.begin(),v.end(), x))
                printf("%d found at %d\n",x,lower_bound(v.begin(),v.end(), x)- v.begin()+1);
            else
                printf("%d not found\n",x);
        }
    }
    return 0;
}
