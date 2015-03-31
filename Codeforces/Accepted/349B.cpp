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

int num[10];
vector<int>v;

int main()
{
    _
    int n, mn = inf,cost,len, sum,cur=0;
    scanf("%d", &n);
    for (int i =1; i<10; i++)
    {
        scanf("%d", &num[i]);
        mn = mn<num[i]?mn:num[i];
    }
    len = n/mn;
    if(len)
    {
        sum=n%mn;
        for (int i = 0; i<len; i++)
        {
            sum+=mn;
            for (int j = 9; j>=1; j--)
            {
                if(num[j]+cur<=sum)
                {
                    cur += num[j];
                    printf("%d", j);
                    break;
                }
            }
        }

    }
    else printf("%d", -1);
    return 0;
}
