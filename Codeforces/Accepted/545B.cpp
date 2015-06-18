/**
* H:\Dropbox\Code\Codeforces\545B.cpp
* Created on: 2015-05-19-22.24.34, Tuesday
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

using namespace std;

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int k, n, m, cas=1;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    string s,t,p;
    cin>>s>>t;

    n =s.size();
    m=0;
    for (int i = 0; i<n; i++)
        if(s[i]!=t[i]) m++;

    if(m%2)
    {
        cout<<"impossible";
    }
    else
    {
        p = t;
        m>>=1;
        k=0;
        for (int i = 0; i<n&&k<m; i++)
        {
            if(s[i]!=t[i])
            {
                p[i] = s[i];
                k++;
            }
        }
        cout<<p;
    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
