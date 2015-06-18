/**
* H:\Dropbox\Code\Codeforces\538C.cpp
* Created on: 2015-04-26-21.49.23, Sunday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define SZ(a) ((int)a.size())
#define sz 100005
#define pb(a) push_back(a)
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e18)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))

using namespace std;

ll d[sz], h[sz];

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1,x,y;
    ll ans=0, now, hacked;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    cin>>n>>m;

    for (int i = 0; i<m; i++)
    {
        cin>>d[i]>>h[i];
        ans = max(  h[i], ans);
    }

    ans = max(ans, (h[0]+d[0]-1));

    for (int i = 1; i<m; i++)
    {
        now = max(h[i],h[i-1]);
        hacked = ( (d[i]-d[i-1]) - abs(h[i]-h[i-1]) );
        if(hacked<0)
        {
            cout<<"IMPOSSIBLE";
            return 0;
        }
        ans = max(ans, now +( hacked/2LL));
    }

    ans = max(ans, (ll) (h[m-1]+n-d[m-1]));

    cout<<ans;

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
