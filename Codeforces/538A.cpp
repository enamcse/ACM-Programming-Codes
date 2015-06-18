/**
* H:\Dropbox\Code\Codeforces\538A.cpp
* Created on: 2015-04-26-21.48.46, Sunday
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

string k = "CODEFORCES",s1,s2;
int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    string s;

    cin>>s;

    n= s.size();

    if(n<10)
    {
        cout<<"NO";
        return 0;
    }

    if(s.substr(n-10,10)==k || s.substr(0,10)==k)
    {
        cout<<"YES";
        return 0;
    }

    m=0;
    for (int i = 1; i<10; i++)
    {
        s1 = k.substr(0,i);
        s2 = k.substr(i,n-i);
//        cerr<<s1<<" KK "<<s2<<"\n";
        if(s1==s.substr(0,i) && s2 == s.substr(n-10+i,10-i))
        {
            cout<<"YES";
            return 0;
        }

    }

    cout<<"NO";

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
