/**
* H:\Dropbox\Code\Codeforces\Valentine Algorithm cUp 2015\val\A.cpp
* Created on: 2015-02-13-22.09.58, Friday
* Verdict: Not Solved
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

//map<int,char>n2c;
//map<char, int> c2n;


int main()
{
#ifdef ENAM
//    	fread;
	fwrite;
#endif // ENAM
    int t, n, m, cas=1;
    _
	char ch;
//	n2c[0] = 'z';
//	n2c['z'] = 0;
//	for (int i = 1; i<10; i++)
//    {
//        ch = '0'+i;
//        n2c[i] = ch;
//        c2n[ch] = i;
//    }
//
//	for (int i = 10; i<31; i++)
//    {
//        ch = ('a'+i-10);
//        n2c[i] = ch;
//        c2n[ch] = i;
//    }

    cout<<"N 31"<<"\n";
    cout<<"I 31"<<"\n";
    cout<<"A 1 31"<<"\n";

	for (int i = 1; i<=31; i++)
        for (int j = 0; j<10; j++)
        {
            int u = (i*10+j)%31;
            u = (u==0?31:u);
            cout<<"E "<<i<<" "<<j<<" "<<u<<"\n";
        }



   return 0;
}
