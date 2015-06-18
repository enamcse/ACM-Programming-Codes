/* 
* @Author: Enamul Hassan
* @Date:   2015-04-06 00:09:00
* @Last Modified by:   Enamul
* @Last Modified time: 2015-04-06 00:59:31
* @Verdict: Solved
* @File Path: H:\Dropbox\Code\Codeforces\28B.cpp
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)


using namespace std;

bool mat[105][105];

int arr[105];

int main(){
	#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int  n, m, p, q;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();


	cin>>n;


	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}

	for (int i = 1; i <= n; ++i)
	{
		cin>>m;
		p = i+m;
		q = i-m;
		if(1<=p&&p<=n)
		{
			mat[ i ][p]=1;
			mat[ p ][i]=1;
		}
		if(1<=q&&q<=n)
		{
			mat[ i ][q]=1;
			mat[ q ][i]=1;
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		mat[i][i]=1;
	}

	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				mat[i][j] |= (mat[i][k]&mat[k][j]); 


	for (int i = 0; i < n; ++i)
	{
		if(!mat[ i+1 ][ arr[i] ])
		{
			cout<<"NO";
			return 0;
		}
	}

	cout<<"YES";
	

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}












