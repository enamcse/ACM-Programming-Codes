/* 
* @Author: Enamul Hassan
* @Date:   2015-03-25 00:08:15
* @Last Modified by:   Enamul
* @Last Modified time: 2015-03-25 01:53:15
* @Verdict: Solved
* @File Path: H:\Dropbox\Code\lightoj\1105 - Fi Binary Number.cpp
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define clr(abc,z) memset(abc,z,sizeof(abc))

using namespace std;

ll dp[100][2];
int lim;

ll rec(int pos, int pre)
{
	if (pos>=lim)
	{
		return 1;
	}
	ll &ret = dp[pos][pre];
	if(ret!=-1) return ret;
	ret = rec(pos+1,0);
	if(pre==0) ret+=rec(pos+1,1);

	return ret;
}

void path(int pos, int n, bool flag)
{

	if(pos>=lim||n==0) return;
	
	if(rec(pos+1,0)>=n)
	{
		if(flag) printf("0");
		path(pos+1,n,flag);
		return;
	}
	printf("1");
	path(pos+1,n-dp[pos+1][0],1);
}

int main(){
	#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, cas=1;
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    clr(dp,-1);
    lim = 45;
    rec(0,0);
	// cerr<<<<endl;
    scanf("%d", &t);
    
    while(t--)
    {
    	scanf("%d", &n);
    	printf("Case %d: ", cas++);
    	path(0,n+1,0);
    	puts("");
    }
	


//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}












