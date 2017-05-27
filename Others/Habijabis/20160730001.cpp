/**
* E:\Dropbox\Code\Others\Habijabis\20160730001.cpp
* Created on: 2016-07-30-19.25.18, Saturday
* Verdict: Not Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define SZ(a) ((ll)a.size())
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
#define csco cout<<"Case "<<cas++<<": ";
#define mod 1000000007

#ifdef ENAM
#define deb(args...) {dbg,args; cerr<<endl;}
#else
#define deb(args...)
#endif

ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;
//#undef ENAM
//#include "temp.hpp"

int pat2num(string s)
{
    int ret = 0,now=0, kk =0;
    for (int i = s.size()-1; i>=0; i--)
    {
        kk=0;
        if(s[i] == 'G' || s[i] =='T') kk|=2;
        if(s[i] == 'C' || s[i] =='T') kk|=1;
        ret|=(kk<<now);
        now+=2;
    }
    return ret;
}

string num2pat(int num, int k)
{
    string s = "";
    int tem=0;
    for (int i = 0; i<k; i++)
    {
        tem = num&3;
        if(tem==0) s+='A';
        else if(tem==1) s+='C';
        else if(tem==2) s+='G';
        else s+='T';
        num>>=2;
    }
    reverse(s.begin(),s.end());
    return s;
}
int find_min(int x, int k) ///should be made more by bit manipulation
{
    int act = x;
    int rev_comp = 0;
    for (int i = 0; i<k; i++)
    {
        rev_comp<<=2;
        rev_comp|=( (x&3)^3);
        x>>=2;
    }
    return min(rev_comp, act);
}
int main()
{
#ifdef ENAM
//      fread;
//  fwrite;
#endif // ENAM
	_
	int cas = 1,t,n,m,x,y;
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    int32_t a;
    int64_t b;
    size_t c;
    a  = 1000;
    b = 1000;
    c= 35000;
    cout<<(a)<<" "<<(b)<<" "<<(c)<<endl;
    cout<<sizeof(a)<<" "<<sizeof(b)<<" "<<sizeof(c)<<endl;

//    string s = "GAAGCTT";
//    n = pat2num(s);
//    n = find_min(n,7);
//    cout<<n<<" "<<num2pat(n,7)<<endl;
//    char const *st = (char*)strdup((char*)s.c_str());
//    cout<<st<<endl;
//    short int i;           // a signed short integer
//   short unsigned int j;  // an unsigned short integer
////    cout<<s<<endl;
////    return 0;
//   j = 50000;
//
//   i = j;
//   cout << i << " " << j <<endl;
//
//     short int z = 50000;
//   cout << z ;

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
