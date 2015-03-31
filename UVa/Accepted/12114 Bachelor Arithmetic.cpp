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
    int s, b,cas=1;
    double prev, now;
    while(scanf("%d %d",&b,&s)&&b&&s)
    {
        if(b==0||b==1)
        {
//            if(b>s) printf("Case %d: :-)\n",cas++);
//            else if (b<s) printf("Case %d: :-(\n",cas++);
            printf("Case %d: :-\\\n",cas++);
        }
        else if (b==s)printf("Case %d: :-|\n",cas++);
        else
        {
            prev = s/(b*1.0);
            now = (s-1)/((b-1)*1.0);
            prev = prev>1?1:prev;
            now = now>1?1:now;
            if(now==prev) printf("Case %d: :-|\n",cas++);
            else if (now<prev)printf("Case %d: :-(\n",cas++);
            else printf("Case %d: :-)\n",cas++);
        }
    }
    return 0;
}
