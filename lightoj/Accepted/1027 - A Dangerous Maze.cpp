#include <stdio.h>
#include <algorithm>
#define sz 101
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)

using namespace std;

int arr[sz];

int main()
{
    #ifdef ENAM
    	fread;
	fwrite;
    #endif // ENAM
    int t, n, m, cas=1;
    ll din, neu, E, g;
    bool flag;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        din =  0;
        neu = 1;
        E = n;
        flag = true;
        for (int i = 0; i<n; i++)
        {
            scanf("%d", &arr[i]);
            if(arr[i]<0) E--,din-=arr[i];
            else din+=arr[i], flag = false;
        }
        if(flag) printf("Case %d: inf\n", cas++);
        else
        {
            neu*=E;
            g = __gcd(din, neu);
            din/=g;
            neu/=g;
            printf("Case %d: %lld/%lld\n", cas++, din, neu);
        }
    }

    return 0;
}
