/**
* H:\Dropbox\Code\CodeChef\Snack Down 2015\Round 1C\B.cpp
* Created on: 2015-06-07-22.49.11, Sunday
* Verdict: Not Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define SZ(a) ((int)a.size())
#define sz 200005
#define pb(a) push_back(a)
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
#define cspf printf("Case %d:", cas++);
#define csco cout<<"Case "<<cas++<<":";
#define mod 1000000007
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

map<int,int>mp;

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1,k,mx,mn, mx2, mn2;
    vector<int> mxv, mnv;
    vector<int> mxv2, mnv2;
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    scanf("%d", &t);


    while(t--)
    {
        mp.clear();
        mxv.clear();
        mxv2.clear();
        mnv.clear();
        mnv2.clear();
        scanf("%d", &n);
        m = (n<<1)-4;
        for (int i = 0; i<m; i++)
        {
            scanf("%d", &k);
            mp[k]++;
        }

        if(n==3)
        {
            cout<<"none\n3 1\n2 1\n";
            continue;
        }
        mx = mx2 = 0;
        mn = mn2 = 1e9;
        for (auto x : mp )
        {
            if(x.first>mx)
            {
                mxv2 = mxv;
                mx2 = mx;
                mx = x.first;
                mxv.clear();
                mxv.pb(x.second);
            }
            else if(x.first == mx)mxv.pb(x.second);
            else if(x.first == mx2)mxv2.pb(x.second);

            if(x.first<mn)
            {
                mnv2 = mxv;
                mn2 = mx;
                mn = x.first;
                mnv.clear();
                mnv.pb(x.second);
            }
            else if(x.first == mn)mnv.pb(x.second);
            else if(x.first == mn2)mnv2.pb(x.second);
        }


        if(mx==mn)
        {
            cout<<"both\n";
            cout<<v[0]<<" "<<n<<"\n";
            cout<<v[0]<<" "<<n-1<<"\n";
        }
        else if(mp[n]!=mx &&mp[n-1]!=mx && mp[n]!=mn &&mp[n-1]!=mn)
        {
            cout<<"both\n";
            cout<<v[0]<<" "<<n<<"\n";
            cout<<v[0]<<" "<<n-1<<"\n";
        }
        else if( mp[n]==mx &&mp[n-1]==mx)
        {
            if(mxv.size()>=3)
            {
                cout<<"both\n";

                for (int i = 0; ; i++)
                    if(mxv[i]<n-1) break;
                cout<<mxv[i]<<" "<<n<<"\n";
                cout<<mxv[i]<<" "<<n-1<<"\n";
            }
            else
            {
                if(mx-mx2==1)
                {
                    if(mxv2.size()>1)
                }
            }
        }

    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}