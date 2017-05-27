/*
* @Author: Enamul Hassan
* @Date:   2015-03-24 21:58:19
* @Last Modified by:   Enamul
* @Last Modified time: 2015-03-24 23:34:05
* @Verdict: Solved
* @File Path: H:\Dropbox\Code\lightoj\1068 - Investigation.cpp
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)

#define clr(abc,z) memset(abc,z,sizeof(abc))

using namespace std;
int n, k;
char s[20];
int dp[35][90][100][2];

int rec(int pos, int digit, int sum, bool flag)
{
	if (pos == n) 
	{
		if (digit == 0 && sum  == 0) 
			return 1; 
		return 0;
	}
	int &ret = dp[pos][digit][sum][flag];
	if (ret != -1) return ret;
	ret = 0;

	int en = flag ? s[pos] - '0' : 9;
	for (int i = 0; i <= en; ++i)
	{
		/* code */
		ret += rec(pos + 1, (i + digit) % k, (sum * 10 + i) % k, flag && i == en);
	}
	return ret;
}


int main() {
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
	int t,  cas = 1, a , b, ans;

//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

	scanf("%d", &t);

	while (t--)
	{
		scanf("%d %d %d", &a, &b, &k);
		if(k>95)
		{
			printf("Case %d: %d\n", cas++, 0);
			continue;
		}
		a--;
		clr(dp, -1);
		sprintf(s, "%d", b);
		n = strlen(s);
		ans = rec(0, 0, 0, 1);

		clr(dp, -1);
		sprintf(s, "%d", a);
		n = strlen(s);
		ans -= rec(0, 0, 0, 1);
		printf("Case %d: %d\n", cas++, ans);
	}



//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

	return 0;
}