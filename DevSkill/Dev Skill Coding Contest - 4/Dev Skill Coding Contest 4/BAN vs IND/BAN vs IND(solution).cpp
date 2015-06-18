#include <bits/stdc++.h>
#define pb push_back
#define INF 1<<29
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL  ({ll  a; scanf("%lld", &a); a;})
#define EPS 1e-10
#define pi 3.1415926535897932384626433832795
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef vector<ll>vl;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef pair<double,double>pdd;

#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

int M ;
double p ;
double dp[200][200];

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int test = II ;
    For(cs,test) {

        scanf("%d %lf",&M, &p);

        forab(i,0,M)
            forab(j,0,M) dp[i][j] = 0.00;

        dp[0][0] = 1.00 ;

        rep(i,M) rep(j,M) {
            dp[i+1][j] += dp[i][j] * p ;
            dp[i][j+1] += dp[i][j] * ( 1.000 - p );
        }

        double Ans = 0.00 ;

        forab(i,0,M) Ans += dp[M][i];

        printf("Case %d: %.3lf\n",cs, Ans);
    }
}
