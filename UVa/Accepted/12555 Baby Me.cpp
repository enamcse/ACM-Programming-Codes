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
    int n, x, y, cas=1, len;
    char line[10];
    double ans;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%s", line);
        len = strlen(line);
        if(len>5)
        {
            sscanf(line,"%d%*c%*c%*c%d", &x, &y);
        }
        else
        {
            sscanf(line,"%d", &x);
            y = 0;
        }
        ans = (x*0.5)+(y*0.05);
        printf("Case %d: %g\n",cas++,ans);
    }
    return 0;
}
/*
3
5???2两
7???3两
6斤
*/
