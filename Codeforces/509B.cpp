/**
* H:\Dropbox\Code\Codeforces\509B.cpp
* Created on: 2015-01-31-17.59.41, Saturday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 200005
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
ll bigmod(ll sonkha,ll ghat,ll vag_const)
{
    ll vag_shesh=1;
    while(ghat>0)
    {
        if(ghat%2==1)
        {
            vag_shesh=(vag_shesh*sonkha)%vag_const;
        }
        ghat/=2;
        sonkha=(sonkha*sonkha)%vag_const;
    }
    return vag_shesh;
}
ll inverse_mod(ll bivajok, ll vag_const)
{
    return bigmod(bivajok,vag_const-2, vag_const);
}

using namespace std;

int a[105],n;

int v[105][105];

bool check()
{
    for (int i = 0; i<n; i++)
        if(a[i]) return false;
    return true;
}

pair<int,int> get(int x)
{
    pair<int,int>now;
    now = make_pair(v[0][x],v[0][x]);

    for (int i = 1; i<n; i++)
    {
        now.first = min(now.first, v[i][x]);
        now.second = max(now.second, v[i][x]);
    }


    return now;
}

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, m, cas=1, k, mn=inf, col=1;
    _
    bool flag;
    cin>>n>>k;

    for (int i = 0; i<n; i++)
    {
        cin>>a[i];
        mn = min(mn,a[i]);

    }

    for (int i = 0; i<n; i++)
    {
        v[i][col]+=mn;
        a[i]-=mn;
    }

    while(col<=k)
    {
        flag = true;
        pair<int,int>x = get(col);

        for (int i = 0; i<n; i++)
            if(a[i])
            {
                if(abs(v[i][col]+1-x.first)<=1 && abs(v[i][col]+1-x.second)<=1)
                {
                    a[i]--;
                    v[i][col]++;
                    flag = false;
                }
            }

        if(check()) break;
        if(flag) col++;
    }

    if(check())
    {
        cout<<"YES\n";
        for (int i = 0; i<n; i++)
        {
            flag = false;
            for (int j = 1; j<=k; j++)
            {
                while(v[i][j]--)
                {
                    if(flag)cout<<" ";
                    cout<<j;
                    flag = true;
                }
            }
                cout<<"\n";
        }
    }
    else cout<<"NO\n";

    return 0;
}
