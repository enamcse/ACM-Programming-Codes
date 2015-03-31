/* 
* @Author: Enamul Hassan
* @Date:   2015-03-22 02:10:36
* @Last Modified by:   Enamul
* @Last Modified time: 2015-03-22 02:42:43
* @Verdict: Solved
* @File Path: H:\Dropbox\Code\ZOJ\2562 - More Divisors.cpp
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define pb(a) push_back(a)
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
using namespace std;

ll n;
pair<ll,ll>ans;
vector<int>primes;

void rec(int pos, ll num, ll div)
{
	if(primes[pos]*num>n)
	{
		if(ans.second<div) ans = make_pair(num,div);
		else if(ans.second==div && ans.first>num) ans = make_pair(num,div);
		return;
	}
	ll p = primes[pos];
	for (int i = 1; i < 1e9; ++i,p*=primes[pos])
	{
		/* code */
		if(p*num<=n) rec(pos+1,p*num,div*(i+1));
		else return;
	}

}


int main(){
	#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    for (int i = 2; i < 100; ++i)
    {
    	/* code */
    	int j = 2;
    	for ( ; j < i; ++j)
    	{
    		/* code */
    		if(i%j==0) break;
    	}
    	if(i==j) primes.pb(i);
    }

	while(cin>>n)
	{
		ans = make_pair(0,0);
		rec(0,1,1);
		cout<<ans.first<<"\n";
	}


//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}












