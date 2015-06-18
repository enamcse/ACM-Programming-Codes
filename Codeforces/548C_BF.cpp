/*
 * C.cpp
 *
 *  Created on: May 26, 2015
 *      Author: mkg
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
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef pair<Long, Long> PLL;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef vector<string> VS;
typedef vector<DD> VD;
typedef vector<Long> VL;
typedef vector<VL> VVL;

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

Long mod, H1, A1, X1, Y1, H2, A2, X2, Y2, nxt;

map<pair<Long, Long>, int> mpp;

int main(int argc, const char **argv) {
    //ios::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    freopen("BANG.txt","w",stdout);
    //double st=clock(),en;
    while (sf("%lld", &mod) == 1) {
        sf("%lld %lld %lld %lld %lld %lld %lld %lld", &H1, &A1, &X1, &Y1, &H2, &A2, &X2, &Y2);
        mpp.clear();
        nxt = 1;
        mpp[pair<Long, Long>(H1, H2)] = nxt++;
        int i = 0, c;
        while (true) {
            cout<<i <<"=t, h1 = "<<H1<<", h2 = "<<H2<<endl;
            H1 = (int) ((X1 * H1 + Y1) % mod);
            H2 = (int) ((X2 * H2 + Y2) % mod);
            if (H1 == A1 && H2 == A2) {
                c = i;
                break;
            }
            if (mpp.find(pair<Long, Long>(H1, H2)) != mpp.end()) {
                c = -2;
                break;
            } else
                mpp[pair<Long, Long>(H1, H2)] = nxt++;
            i++;
        }
        //out.println("break at "+i);
        if (c == 0)
            pf("-1\n");
        else
            pf("%d\n", c + 1);
    }
    //en=clock();
    //cerr<<(double)(en-st)/CLOCKS_PER_SEC<<endl;
    return 0;
}
