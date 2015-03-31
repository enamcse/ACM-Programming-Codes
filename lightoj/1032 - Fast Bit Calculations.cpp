/* 
* @Author: Enamul Hassan
* @Date:   2015-03-22 23:14:04
* @Last Modified by:   Enamul
* @Last Modified time: 2015-03-23 02:11:24
* @Verdict: Solved
* @File Path: H:\Dropbox\Code\lightoj\1032 - Fast Bit Calculations.cpp
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 200005
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
#define mod 1000000007

using namespace std;

string s;

pair<ll,ll> dp[35][2][2];

pair<ll,ll> rec(int pos, int pre, bool flag)
{
	if(pos == 32) return make_pair(0,1);
	pair<ll,ll> &ret = dp[pos][pre][flag];
	if(ret.first != -1) return ret;

	ret = make_pair(0,0);

	int en = (flag?s[pos]:'1')-'0';
	pair<ll,ll>temp;
	for (int i = 0; i <= en; ++i)
	{
		/* code */
		temp = rec(pos+1,i,flag&&i==en);
		ret.first+=temp.first;
		ret.second+=temp.second;
		if(i==1 && pre==1)ret.first+=temp.second;
	}
	return ret;
}


int main(){
	#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, cas=1;
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    scanf("%d", &t);
    while(t--)
    {
    	scanf("%d", &n);
    	clr(dp,-1);
    	bitset<32>bt(n);
    	s = bt.to_string();

    	printf("Case %d: %lld\n", cas++,rec(0,0,1).first);
    }
	
//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}












