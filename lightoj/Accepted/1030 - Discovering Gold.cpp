#include <stdio.h>
#include <algorithm>
#define sz 105

int n;
double arr[sz],dp[sz];

double rec(int pos)
{

    if(pos==n-1) return arr[pos];
    double &ret = dp[pos];
    if(ret!=-1.0) return ret;
    ret = arr[pos];
    int len = std::min(n-pos-1,6);
    for (int i = 0; i<len; i++)
        ret+=(rec(pos+i+1)/(len*1.0));

    return ret;
}


int main()
{
    #ifdef ENAM
    	fread;
	fwrite;
    #endif // ENAM
    int t, m, cas=1;
    scanf("%d", &t);

    while(t--)
    {
        scanf("%d", &n);

        for (int i = 0; i<n; i++)
            dp[i]=-1.0;

        for (int i = 0; i<n; i++)
            scanf("%lf", &arr[i]);
        printf("Case %d: %lf\n",cas++,rec(0));
    }


    return 0;
}
