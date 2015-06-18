/* 
* @Author: Enamul Hassan
* @Date:   2015-05-02 05:16:10
* @Last Modified by:   Enamul
* @Last Modified time: 2015-05-02 05:32:09
* @Verdict: Solved
* @File Path: H:\Dropbox\Code\UVa\541 - Error Correction.cpp
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

bool mat[105][105];
int main(){
	#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int n, x,y,col,row;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    bool r,c;

	while(cin>>n&&n)
	{
		x=y=-1;
		col=row=0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin>>mat[i][j];
			}
		}

		for (int i = 0; i < n; ++i)
		{
			r=c=0;
			for (int j = 0; j < n; ++j)
			{
				r^=mat[i][j];
				c^=mat[j][i];
			}
			if(r)
			{
				row++;
				x=i+1;
			}
			if(c)
			{
				col++;
				y=i+1;
			}
		}

		if(!row&&!col) cout<<"OK\n";
		else if(row==1&&col==1) cout<<"Change bit ("<<x<<","<<y<<")"<<"\n";
		else cout<<"Corrupt\n";

	}


//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}












