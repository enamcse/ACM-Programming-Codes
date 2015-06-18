/**
* H:\Dropbox\Code\Codeforces\538B.cpp
* Created on: 2015-04-26-21.49.01, Sunday
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
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e18)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
using namespace std;
int ans[50];
int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1,now=0,k=1;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    string s;
    cin>>s;
    n = s.size();
    m=0;
    for (int i = 0; i<n; i++)
        now = max(now,s[i]-'0');

    if(now==0)
    {

        cout<<"1\n0";
        return 0;
    }

    clr(ans,0);

    for (int i = n-1; i>=0; i--)
    {
        m=0;
        while(s[i]!='0')
        {
//            cout<<m<<" KK "<<k<<endl;
            ans[m++]+=k;
            s[i]--;
        }
        k*=10;
    }

    cout<<now<<"\n";

    for (int i = 0; i<now; i++)
        cout<<ans[i]<<" \n"[i==now-1];



//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
