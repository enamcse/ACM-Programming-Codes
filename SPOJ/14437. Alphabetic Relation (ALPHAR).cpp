/**
* H:\Dropbox\Code\SPOJ\14437. Alphabetic Relation (ALPHAR).cpp
* Created on: 2015-01-06-21.45.14, Tuesday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <iostream>
#include <string>
#include <assert.h>
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

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1, k;
    _
	string s;
	char c;
	cin>>t;

	while(t--)
    {
        cin>>s>>c;
        assert(c>='A'&&c<='G');
        k = c-s[0];

        if(k<0) k+=7;
        for (int i = 0; i<s.size(); i++)
        {
            assert(s[i]>='A'&&s[i]<='G');
            s[i] = (s[i]-'A'+k)%7+'A';
        }

        cout<<"Case "<<cas++<<": "<<s<<"\n\n";
    }


   return 0;
}
