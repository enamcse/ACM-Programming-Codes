#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
#include<sstream>

typedef long long ll;
typedef unsigned long long ull; //scanf("%llu",&N);
#define READ(a) freopen("a.txt","r",stdin)
#define WRITE(a) freopen("a.txt","w",stdout)
#define FOR(i,a,b)  for(int i=(a);i<b;i++)
#define REV(i,a,b)  for(int i=a;i>=b;i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define clr(a) a.clear()
#define mp make_pair
#define pb push_back
#define SZ(a) (int)a.size()
#define all(a) (a).begin(),(a).end()
#define reall(a) (a).rbegin(),(a).rend()
#define fs first
#define sc second
#define PI (2*acos(0.0))
#define ERR (1e-7)
#define EQ(a,b) (fabs(a-b)<ERR)

#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
//#define FOREACH(it,x) for(__typeof((x.begin())) it=x.begin();it!=x.end();it++)
////int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1};                      //4 Direction
////int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};  //8 direction
////int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

using namespace std;
typedef vector<int>     VI;
typedef vector<string>  VS;
typedef pair<int,int>   PII;
typedef pair<int,PII >  DPII;
typedef vector<pair<int,int> >VPII;
typedef vector<pair<int,pair<int,int> > > VDPII;

const int INF=(1<<29);
const int MAX=5009;

int grid[MAX][MAX];
int idx[MAX][MAX];
pair<int,int>arr[500*501];

int pre(int n,int m)
{
    int tk=0;int cnt=0;
    FOR(i,0,n)FOR(j,0,m)
    {
        idx[i][j]=tk;tk++;
        if(grid[i][j]!=idx[i][j]) cnt++;
    }
    return cnt;
}


int FindDis(int n)
{
    int l=n*n;
    for(int i=0;i<l;i++)
    {
        int k1=arr[i].fs;
        int k2=arr[i].sc;
        int tidx=k1*n+k2;
        if(tidx!=i) return i;
    }
    return -1;
}

int main()
{
    #ifdef ENAM
    	fread;
	fwrite;
#endif // ENAM
    int t,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);

        int x;
        FOR(i,0,n)FOR(j,0,n)
        {
            scanf("%d",&x);
            arr[x]=mp(i,j);
            grid[i][j]=x;
        }
        int disorder=pre(n,n);

        //cout<<"DIS: "<<disorder<<endl;

        int cnt=0;
        while(disorder)
        {
            int i=arr[0].fs;
            int j=arr[0].sc;
            int tidx=(i*n+j);

          // cout<<i<<" "<<j<<" "<<tidx<<endl;
            int now=idx[i][j];

            if(now!=0)
            {
               // cout<<"Just Swap"<<endl;
                arr[0]=arr[now];
                arr[now]=mp(i,j);
                cnt++;
                disorder--;
            }
            else
            {
                int tk=FindDis(n);

                //cout<<"TK: "<<tk<<endl;
                if(tk==-1) break;

                //cout<<"aslam: "<<tk<<endl;
                arr[0]=arr[tk];
                arr[tk]=mp(i,j);
                cnt++;
            }
           // cout<<"Disorder: "<<disorder<<endl;int x;cin>>x;

        }
        printf("Case %d: %d\n",++cas,cnt);
    }
    return 0;
}


/**

2
3
7 2 4
5 0 6
8 3 1

2
3 0
1 2

3
0 3 4
1 2 8
6 7 5

4
0 1 2 3
4 5 6 7
8 9 10 11
12 14 13 15


**/


