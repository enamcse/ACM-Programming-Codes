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
    int t,n, cnt,cas=1;
    char str[20];
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %s", &n, str);
        if(!strcmp("Alice", str))
        {
            if(n%3==1) printf("Case %d: Bob\n", cas++);
            else printf("Case %d: Alice\n", cas++);
        }
        else
        {
            if(n%3) printf("Case %d: Bob\n", cas++);
            else printf("Case %d: Alice\n", cas++);
        }
    }
    return 0;
}
