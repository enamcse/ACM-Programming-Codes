/**
* H:\Dropbox\Code\lightoj\1138 - Trailing Zeroes (III).cpp
* Created on: 2015-02-09-03.31.45, Monday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <stdio.h>
#define ll long long

ll check(int now)
{
    ll ans = 0;
    while(now)
    {
        now/=5;
        ans+=now;
    }
    return ans;
}


int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, cas=1, ans, lef = 0, righ = 1e9, mid;
    scanf("%d", &t);
    ll m;
    while(t--)
    {
        ans=0;
        scanf("%d", &n);

        lef = 0, righ = 1e9;
        while(lef<righ)
        {
            mid = (lef+righ)>>1;
            m = check(mid);
            if(m==n)
            {
                ans = mid;
                break;
            }
            else if(m>n) righ = mid-1;
            else lef = mid+1;
        }
        if(ans) printf("Case %d: %d\n", cas++, (ans/5)*5);
        else printf("Case %d: impossible\n", cas++);

    }


   return 0;
}
