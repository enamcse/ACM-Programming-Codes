/* 
* @Author: Enamul Hassan
* @Date:   2015-03-30 17:48:59
* @Last Modified by:   Enamul
* @Last Modified time: 2015-03-30 18:00:51
* @Verdict: Solved
* @File Path: H:\Dropbox\Code\lightoj\1033 - Generating Palindromes.cpp
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define clr(abc,z) memset(abc,z,sizeof(abc))
using namespace std;

int dp[105][105];
char line[105];

int rec(int start, int ending)
{
	if(start>=ending) return 0;
	int &ret = dp[start][ending];
	if(ret!=-1) return ret;
	ret = (int)INFINITY;
	if(line[start]==line[ending]) ret = min(ret,rec(start+1, ending-1));
	ret = min(ret, 1+rec(start,ending-1));
	ret = min(ret, 1+rec(start+1,ending));
	return ret;
}

int main(){
	#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, cas=1;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();


	scanf("%d", &t);

	while(t--)
	{
		clr(dp,-1);
		scanf("%s", line);
		printf("Case %d: %d\n",cas++,rec(0,strlen(line)-1));
	}


//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}












