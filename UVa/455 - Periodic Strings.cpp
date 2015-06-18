/* 
* @Author: Enamul Hassan
* @Date:   2015-04-16 15:38:43
* @Last Modified by:   Enamul
* @Last Modified time: 2015-04-16 16:04:51
* @Verdict: Solved
* @File Path: H:\Dropbox\Code\UVa\455 - Periodic Strings.cpp
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
using namespace std;

int main(){
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
    cin>>t;

    while(t--)
	{
		cin>>s;
		n = s.size();
		for (int i = 1,j; i <=n; ++i)
		{
			if(n%i)continue;
			for (j = 0; j < n; j+=i)
				if(s.substr(0,i)!=s.substr(j,i)) break;

			if(j>=n) {m = i;break;}
		}
		cout<<m<<"\n";
		if(t)cout<<"\n";
	}


//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}












