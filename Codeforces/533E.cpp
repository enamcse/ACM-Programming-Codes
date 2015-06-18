/**
* H:\Dropbox\Code\Codeforces\533E.cpp
* Created on: 2015-04-17-22.07.08, Friday
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
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

string s,s1;
int n;
bool check(int a, int b, bool f1, bool f2)
{
    if(a==n||b==n)
    {
        if(a==n&&b==n) return true;
        if(a==n&&!f2) return true;
        if(b==n&&!f1) return true;
        return false;
    }
    if(s[a]==s1[b]) return check(a+1,b+1,f1,f2);
    if(s[a]==s1[b+1]&&!f2)return check(a+1,b+2,f1,true);
    if(s[a+1]==s1[b]&&!f1)return check(a+2,b+1,true,f2);
    return false;
}

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    cin>>n>>s>>s1;

    if(s==s1)
    {
        ll ans=26+25*n;
        cout<<ans;
    }
    else
    {
        int m = 0;
        for (int i = 0; i<n; i++)
            if(s[i]!=s1[i]) m++;
        if(m==1) cout<<2;
        else if(check(0,0,0,0)) cout<<1;
        else cout<<0;
    }



//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
