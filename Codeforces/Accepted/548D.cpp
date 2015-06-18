/**
* H:\Dropbox\Code\Codeforces\548DD.cpp
* Created on: 2015-05-26-22.31.53, Tuesday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 200005
#define pb(a) push_back(a)
#define all(a) a.begin(),a.end()
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)

using namespace std;

int  val[sz],le[sz], ri[sz], ans[sz];


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

bool comp(pair<int,int> const &a, pair<int,int> const &b)
{
    return a.first==b.first?a.second>b.second:a.first>b.first;
}

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m=1, cas=1;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    cin>>n;

    for (int i = 1; i<=n; i++) cin>>val[i];


    histogram(n);
    vector<pair<int,int>>v;
    for (int i = 1; i<=n; i++)
        v.pb(make_pair(val[i], ri[i]-le[i]+1));

    sort(all(v),comp);

    for (int i = 0; i<n; i++)
    {
        if(v[i].second>=m)
        {
            for ( ; m<=v[i].second; m++)
                ans[m]= v[i].first;
        }
    }

    for (int i = 1; i<=n; i++)
        cout<<ans[i]<<" \n"[i==n];

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
