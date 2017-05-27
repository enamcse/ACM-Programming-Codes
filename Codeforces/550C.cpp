/**
* E:\Dropbox\Code\Codeforces\550C.cpp
* Created on: 2016-04-02-07.39.29, Saturday
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

ll bigmod(ll sonkha,ll ghat,ll vag_const)
{
    ll vag_shesh=1;
    while(ghat>0)
    {
        if(ghat%2==1)
        {
            vag_shesh=(vag_shesh*sonkha)%vag_const;
        }
        ghat/=2;
        sonkha=(sonkha*sonkha)%vag_const;
    }
    return vag_shesh;
}
ll inverse_mod(ll bivajok, ll vag_const)
{
    return bigmod(bivajok,vag_const-2, vag_const);
}

using namespace std;

int main()
{
#ifdef ENAM
//      fread;
//  fwrite;
#endif // ENAM
    _
    int cas = 1,t,n,m,x,y,z;
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    string s;

    cin>>s;
    n = s.size();
    for (int i =0; i<n; i++)
    {
        if(s[i]=='0'||s[i]=='8')
        {
            cout<<"YES\n"<<s[i];

            return 0;
        }
    }

    for (int i =0; i<n; i++)
        for (int j = i+1; j<n; j++)
            for (int k = j+1; k<n; k++)
            {
                m = (s[i]-'0')*100+(s[j]-'0')*10+(s[k]-'0');
                if(m%8==0)
                {
                    cout<<"YES\n";
                    for (int p = 0; p<=i; p++)
                        cout<<s[p];
                    cout<<s[j]<<s[k];
                    return 0;
                }
            }

    for (int i =0; i<n; i++)
        if(s[i]!='0')
            for (int j = i+1; j<n; j++)
            {
                m = (s[i]-'0')*10+(s[j]-'0');
                if(m%8==0)
                {
                    cout<<"YES\n";
                    cout<<s[i]<<s[j];
                    return 0;
                }
            }

    cout<<"NO";


//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}
