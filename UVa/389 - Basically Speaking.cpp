/**
* H:\Dropbox\Code\UVa\389 - Basically Speaking.cpp
* Created on: 2015-02-24-16.27.35, Tuesday
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

string s;
int b1,b2;
int digits[10];

ll powers[20][10];

map<int,char>mp1;
map<char,int>mp2;

void b2b()
{
    ll now=0;
    int n = s.size(),k=0;
    for (int i = 0; i<n; i++)
        now+=(mp2[ s[i] ]*powers[b1][n-i-1]);
    while(now)
    {
        digits[ k++ ] = now%b2;
        now/=b2;
        if(k>=8) {s="  ERROR"; return;}
    }
    s="       ";
    k=max(k,1);
    for (int i=0; i<k; i++)
        s[6-i]=mp1[ digits[i] ];
        return;
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

    for (int i = 0; i<10; i++)
        mp1[i]=i+'0', mp2[i+'0']=i;

    mp1[10]='A';mp2['A']=10;
    mp1[11]='B';mp2['B']=11;
    mp1[12]='C';mp2['C']=12;
    mp1[13]='D';mp2['D']=13;
    mp1[14]='E';mp2['E']=14;
    mp1[15]='F';mp2['F']=15;

    for (int i = 2; i<18; i++)
    {
        powers[i][0]=1;
        for (int j = 1; j<10; j++)
            powers[i][j]=(powers[i][j-1]*i);
    }


    while(cin>>s>>b1>>b2)
    {
        clr(digits,0);
        b2b();
        cout<<s<<"\n";


    }


//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
/**
9999999 16 16
      0 10 12
    000 10 12
0000000 10 12
     FF 16  2
*/
