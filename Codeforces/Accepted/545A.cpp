/**
* H:\Dropbox\Code\Codeforces\545A.cpp
* Created on: 2015-05-19-22.24.12, Tuesday
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

int mat[105][105];

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1,k;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    vector<int>ans;
    cin>>n;

    for (int i = 0; i<n; i++)
    {
        k = 0;
        for (int j = 0; j<n; j++)
        {
            cin>>m;
            if(i!=j)k|=m;
        }
        if(!(k&1)) ans.pb(i+1);
    }

    n = ans.size();
    cout<<n<<"\n";

    for (int i =0; i<n; i++)
        cout<<ans[i]<<" \n"[i==n-1];

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
