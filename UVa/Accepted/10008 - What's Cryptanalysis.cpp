/* 
* @Author: Enamul Hassan
* @Date:   2015-05-02 06:02:09
* @Last Modified by:   Enamul
* @Last Modified time: 2015-05-02 06:19:12
* @Verdict: Solved
* @File Path: H:\Dropbox\Code\UVa\10008 - What's Cryptanalysis.cpp
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

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
#define PI acos(-1)
#define pi 3.14159265358979323846264338327950288419716939937510
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}
using namespace std;

int let[26];

bool comp(const pair<char,int> &a, const pair<char,int> &b)
{
	if(a.second!=b.second) return a.second>b.second;
	return a.first<b.first;
}

int main(){
	#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    vector< pair<char,int> > v;
    string s;
	cin>>t;
	cin.ignore();
	while(t--)
	{
		getline(cin,s);
		n = s.size();
		for (int i = 0; i < n; ++i)
			if(isalpha(s[i])) let[ toupper(s[i])-'A' ]++;
	}
	v.clear();
	for (int i = 0; i < 26; ++i)
		if(let[i])v.pb(make_pair((char)i+'A',let[i]));

	sort(all(v), comp);

	for (int i = 0; i < v.size(); ++i)
		cout<<v[i].first<<" "<<v[i].second<<"\n";


//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}











