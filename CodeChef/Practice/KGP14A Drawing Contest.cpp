/**
* H:\Dropbox\Code\CodeChef\Practice\KGP14A Drawing Contest.cpp
* Created on: 2015-03-05-03.35.16, Thursday
* Verdict: Solved
* Author: Enamul Hassan
* Problem link: http://www.codechef.com/problems/KGP14A
* Concept: Sorting both height of kids and length of pencils array, we
           would take the sum of all absolute differences between hi
           and li where i = 1,2,...,n. Because, every kids have to assign
           a pencil and the number of kids and the number pencils are same.
           This would be the optimal, because if we don't take the ith
           pencil for ith kids after sorting then absolute differences would
           be increase, because it would be taken by the jth kids having
           larger absolute difference.
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 200005
#define pb(a) push_back(a)
#define all(a) a.begin(),a.end()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)

using namespace std;

vector<ll>v,vv;

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    ll t, n, m, ans,cas=1;
    cin>>t;
    while(t--)
    {
        v.clear();
        vv.clear();
        ans = 0;
        cin>>n;

        for (int i  = 0; i<n; i++)
        {
            cin>>m;
            v.pb(m);
        }
        for (int i = 0; i<n; i++)
        {
            cin>>m;
            vv.pb(m);
        }

        sort(all(v));
        sort(all(vv));

        for (int i = 0; i<n; i++)
            ans+=abs(v[i]-vv[i]);
        cout<<"Case "<<cas++<<": "<<ans<<"\n";
    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
