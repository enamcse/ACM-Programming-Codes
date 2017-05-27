/**
* E:\Dropbox\Code\CodeChef\Intra AUST Programming Contest Fall 2015\AUSASA.cpp
* Created on: 2016-01-22-19.03.57, Friday
* Verdict: Solved
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
#define fread freopen("input.txt","r",stdin)
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

int arr[sz];

int main()
{
#ifdef ENAM
//      fread;
//  fwrite;
#endif // ENAM
	_

	int n,k,t,m,s,cur,mn,tmp;
    cin>>t;

    while(t--)
    {
        s=0;
        cin>>n>>k;
        for (int i = 0; i<n; i++)
        {
            cin>>arr[i];
        }
        while(k>0&&s<n)
        {
            mn = arr[s];
            cur=s;
            for (int i = 0; i<=k&&i+s<n; i++)
            {
                if(mn>arr[i+s])
                {
                    mn = arr[i+s];
                    cur=i+s;
                }
            }
//            cerr<<s<<" : "<<cur<<" k = "<<k<<endl;
            for(int i = cur;i>s; i--)
                swap(arr[i],arr[i-1]);

            tmp=cur-s;
            k-=tmp;
            if(tmp==0)s++;
            else s = 0;
        }
        for (int i = 0; i<n; i++)
        {
            cout<<arr[i]<<" \n"[i==n-1];
        }
    }


//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
