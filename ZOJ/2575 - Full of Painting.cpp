/* 
* @Author: Enamul Hassan
* @Date:   2015-03-22 00:51:37
* @Last Modified by:   Enamul
* @Last Modified time: 2015-03-22 01:46:46
* @Verdict: Solved
* @File Path: H:\Dropbox\Code\ZOJ\2575 - Full of Painting.cpp
* @Comment: This problem gives WA if does not output 3 digits after decimal point.
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define pb(a) push_back(a)
#define all(a) a.begin(),a.end()
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e18)
#define clr(abc,z) memset(abc,z,sizeof(abc))
using namespace std;

int n, m,minI[10], maxI[10];
double  dp[10][500];
vector<double>price;
bool visited[10][500];

double rec(int pos, int rest)
{
	if(pos==n&&!rest) return 0.0;
	if(pos==n||rest<0) return inf;
	double &ret = dp[pos][rest];
	if(visited[pos][rest]) return ret;
	visited[pos][rest] = true;
	ret = inf;
	for (int i = minI[pos]; i <= maxI[pos]; ++i)
	{
		/* code */
		double now = rec(pos+1,rest-i)+price[pos]*i*i;
		ret = min(ret,now);
	}

	return ret;
}

int main(){
	#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    double in;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    while(cin>>n>>m)
    {
    	price.clear();
    	for (int i = 0; i < n; ++i)
    	{
    		/* code */
    		cin>>in;
    		price.pb(in);
    	}

    	for (int i = 0; i < n; ++i)
    	{
    		/* code */
    		cin>>minI[i]>>maxI[i];
    	}
    	clr(visited,false);
    	double ans = rec(0,m);
    	while(next_permutation(all(price)))
    	{
    		clr(visited,false);
    		ans = min(ans,rec(0,m));
    	}
    	if(ans>1e17) cout<<"Impossible\n";
    	else cout<<setprecision(3)<<fixed<<ans<<"\n";
    }
//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}