/* 
* @Author: Enamul Hassan
* @Date:   2015-05-03 19:28:36
* @Last Modified by:   Enamul
* @Last Modified time: 2015-05-03 19:51:02
* @Verdict: Solved
* @File Path: H:\Dropbox\Code\UVa\612 - DNA Sorting.cpp
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define pb(a) push_back(a)
#define all(a) a.begin(),a.end()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
using namespace std;

vector< pair<int,string> > v;

bool comp( const pair<int,string> &a, const pair<int,string> &b)
{
	return a.first<b.first;
}

int sortedness(string &s)
{
	int n = s.size(), ret = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			if(s[i]>s[j]) ret++;
		}
	}
	return ret;
}

int main(){
	#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    string s;

	cin>>t;

	while(t--)
	{
		v.clear();
		cin>>n>>m;
		for (int i = 0; i < m; ++i)
		{
			cin>>s;
			v.pb(make_pair(sortedness(s),s));
			
		}
		stable_sort(all(v), comp);
		for (int i = 0; i < m; ++i)
		{
			cout<<v[i].second<<"\n";
		}
		if(t) cout<<"\n";
	}


//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}












