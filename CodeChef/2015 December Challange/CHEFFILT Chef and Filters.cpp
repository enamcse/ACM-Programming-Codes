/**
* H:\Dropbox\Code\CodeChef\2015 December Challange\CHEFFILT Chef and Filters.cpp
* Created on: 2015-12-07-00.21.22, Monday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define SZ(a) ((int)a.size())
#define sz 100005
#define pb push_back
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
#define cntbit(mask) __builtin_popcount(mask)
#define unify(a) stable_sort(a.begin(),a.end());a.resize(distance(a.begin(),unique(all(a))));
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e18)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define pi 3.14159265358979323846264338327950288419716939937510
#define fr(i,a,b) for(i=a;i<=b;i++)
#define cspf printf("Case %d:", cas++);
#define csco cout<<"Case "<<cas++<<":";
#define mod 1000000007LL
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

const int lim = (1<<10)-1;
char ss[12], s[12];
int dp[5][lim+10], cnt[lim+10], arr[sz],n,t, m, mask,i,j, xors[lim+10][lim+10];
ll p;

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM

//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    for (i=0; i<=lim; i++)
        for (j=i+1; j<=lim; j++)
            xors[i][j]=xors[j][i]=i^j;

    scanf("%d", &t);

    while(t--)
    {

        scanf(" %s %d", s, &n);
        for ( i = 1; i<=n; i++)
        {
            scanf(" %s", ss);
            arr[i] = 0;
            for ( j = 0; j<10; j++)
                if(ss[j]=='+')arr[i]|=(1<<j);
        }

        mask = 0;
        for ( j = 0; j<10; j++)
            if(s[j]=='b')mask|=(1<<j);

        dp[t][mask]=1;
        arr[0]=-1;
        p=1;
        sort(arr+1,arr+n+1);
        for ( i = 1; i<=n; i++)
        {
            if(arr[i]==arr[i-1])
            {
                p*=2LL;
                p%=mod;
                continue;
            }
            else
            {
                for (j=0; j<=lim; j++)
                    dp[t][j] = ((ll)dp[t][j]*p)%mod;

                for ( j = 0; j<=lim; j++)
                {
                    cnt[ j ]=dp[t][xors[arr[i]][j]];
                    if(cnt[j]>=mod) cnt[j]-=mod;
                }

                for ( j = 0; j<=lim; j++)
                {
                    dp[t][ j ]+=cnt[j];
                    if(dp[t][j]>=mod) dp[t][j]-=mod;
                    cnt[j]=0;
                }
                p=1;
            }

        }

        for (j=0; j<=lim; j++)
             dp[t][j] = ((ll)dp[t][j]*p)%mod;

//        assert(temp<4);
        printf("%d\n", dp[t][lim]);

    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
