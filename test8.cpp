/*
* @Author: mdgaurab
* @Date:   2015-03-21 16:47:14
* @Last Modified by:   mdgaurab
* @Last Modified time: 2015-03-21 18:17:57
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
#define lim       550
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
int N, M;
Long DP[31][lim][lim];
bool ok(int mask, int biti)
{
	if ((mask & (1 << biti))) return 0;
	return 1;
}
Long REC(int , int , int );
Long generate_t(int pos, int cur, int a, int b)
{
	if (cur == ((1 << M) - 1))
	{
		return REC(pos + 1, a, b);
	}
	int i = 0;
	Long tot = 0;
	while (i < M)
	{
		if (ok(cur, i))
		{
			if (i + 2 < M && ok(cur, i + 1) && ok(cur, i + 2))
			{
				tot += generate_t(pos, (cur | (1 << i) | (1 < (i + 1)) | (1 << (i + 2))), a, b);
			}
			if (pos + 2 < N && ok(cur, i) && ok(a, i) && ok(b, i))
			{
				tot += generate_t(pos, (cur | (1 << i)), (a | (1 << i)), (b | (1 << i)));
			}
			break;
		}
		i++;
	}
	if (i == M) tot += REC(pos + 1, a, b);
	return tot;
}

Long gen(int pos, int cur, int a, int b)
{
    if (cur == ((1 << M) - 1))
	{
		return REC(pos + 1, a, b);
	}
//    if(dp2.count( make_pair(pos, make_pair(mask,mask2) ) )) return dp2[ make_pair(pos, make_pair(mask,mask2) ) ];
//    dp2[ make_pair(pos, make_pair(mask,mask2) ) ] = 0;

//    ll &ret = dp2[pos][mask][mask2];
//    if(ret!=-1) return ret;
    Long ret = 0;
    int i;
    for(i = 0;i<M;i++)
    {
        if(!((1<<i)&cur))
        {
            if (i + 2 < M && ok(cur, i + 1) && ok(cur, i + 2))
			{
				ret += gen(pos, (cur | (1 << i) | (1 << (i + 1)) | (1 << (i + 2))), a, b);
			}
//			if (pos + 2 < N && ok(cur, i) && ok(a, i) && ok(b, i))
//			{
//				ret += generate_t(pos, (cur | (1 << i)), (a | (1 << i)), (b | (1 << i)));
//			}

//           if (i + 2 < M && ok(cur, i + 1) && ok(cur, i + 2)) ret+=gen(pos,cur|(1<<i)|(1<<(i+1))|(1<<(i+2)), a,b);

            if(pos+2<N)
            {
                if(!((1<<i)&a)  && !((1<<i)&b)) ret+=gen(pos,cur|(1<<i), a|(1<<i),b|(1<<i));
            }
            break;
        }
    }
    if(i==M) ret=REC(pos+1,a, b);
    return ret;
}





Long REC(int pos, int a, int b)
{
	if (pos == N)
	{
		if (a == 0 and b == 0) return 1LL;
		else return 0LL;
	}
	Long &ret = DP[pos][a][b];
	if (~ret) return ret;
	ret = gen(pos, a, b, 0);
	return ret;
}
int main(int argc, const char **argv)
{
	//ios::sync_with_stdio(false);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	//double st=clock(),en;
	while (cin >> M >> N and (M + N))
	{
		mem(DP, -1);
		cout << REC(0, 0, 0) << endl;
	}
	//en=clock();
	//cerr<<(double)(en-st)/CLOCKS_PER_SEC<<endl;
	return 0;
}
