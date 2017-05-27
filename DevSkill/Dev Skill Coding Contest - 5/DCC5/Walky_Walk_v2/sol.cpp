/*
Bismillahir Rahmanir Rahim
Coder: Ahmad Faiyaz
*/

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>


# define FOR(i, a, b) for (int i=a; i<b; i++)
# define REP(i, a) FOR(i,0,a)

#define EPS 1e-11
#define inf 1234567891
#define LL long long

#define abs(x) (((x)< 0) ? (-(x)) : (x))
#define all(x) (x).begin(), (x).end()
#define ms(x, a) memset((x), (a), sizeof(x))

#define pb push_back
#define FORIT(i,m) for(__typeof((m).begin()) i=(m).begin();i!=(m).end();i++)
#define pii pair<int,int>
#define UNIQUE(c) (c).resize( unique( all(c) ) - (c).begin() )

#define READ(f) {ifstream infile(f) ;if(infile.good()) freopen(f, "r", stdin);}
#define WRITE(f) freopen(f, "w", stdout)
#define CIN ios_base::sync_with_stdio(0);
///int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///int month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;
#define MAX 1005
int arr [MAX];
int mem [MAX][MAX];
int n;
int dp(int idx, int lst){
    if(idx == n){
        return 0;
    }

    if(mem[idx][lst]  > -1) return mem[idx][lst];

    int ret = inf;

    if(idx + lst + 1 <= n)
        ret = min(ret, arr[idx+lst+1] + dp(idx+lst+1, lst+1));
    if(idx - lst >= 1 && idx - lst != idx){
        ret = min(ret, arr[idx-lst]   + dp(idx-lst,  lst));
    }

    return mem[idx][lst] = ret;
}

int main(){
    
    int t, chk =1 ;

    scanf("%d", &t);

    while(t--){
        scanf("%d", &n);

        for(int i=1;i<=n;i++){
            scanf("%d", &arr[i]);
        }

        ms(mem, -1);

        printf("Case %d: %d\n", chk++, dp(1, 0));
    }

    return 0;
}
