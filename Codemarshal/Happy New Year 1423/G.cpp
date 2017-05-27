/*
* @Author: Enum
* @Date:   2016-04-18 20:39:10
* @Last Modified by:   mkg
* @Last Modified time: 2016-04-18 20:52:13
*/

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long Long;
typedef double DD;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef pair<int, int> PII;
typedef pair<Long, Long> PLL;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;

const int INF = 2000000000;
const int MOD = 1000000007;
const Long L_MAX = 9223372036854775807;
const int I_MAX = 2147483647;

#define sf scanf
#define pf printf
#define mem(a,b)          memset(a,b,sizeof(a))
#define pb push_back
#define REP(i,a,b)        for(int i=a; i<=b; ++i)
#define REPI(i,a,b,c)     for(int i=a; i<=b; i+=c)
#define REPR(i,a,b)       for(int i=b; i>=a; --i)
#define REPRD(i,a,b,c)    for(int i=b; i>=a; i-=c)
#define REPB(i,a)         for(int i=a; ;i++)
#define REPRB(i,a)        for(int i=a; ; i--)
#define mp(a,b)   make_pair(a,b)
#define fs        first
#define sc        second
#define SZ(s)     ((int)s.size())
#define PI        3.141592653589793
#define VS        vector<string>
#define VI        vector<int>
#define VD        vector<DD>
#define VL        vector<Long>
#define VVL       vector<VL >
#define lim       10000010
#define tlim      (1<<((int)ceil(log2(lim))+1))
#define unq(vec)  stable_sort(vec.begin(),vec.end());\
                  vec.resize(distance(vec.begin(),unique(vec.begin(),vec.end())));
#define BE(a)     a.begin(),a.end()
#define rev(a)    reverse(BE(a))
#define sorta(a)  stable_sort(BE(a))
#define sortc(a, comp)  sort(BE(a),comp)

//int X[]={1,1,2,2,-1,-1,-2,-2},Y[]={2,-2,1,-1,2,-2,1,-1};//knight move
//int X[]={0,-1,-1,-1,0,1,1,1},Y[]={-1,-1,0,1,1,1,0,-1};//8 move
//int X[]={-1,0,1,0},Y[]={0,1,0,-1};//4 move

int dig[70], tmp[70];
Long DP[70][70][2];

bool OK(string str) {
	int k = SZ(str) - 1;
	REP(i, 0, k) {
		if (str[i] != str[k - i]) return false;
	}
	return true;
}

Long REC(int pos, int spos, int f, int e1) {
	if (pos < 0) return f;
	Long &ret = DP[pos][spos][f];
	if (!e1 && ~ret) return ret;
	int mdig = e1 ? dig[pos] : 9;
	Long res = 0;
	REP(i, 0, mdig) {
		bool st = (pos == spos && i == 0);
		int nf = f;
		if (f) {
			if (!st && pos < ((spos + 1) >> 1)) {
				nf = (i == tmp[spos - pos] ? 1 : 0);
			}
		}
		tmp[pos] = i;
		res += REC(pos - 1, st ? spos - 1 : spos, nf, e1 && (i == mdig));
	}
	return e1 ? res : ret = res;
}

Long solve(string str) {
	int len = SZ(str) - 1;
	REP(i, 0, len) {
		dig[i] = str[len - i] - '0';
	}
	return REC(len, len, 1, 1);
}

int main(int argc, const char **argv) {
	//ios::sync_with_stdio(false);
	//double st=clock(),en;
	int Test;
	char ch[200];
	Long Res;
	string A;
	sf("%d", &Test);
	mem(DP, -1);
	REP(kase, 1, Test) {
		sf("%s", ch);
		A = ch;
		Res = solve(A);
		Res--;
		pf("Case %d: %lld\n", kase, Res);
	}
	//en=clock();
	//cerr<<(double)(en-st)/CLOCKS_PER_SEC<<endl;
	return 0;
}