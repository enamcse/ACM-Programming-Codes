/**
* H:\Dropbox\Code\Codeforces\556D.cpp
* Created on: 2015-06-30-15.51.45, Tuesday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 200005
#define pb push_back
#define all(a) a.begin(),a.end()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)


using namespace std;

int n, m;

set<pair<ll, pair<ll,ll> > >s;
int ans[sz];
set< pair<ll,ll> >a;
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
    ll x, y, p ,q;
    cin>>n>>m;
    cin>>p>>q;
    for (int i = 1; i<n; i++)
    {
        cin>>x>>y;
        s.insert({y-p,{x-q,i}});
        p = x, q = y;
    }

    for (int i = 0; i<m; i++)
    {
        cin>>x;
        a.insert({x,i+1});
    }

    for (auto now : s)
    {
        if(
            (a.lower_bound( {now.first , 0} )==a.end() && a.lower_bound( {now.second.first,0} )!=a.end()) ||
            ( (*a.lower_bound( {now.second.first,0} )).first < (*a.lower_bound( {now.first , 0} )).first )  ||
            ((*a.lower_bound( {now.second.first,0} )).first == (*a.lower_bound( {now.first , 0} )).first &&
             (( (*a.lower_bound( {now.second.first,0} )).first >= now.second.first) &&
              (*a.lower_bound( {now.second.first,0} )).first <= now.first)))
        {
            ans[ now.second.second ] = (*a.lower_bound( {now.second.first,0} )).second;
            a.erase( a.lower_bound( {now.second.first,0} ) );
        }
        else
        {
            cout<<"No\n";
            return 0;
        }
    }

    cout<<"Yes\n";
    for (int i = 1; i<n; i++)
        cout<<ans[i]<<" \n"[i==n-1];

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}

/**
3 2
1 5
6 12
14 100000000000
10000000000 4
*/
