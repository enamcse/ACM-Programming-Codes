/*
* @Author: Enamul Hassan
* @Date:   2015-03-26 14:51:42
* @Last Modified by:   Enamul
* @Last Modified time: 2015-03-26 18:25:48
* @Verdict: Solved
* @File Path: H:\Dropbox\Code\lightoj\1382 - The Queue.cpp
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define pb(a) push_back(a)
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define mod 1000000007
ll bigmod(ll sonkha, ll ghat, ll vag_const) {ll vag_shesh = 1; while (ghat > 0) {if (ghat % 2 == 1) {vag_shesh = (vag_shesh * sonkha) % vag_const;} ghat /= 2; sonkha = (sonkha * sonkha) % vag_const;} return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const) {return bigmod(bivajok, vag_const - 2, vag_const);}
using namespace std;

vector<int>adj[1005];
ll fact[1005];

pair<ll, ll> rec(int node) ///make_pair(combinations, node)
{
	pair<ll, ll> ret = make_pair(1, 0), temp;
	for (int i = 0; i < adj[node].size(); i++)
	{
		temp = rec(adj[node][i]);
		ret.first =(( (ret.first * temp.first) %mod) * (fact[ret.second + temp.second]))%mod;
		 ret.first*=inverse_mod((fact[ret.second] * fact[temp.second])%mod,mod);
		 ret.first%=mod;
		ret.second += temp.second;
	}
	ret.second++;
	return ret;
}

int degree[1005];

int main() {
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
	int t, n, cas = 1, u, v;
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

	fact[0] = 1;
	for (int i = 1; i <= 1004; i++)
		fact[i] = (fact[i - 1] * i) % mod;


	scanf("%d", &t);

	while (t--)
	{
		scanf("%d", &n);

		for (int i = 0; i < n + 1; ++i)
			adj[i].clear();
		clr(degree,0);
		for (int i = 0; i < n - 1; ++i)
		{
			scanf("%d %d", &u, &v);
			adj[u].pb(v);
			degree[v]++;
		}

		for (u = 1; u <= n; ++u)
			if(!degree[u]) break;
		printf("Case %d: %lld\n", cas++, rec(u).first%mod);
	}


//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

	return 0;
}












