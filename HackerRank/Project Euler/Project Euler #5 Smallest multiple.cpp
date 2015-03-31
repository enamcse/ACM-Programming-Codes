#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>
#include <cctype>
#define sz 100
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
using namespace std;

int prime[25], cnt, factor[25];



int main()
{
    bool flag;
    for (int i = 2; i<=50; i++)
    {
        flag = true;
        for (int j = 2; j<i; j++)
        {
            if(i%j==0)
            {
                flag = false;
                break;
            }
        }
        if(flag) prime[cnt++]=i;
    }
    int t, n;

    cin>>t;

    while(t--)
    {
        clr(factor,0);
        cin>>n;
        for (int j = 1; j<=n; j++)
        {
            int k = j;
            for (int i = 0; i<cnt&&k>1; i++)
                if(k%prime[i]==0)
                {
                    int p = 0;
                    while(k%prime[i]==0) k/=prime[i], p++;
                    factor[i] = max(factor[i],p);
                }
        }
        n = 1;
        for (int i = 0; i<cnt; i++)
            for (int j = 0; j<factor[i]; j++) n*=prime[i];

        cout<<n<<endl;
    }


    return 0;
}
