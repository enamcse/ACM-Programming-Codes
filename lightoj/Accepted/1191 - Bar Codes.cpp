/* 
* @Author: Enamul Hassan
* @Date:   2015-03-26 00:59:21
* @Last Modified by:   Enamul
* @Last Modified time: 2015-03-26 04:23:34
* @Verdict: Solved
* @File Path: H:\Dropbox\Code\lightoj\1191 - Bar Codes.cpp
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define clr(abc,z) memset(abc,z,sizeof(abc))
using namespace std;

ll dp[60][60][60];
int m,k,n;

ll rec(int pos, int bar)
{
	if(pos<0||bar<0) return 0;
	if(pos==0) return !bar;
	ll &ret = dp[pos][bar][m];
	if(ret!= -1 ) return ret;
	ret = 0;
	for (int i = 1; i <= m; ++i)
		ret+=rec(pos-i,bar-1);
	return ret;
}

int main(){
	#ifdef ENAM
//    	fread;
	// fwrite;
#endif // ENAM
    int t,  cas=1;
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

	scanf("%d", &t);
	clr(dp,-1);
	while(t--)
	{
		scanf("%d %d %d",&n, &k, &m);
		printf("Case %d: %lld\n",cas++, rec(n,k));
	}

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}












