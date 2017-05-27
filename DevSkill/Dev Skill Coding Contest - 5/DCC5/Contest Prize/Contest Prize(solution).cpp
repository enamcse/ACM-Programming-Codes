/*
    rezwan_4029
*/
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

typedef long long Long;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef vector<Long>vl;
typedef pair<int,int>pii;
typedef pair<double,double>pdd;

#define forab(i, a, b)        for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)                forab (i, 0, (n) - 1)
#define For(i, n)                forab (i, 1, n)
#define rofba(i, a, b)        for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)                rofba (i, 0, (n) - 1)
#define rof(i, n)                rofba (i, 1, n)
#define forstl(i, s)        for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

const int MX = 1e3 + 7;
const int MD = 1e9 + 9;
Long dp[MX][MX];

Long solve(int k, int n){
    if( k == 1 || n == 0 ) return 1;
    Long &ret = dp[k][n];
    if( ret != -1 ) return ret;
    ret = solve(k - 1, n);
    if( n >= k ) ret += solve(k, n - k);
    ret %= MD;
    return ret;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ms(dp, -1);
    int T = II;
    For(cs,T){
        int n , k ;
        cin >> n >> k ;
        printf("Case %d: ",cs);
        if( k > n ) puts("0");
        else cout << solve(k, n - k) << endl;
    }
}
