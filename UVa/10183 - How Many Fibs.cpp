/**
* H:\Dropbox\Code\UVa\10183 - How Many Fibs.cpp
* Created on: 2015-09-18-23.57.24, Friday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define SZ(a) ((int)a.size())
#define sz 200005
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
#define cspf printf("Case %d:", cas++);
#define csco cout<<"Case "<<cas++<<":";
#define mod 1000000007
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

vector<string>v;
char sum[2][105];

bool stringAdd(bool now)
{
    int carry = 0, su;
    for (int i = 100; i>=0; i--)
    {
        su = (sum[now^1][i]-'0') + (sum[now][i]-'0') + carry;
        carry = su/10;
        sum[now^1][i] = (su%10+'0');
    }
    if(carry) return false;
    v.pb(sum[now^1]);
    return true;
}

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1;
    bool now=false;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    for (int i = 0; i<=100; i++)
        sum[0][i]=sum[1][i]='0';
    sum[0][101]=sum[1][101]=0;
    sum[0][100] = '2';
    sum[1][100] = '1';
    v.pb(sum[1]);
    v.pb(sum[0]);
    int len=101;
    string s1,s2;
    while(stringAdd(now)) now^=1;
//    for (auto s:v)
//        cout<<s<<endl;

//    cout<<v.size()<<endl;

    while(cin>>s1>>s2)
    {
        if(s1[0]=='0'&&s2[0]=='0') return 0;
        s1=string(len-s1.size(),'0')+s1;
        s2=string(len-s2.size(),'0')+s2;

        cout<<upper_bound(all(v),s2)-lower_bound(all(v),s1)<<"\n";
    }


//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
