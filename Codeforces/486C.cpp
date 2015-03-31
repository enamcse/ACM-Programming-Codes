/**
* H:\Dropbox\Code\Codeforces\486C.cpp
*
* Created on: 2014-11-11-20.48.32, Tuesday
* Author: Enamul Hassan
* Verdict: NOT SOLVED
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);


#define sz 100005
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

string s;
bool flag[sz];

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, p,m, cas=1,now, ans,pointing;
    _
    cin>>n>>p>>s;
    ans = INFINITY;
    pointing = p-1;

    now = 0;
    for (int i = 0, j = pointing; i<n; i++,j++)
    {
        if(j==n) j=0;

        if(s[j]!=s[n-1-j]&&!flag[j])
        {
            flag[j]=flag[n-1-j]=true;
            int temp = abs(p-j);
            now+=min(temp, n-temp);
            temp = abs(s[n-1-j]-s[j]);
            now+=min(temp,26-temp);
            p = j;
        }
    }
    ans=now;
    p=pointing;
    bool sign=true;
    for (int i = 0, j = pointing; i<n; i++,sign?j++:j--)
    {
        if(j==n) sign=false,i=-1;

        if(s[j]!=s[n-1-j]&&!flag[j])
        {
            flag[j]=flag[n-1-j]=true;
            int temp = abs(p-j);
            now+=min(temp, n-temp);
            temp = abs(s[n-1-j]-s[j]);
            now+=min(temp,26-temp);
            p = j;
        }
    }
    ans=min(ans,now);



    now=0;
    p=pointing;
    clr(flag, false);
    for (int i = 0, j = pointing; i<n; i++,j--)
    {
        if(j==-1) j+=n;

        if(s[j]!=s[n-1-j]&&!flag[j])
        {

            flag[j]=flag[n-1-j]=true;
            int temp = abs(p-j);

            now+=min(temp, n-temp);
            temp = abs(s[n-1-j]-s[j]);

            now+=min(temp,26-temp);
            p = j;
        }
    }
    ans=min(ans,now);

    sign=true;
    now=0;
    p=pointing;
    clr(flag, false);
    for (int i = 0, j = pointing; i<n; i++,sign?j--:j++)
    {
        if(j==-1) sign=false,i=-1;

        if(s[j]!=s[n-1-j]&&!flag[j])
        {

            flag[j]=flag[n-1-j]=true;
            int temp = abs(p-j);

            now+=min(temp, n-temp);
            temp = abs(s[n-1-j]-s[j]);

            now+=min(temp,26-temp);
            p = j;
        }
    }
    ans=min(ans,now);


    cout<<ans<<"::"<<now<<endl;
    cout<<ans;


    return 0;
}
