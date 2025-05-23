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
int a [MAX];

vector <int> diff;
int main(){
    #if defined( faiyaz_pc )
        READ("input.txt");
        WRITE("out2.txt");
    #endif

    int t, n, chk = 1;

    CIN;

    cin>>t;

    while(t--){
        cin>>n;

        diff.clear();

        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                    int dif = abs(a[i] - a[j]);
                    diff.pb(dif);
            }
        }

        int g = diff[0];

        for(int i=1;i<diff.size();i++){
           // cout<<i<<" "<<g<<endl;
            g = __gcd(diff[i], g);
        }

        vector <int> res;
        for(long long i=1;i*i <= g;i++){
                if(g%i == 0){
                    int o = g/i;
                    if(i!=1)
                        res.pb(i);

                    if(o != i){
                        res.pb(o);
                    }
                }
        }

        sort(all(res));


        cout<<"Case "<<chk++<<":\n";
        for(int i=0;i<res.size();i++){
                if(i)cout<<" ";
            cout<<res[i];
        }
        cout<<"\n";

    }

    return 0;
}
