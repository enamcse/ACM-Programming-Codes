    /**
* E:\Dropbox\Code\Others\Habijabis\20160617002_op_overload.cpp
* Created on: 2016-06-17-18.15.52, Friday
* Verdict: Not Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
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

class Number {
    int x, y;
public:
    Number(){x=0;y=0;}
    Number(int a, int b){x=a; y=b;}
    void print(){cout<<x<<" "<<y<<endl;}
    Number operator = (Number ob);
};
Number Number::operator = (Number ob){
    x = ob.x;
    y = ob.y;
}

int main()
{
    Number n1(3,6), n2(7,9), n3;

    n1.print();
    n2.print();
    n3.print();

    n3 = n1 = n2;

    n1.print();
    n2.print();
    n3.print();


    n1 = n3 = n2;

    n1.print();
    n2.print();
    n3.print();


    return 0;
}
