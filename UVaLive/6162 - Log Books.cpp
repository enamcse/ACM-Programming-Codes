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
    int n,h[4],m[4], driving_time,after, before, night,d,ab,s,e,rise,sett;
    bool flag;
    while(scanf("%d",&n)&&n)
    {
        driving_time = 0;
        night=0;
        flag = true;
        while(n--)
        {
            for (int i =0; i<4; i++)
                scanf("%d:%d",&h[i], &m[i]);

            s = h[2]*60+m[2];
            e = h[3]*60+m[3];
            rise = h[0]*60+m[0];
            sett = h[1]*60+m[1];
            d =e - s;
            driving_time += d;
            if(e<=rise)
            {
                night+=d;
            }
            else if (s>=sett)
            {
                night+=d;
            }
            else
            {
                after = e - sett;
                before = rise - s;
                if(after<0) after=0;
                if(before<0) before=0;
                ab = (after+before);
                if(ab<=(d>>1)) night+=ab;
            }


            if(d>120) flag=false;
        }
        if(flag&&night>=600&&driving_time>=3000) printf("PASS\n");
        else printf("NON\n");
    }
    return 0;
}
