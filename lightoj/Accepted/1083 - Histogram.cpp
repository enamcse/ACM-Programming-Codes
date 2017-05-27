/**
* H:\Dropbox\Code\lightoj\1083 - Histogram.cpp
* Created on: 2015-05-28-17.41.22, Thursday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define SZ(a) ((int)a.size())
#define sz 30005
#define sz2 (sz<<2)
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
#define cp printf("Case %d: ", cas++);

using namespace std;

int  val[sz],le[sz], ri[sz];


void histogram(int n)
{
    for (int i = 1; i<=n; i++)
        le[i] = ri[i] = i;

    for (int i = 1; i<=n; i++)
    {
        while(le[i]>1 && val[ i ]<= val[le[i]-1])
            le[i]=le[le[i]-1];
    }

    for (int i = n; i>=1; i--)
    {
        while(ri[i]<n && val[ i ]<= val[ri[i]+1])
            ri[i]=ri[ri[i]+1];
    }
}


int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1, ans, l, r, ind, mid,f,s;

//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    scanf("%d", &t);

    while(t--)
    {
        ans = 0;
        scanf("%d", &n);

        for (int i = 1; i<=n; i++)
            scanf("%d", &val[i]);

        val[n+1]=-1;

        histogram(n);

        for (int i = 1; i<=n; i++)
            ans = max(ans,(ri[i]-le[i]+1)*val[i]);

        cp
        printf("%d\n", ans);
    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
