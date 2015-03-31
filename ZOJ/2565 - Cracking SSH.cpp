/* 
* @Author: Enamul Hassan
* @Date:   2015-03-21 19:28:40
* @Last Modified by:   Enamul
* @Last Modified time: 2015-03-22 00:28:43
* @Verdict: Solved
* @File Path: H:\Dropbox\Code\ZOJ\2565 - Cracking SSH.cpp
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 205
#define pb(a) push_back(a)
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
#define cntbit(mask) __builtin_popcount(mask)
#define unify(a) stable_sort(a.begin(),a.end());a.resize(distance(a.begin(),unique(all(a))));
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e9)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define pi 3.14159265358979323846264338327950288419716939937510
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}
using namespace std;

int n, m, a[sz],t[sz][sz], dp[sz][sz], path[sz][sz];

void path_dp(int pos, int pre)
{
	// cerr<<pos<<":"<<pre<<path[pos][pre]<<endl;
	if(pos==n)
	{
		cout<<"\n";
		return;
	}
	cout<<char(path[pos][pre]+'a'-1);
	path_dp(pos+1,path[pos][pre]);
}

int rec(int pos, int pre)
{
	if(pos==n) return 0;
	int &ret = dp[pos][pre], now;
	if(ret!=-1) return ret;
	ret = inf;
	for (int i = 1; i <= m; ++i)
	{
		/* code */
		now = rec(pos+1,i) + abs( t[pre][i] - a[pos] );
		// cout<<pos<<" "<<pre<<"K"<<now<<" L "<<ret<<endl;
		if(now<ret)
		{
			ret = now;
			path[pos][pre] = i;
		}
	}
	return ret;
}

int main(){
	#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();


	while(cin>>n>>m)
	{
		for (int i = 1; i < n; ++i)
		{
			/* code */
			cin>>a[i];
		}

		for (int i = 1; i <= m; ++i)
		{
			/* code */
			for (int j = 1; j <= m; ++j)
			{
				/* code */
				cin>>t[i][j];
			}
		}
		clr(dp,-1);
		// clr(path,-1);
		rec(0,0);
		path_dp(0,0);

	}


//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}












