/**
* H:\Dropbox\Code\CodeChef\2014 November Challange\PRPALN Let us construct palindrome.cpp
*
* Created on: 2014-11-07-18.21.29, Friday
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
#define fwrite freopen("input.txt","w",stdout)
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
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1; while(ghat>0)  {if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;} return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const) { return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

string s;


int main()
{
    #ifdef ENAM
    	fread;
//	fwrite;
    #endif // ENAM
    _
    int t, n, m, cas=1,k,x,y;

//    for (int i = 0; i<100000; i++)
//        putchar('a');
//    return 0;

    cin>>t;


    while(t--)
    {
        cin>>s;
        m = 0;
        x = 0;
        n = s.size();
        y = n-1;

        for (; x<y&&m<=1;x++,y--)
        {
            if(s[x]==s[y]) continue;
            if(s[x]==s[y-1]) y--,m++;
            else if(s[x+1]==s[y]) x++,m++;
            else {m=51;break;}
        }

        k = m;

        m = 0;
        x = 0;
        y = n-1;

        for (; x<y&&m<=1;x++,y--)
        {
            if(s[x]==s[y]) continue;
            if(s[x+1]==s[y]) x++,m++;
            else if(s[x]==s[y-1]) y--,m++;
            else {m=51;break;}
        }

        m = min(k,m);

        if(m<=1)cout<<"YES\n";
        else cout<<"NO\n";
//        cout<<endl;


    }


    return 0;
}
