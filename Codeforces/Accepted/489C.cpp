/**
* H:\Dropbox\Code\Codeforces\489C.cpp
* Created on: 2015-06-07-20.35.09, Sunday
* Verdict: Solved
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
#define cspf printf("Case %d:", cas++);
#define csco cout<<"Case "<<cas++<<":";
#define mod 1000000007
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, s, m, cas=1;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    string a, b;
    cin>>m>>s;

    if(s==0)
    {
        if(m>1) cout<<"-1 -1";
        else cout<<"0 0";
    }
    else if(m*9<s) cout<<"-1 -1";
    else
    {

        a="";
        for (int i =0; i<m; i++)
            a+="0";
        a[0]='1';
        b=a;
        b[0]='0';
        t=s;
        for(int i = 0;t;i++)
            if(t>=9) b[i]='9',t-=9;
            else
                b[i]+=t,
                t=0;

        t=s-1;
        for(int i = m-1;t;i--)
            if(t>=9) a[i]='9',t-=9;
            else a[i]+=t,
                t=0;

        cout<<a<<" "<<b;

    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}