/**
* E:\Dropbox\Code\HackerCup\2016\Facebook Hacker Cup 2016 Qualification Round\Boomerang Constellations.cpp
* Created on: 2016-01-10-16.13.10, Sunday
* Verdict: Not Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define SZ(a) ((ll)a.size())
#define sz 2005
#define pb push_back
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
#define cntbit(mask) __builtin_popcount(mask)
#define unify(a) stable_sort(a.begin(),a.end());a.resize(distance(a.begin(),unique(all(a))));
#define fread freopen("boomerang_constellations.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e18)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define pi 3.14159265358979323846264338327950288419716939937510
#define fr(i,a,b) for(i=a;i<=b;i++)
#define cspf prllf("Case %d:", cas++);
#define csco cout<<"Case "<<cas++<<":";
#define mod 1000000007

#ifdef ENAM
#define deb(args...) {dbg,args; cerr<<endl;}
#else
#define deb(args...)
#endif

ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

ll arr[sz][2];

//ll dist[sz][sz];
map<ll,ll>mpp;
ll getdist(int a, int b)
{
    return ((arr[a][0] - arr[b][0])*(arr[a][0] -arr[ b][0]) +(arr[a][1] - arr[b][1])*(arr[a][1] - arr[b][1]));
}

int main()
{
//#ifdef ENAM
      fread;
  fwrite;
//#endif // ENAM
	_
    ll t, n, x, y, m,cas=1;
    cin>>t;
    while(t--)
    {
        //cerr<<"start:"<<t<<endl;
        cin>>n;
        m = 0;
        for (int i = 0;i<n ;i++)
        {
            cin>>x>>y;
            arr[i][0]=x;
            arr[i][1]=y;
        }

//        for (int i = 0; i<n; i++)
//            for (int j = i+1; j<n; j++)
//                dist[j][i] = dist[i][j] = getdist(i,j);

        for (int i = 0; i<n; i++)
        {
            mpp.clear();
            for (int j = 0; j<n; j++)
            {
                if(i==j) continue;
                x = getdist(i,j);
                if(mpp.count(x)==0)mpp[ x ] = 0;
                mpp[ x ]++;
//                cerr<<i<<" "<<j<<": "<< dist[i][j]<<" -> "<<mpp[dist[i][j]]<<endl;
            }
            for (auto &now : mpp)
                if(now.second>1) m+=((now.second*(now.second-1))/2LL);
        }
        cout<<"Case #"<<cas++<<": "<<m<<"\n";
        //cerr<<t<<endl;
    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
