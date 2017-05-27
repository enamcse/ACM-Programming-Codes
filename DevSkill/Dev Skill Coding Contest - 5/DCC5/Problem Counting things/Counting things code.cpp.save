#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    //freopen("strin.txt", "r", stdin);
    //freopen("strout.txt", "w", stdout);
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        ll  a,d,k,n;
        scanf("%lld%lld%lld",&a,&d,&k);
        n=0;
        if(k<a)n=0;
        else if(d==0)n=1;
        else
        {
            ll lo=0;
            ll hi=100000000ll;

            while(lo<=hi)
            {
                ll mid=(lo+hi)/2;
                ll res=mid*(2*a+(mid-1)*d);
                if(res<=2*k)
                {
                    n=max(n,mid);
                    lo=mid+1;
                }
                else hi=mid-1;
            }
        }
        printf("%lld\n",n);
    }

    return 0;
}
