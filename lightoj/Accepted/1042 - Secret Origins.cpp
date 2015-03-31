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
    int t, n, cas=1, cnt, k, hand;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        k=(1<<30);
        cnt=0;
        while(k)
        {
            if((n&k)!=0) cnt++;
            k>>=1;
        }
        if(cnt==1)
        {
            k=1;

            while((n&k)==0)k<<=1;
            n = (k<<1);
        }
        else
        {
            k=1;
            hand = 0;
            while((n&k)==0)k<<=1;
            n^=k;
            k<<=1;
            while((n&k)!=0)
            {
                hand++;
                n^=k;
                k<<=1;
            }
            n|=k;
            k=1;
            while(hand)
            {
                if((n&k)==0)
                {
                    n|=k;
                    hand--;
                }
                k<<=1;
            }
        }
        printf("Case %d: %d\n", cas++,n);
    }

    return 0;
}
