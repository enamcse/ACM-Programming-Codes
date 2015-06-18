/**
* H:\Dropbox\Code\Codeforces\534D.cpp
* Created on: 2015-04-13-00.00.26, Monday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define SZ(a) ((int)a.size())
#define sz 200005
#define pb(a) push_back(a)
#define pp pop_back
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
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;
queue<int>adj[sz];
vector<int> ans;

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1, k;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    cin>>n;
    k=n;
    for (int i = 1; i<=n; i++)
    {
        cin>>m;
        adj[m].push(i);
    }
    bool flag = false;
    while(1)
    {
        for (int i = 0; i<n; i++)
        {
            if(!adj[i].empty())
            {
                ans.pb(adj[i].front());
                adj[i].pop();
            }
            else
            {
                i-=3;
                if(i<0)
                {
                    flag = true;
                    break;
                }
                while(adj[i].empty())
                {
                    i-=3;
                    if(i<0)
                    {
                        flag = true;
                        break;
                    }
                }
                if(flag) break;
                ans.pb(adj[i].front());
                adj[i].pop();
            }
            if(flag) break;
        }
        if(flag) break;
    }

    if(ans.size()!=n) cout<<"Impossible";
    else
    {
        cout<<"Possible\n";
        for (int i = 0; i<n; i++)
            cout<<ans[i]<<" \n"[i==n-1];
    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
