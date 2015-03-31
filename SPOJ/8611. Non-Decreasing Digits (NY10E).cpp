#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>
#include <cctype>
#include <map>
#include <list>
#include<set>

#define sz 69
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define inf (1<<30-1)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
using namespace std;

ll dp[sz][sz], state[sz];

int main()
{
    ll temp;
    for (int i = 0; i<10; i++)
    {
        dp[1][i] = 1;
        state[1]+=dp[1][i];
    }

    for (int i = 2; i<=64; i++)
    {
        temp = state[i-1];
        for (int j=0; j<10; j++)
        {
            state[i]+=temp;
            dp[i][j]=temp;
            temp-=dp[i-1][j];
        }
    }
    int t,x,y;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &x, &y);
        printf("%d %lld\n", x,state[y]);
    }
	return 0;
}
