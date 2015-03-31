//#include <bits/stdc++.h>
//#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#include <stdio.h>
#include <math.h>
#include <set>
using namespace std;

#define sz 100010
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)


double dp[sz];

set<int> find_divisors(int n)
{
    set<int>s;
    int len = sqrt(n);
    for (int i = 1; i<=len; i++)
    {
        if(n%i==0)
        {
            s.insert(i);
            s.insert(n/i);
        }
    }
    return s;
}

double rec(int n)
{
    if(n==1) return 0.0;
    double &ret = dp[n];
    if(ret!=-1.0) return ret;
    ret = 2.0;
    set<int>s = find_divisors(n);
    if(s.size()<=2) return ret;
    double E = s.size()-1;

    for (set<int>:: iterator it =  s.begin() ; ++it!=s.end();)
        if(*it!=n)ret+=(rec(*it)+1.0);
    ret/=E;
    return ret;
}

int main()
{
    #ifdef ENAM
    	fread;
	fwrite;
    #endif // ENAM
    int t, n, m, cas=1;

    scanf("%d", &t);
    for (int i = 0; i<sz; i++) dp[i] = -1.0;

    while(t--)
    {
        scanf("%d", &n);
        printf("Case %d: %lf\n",cas++,rec(n));
    }


    return 0;
}
