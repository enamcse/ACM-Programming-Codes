/*
* @Author: Enamul Hassan
* @Date:   2015-03-26 13:00:48
* @Last Modified by:   Enamul
* @Last Modified time: 2015-03-30 18:58:21
* @Verdict: Solved
* @File Path: H:\Dropbox\Code\lightoj\1326 - Race.cpp
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 1005
#define pb(a) push_back(a)
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
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 10056
ll bigmod(ll sonkha, ll ghat, ll vag_const) {ll vag_shesh = 1; while (ghat > 0) {if (ghat % 2 == 1) {vag_shesh = (vag_shesh * sonkha) % vag_const;} ghat /= 2; sonkha = (sonkha * sonkha) % vag_const;} return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const) {return bigmod(bivajok, vag_const - 2, vag_const);}
using namespace std;

int dp[sz];

int ncr[sz][sz];

int nCr(int n, int r)
{
	if (r == 1) return n;
	if (n == r) return 1;
	int &ret = ncr[n][r];
	if (ret != -1) return ret;
	ret = (nCr(n - 1, r) + nCr(n - 1, r - 1)) % mod;
	return ret;
}


int rec(int pos)
{
	if (pos == 0) return 1;

	int &ret = dp[pos];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 1; i <= pos; ++i)
	{
		ret += (nCr(pos, i) * (rec(pos - i) % mod)) % mod;
		ret %= mod;
	}

	return ret;
}



int main() {
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
	int t, n, cas = 1;

//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
	clr(dp, -1);
	clr(ncr, -1);

	scanf("%d", &t);

	while (t--)
	{
		scanf("%d", &n);
		printf("Case %d: %d\n", cas++, rec(n) % mod);
	}



//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

	return 0;
}












