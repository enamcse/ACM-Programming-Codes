/**
* H:\Dropbox\Code\DevSkill\Dev Skill Coding Contest - 2\F.cpp
* Created on: 2015-03-14-21.44.34, Saturday
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
#define fread freopen("in.txt","r",stdin)
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
    	fread;
	fwrite;
#endif // ENAM
    int t, n, m, cas=1, p;
    char ch;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    cin>>t;
    string s;

    while(t--)
    {
        cin>>m;
        cin.ignore();
        getline(cin,s);
//        cout<<m<<":"<<s<<"LL"<<endl;
        p=0;
        n =s.size();
        string ans="";

        for (int i = 0; i<n; i++)
        {
            if(s[i]>='A'&&s[i]<='Z')
            {
                s[i] = tolower(s[i]);
            }
            else if((s[i]>='a'&&s[i]<='z') || (s[i]>='0'&&s[i]<='9') ) continue;
            else s[i] = '-';
        }
        bool flag =false;
        for(int i = 0;i<n;i++)
        {
            if((s[i]>='a'&&s[i]<='z') || (s[i]>='0'&&s[i]<='9'))
            {
                ans+=s[i];
                flag = true;
            }
            else if(flag)
            {
                flag = false;
                ans+=s[i];
            }
        }
//        cout<<m<<" LL: "<<s<<endl;
        if(m<ans.size())ans = ans.substr(0,m);
//        cout<<m<<" LL: "<<s<<endl;

        n =s.size();

        if(ans[ans.size()-1]=='-') ans = ans.substr(0,ans.size()-1);

//        if(ans.size()>m)
//        {
//            if(ans[m-1]=='-') ans = ans.substr(0,m-1)+ans[m];
//            else ans = ans.substr(0,m);
//        }
        cout<<ans<<"\n";
    }



//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}