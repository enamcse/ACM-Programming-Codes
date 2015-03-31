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
int cnt[2];
int main()
{
    _
    int n, k;
    bool flag = true;
    scanf("%d", &n);
    for (int i = 0; i<n; i++)
    {
        scanf("%d", &k);
        if(k==25) cnt[0]++;
        else if (k==50) {cnt[0]--;cnt[1]++;}
        else
        {
            if(cnt[0]-1>=0&&cnt[1]-1>=0)
            {
                cnt[0]--;cnt[1]--;
            }
            else cnt[0]-=3;
        }
        if(cnt[0]<0||cnt[1]<0) flag = false;
    }
    if(flag) printf("YES");
    else printf("NO");
    return 0;
}
