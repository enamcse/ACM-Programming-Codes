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

#define MAX 105

#define MOD 1000000007

int x [MAX], y[MAX];
LL mem [MAX][MAX];
LL dp(int idx, int task){
    if(idx == 0){
        if(task == 0) return 1;
        return 0;
    }

    if(mem[idx][task] > -1) return mem[idx][task];

    LL ret = 0;

    for(int i=x[idx];i<=y[idx];i++){
            if(task - i >= 0)
                ret = (ret + dp(idx-1, task-i));
            else break;
    }

    return mem[idx][task] = ret;
}
int main(){
    #if defined( faiyaz_pc )
        READ("input.txt");
        WRITE("out.txt");
    #endif

    int t, n, m, chk = 1;
    CIN;

    cin>>t;

    while(t--){
        cin>>n>>m;

        for(int i=1;i<=m;i++){
            cin>>x[i]>>y[i];
        }

        ms(mem, -1);
        cout<<"Case "<<chk++<<": "<<dp(m, n)<<"\n";
    }

    return 0;
}
