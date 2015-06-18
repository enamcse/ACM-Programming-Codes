/**
* H:\Dropbox\Code\Codeforces\519A.cpp
* Created on: 2015-02-28-18.42.03, Saturday
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
map<char,int>mpp;

int w, b;
int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM

string s[10];


mpp['q'] = 9;
mpp['r'] = 5;
mpp['b'] = 3;
mpp['n'] = 3;
mpp['p'] = 1;
mpp['k'] = 0;
    int t, n, m, cas=1;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    for (int i = 0; i<8; i++)
        cin>>s[i];

    n = s[0].size();

    for (int i = 0; i<8; i++)
        for (int j = 0; j<n; j++)
            if(s[i][j]<='z'&&s[i][j]>='a') b+=mpp[s[i][j]];
    for (int i = 0; i<8; i++)
        for (int j = 0; j<n; j++)
            if(s[i][j]<='Z'&&s[i][j]>='A') w+=mpp[tolower(s[i][j])];

    if(w>b) cout<<"White";
    else if(w<b) cout<<"Black";
    else cout<<"Draw";

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
