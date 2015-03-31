/**
* H:\Dropbox\Code\lightoj\1018 - Brush (IV).cpp
* Created on: 2015-02-02-04.08.19, Monday
* Verdict: Solved
* Comment: This problem gives Runtime Error while using cin/cout with sync.
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 16
#define pb(a) push_back(a)
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
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

pair<int,int>point[sz];

int parallel[sz][sz], n, nmask, dp[(1<<sz)];
bool slope(const pair<int,int> &a, const pair<int,int> &b)
{
    return !(a.first * b.second - a.second * b.first);
}

int rec(int mask)
{
    if(mask==nmask) return 0;
    int &ret = dp[mask];
    if(ret!=-1) return ret;
    ret = inf;
    if(n - __builtin_popcount(mask)<=2) return ret=1;
    for (int i = 0; i<n; i++)
        if(!(mask&(1<<i)))
        {
            for (int j = i+1; j<n; j++)
                if(!(mask&(1<<j)))
                    ret = min(ret, rec(mask|parallel[i][j])+1);
            break;
        }

    return ret;
}


int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, cas=1;
//    _
	pair<int,int>x,y;
//	cin>>t;
    scanf("%d", &t);
	while(t--)
    {
//        cin>>n;
        scanf("%d", &n);
        for (int i = 0; i<n; i++)
//            cin>>point[i].first>>point[i].second;
            scanf("%d %d", &point[i].first, &point[i].second);
        clr(parallel,0);
        clr(dp,-1);
        nmask=(1<<n)-1;
        for (int i = 0; i<n; i++)
            for (int j = i+1; j<n; j++)
                for (int k = 0; k<n; k++)
                {
                    x.first = point[i].first - point[k].first;
                    x.second = point[i].second - point[k].second;
                    y.first = point[j].first - point[k].first;
                    y.second = point[j].second - point[k].second;
                    if(slope(x,y)) parallel[i][j]|=(1<<k);
                }
//        cout<<"Case "<<cas++<<": "<<rec(0)<<"\n";
        printf("Case %d: %d\n", cas++, rec(0));
    }
   return 0;
}
