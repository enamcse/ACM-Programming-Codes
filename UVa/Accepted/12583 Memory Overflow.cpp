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
    int n, t, cas=1, mem, cnt;
    char line[10000];
    scanf("%d", &t);
    while(t--)
    {
        cnt=0;
        scanf("%d %d %s", &n, &mem, line);

        for (int i = 0,j; i<n; i++)
        {
            for (j = (i-mem>0?i-mem:0); j<i; j++)
            {
                if(line[i]==line[j])
                {
                    cnt++;
                    break;
                }
            }
        }
        printf("Case %d: %d\n", cas++, cnt);
    }
    return 0;
}
/*
6
6 2 SULTAN
6 1 MAHBUB
6 2 MAHBUB
6 2 SULTAN
6 1 MAHBUB
6 2 MAHBUB
*/
