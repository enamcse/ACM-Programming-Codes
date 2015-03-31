/* 
* @Author: Enamul Hassan
* @Date:   2015-03-21 16:09:18
* @Last Modified by:   Enamul
* @Last Modified time: 2015-03-22 05:34:48
* @Verdict: Solved
* @File Path: H:\Dropbox\Code\ZOJ\2559 - The Smart Bomb.cpp
* @Concept: 
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define pb(a) push_back(a)
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)

using namespace std;

struct point{
	double x,y;
	point(){}
	point(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
} p[3];


double getdist(point a, point b)
{
	return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
}
vector<double> v,ans;

bool check(double n)
{
	double a = v[0] - n;
	double b = v[1] - a;
	double c = v[2] - b - n;
	// cerr<<setprecision(6)<<fixed<<n<<":"<<a<<":"<<b<<":"<<c<<endl;
	// if(a>=0&&b>=0&&c>=0&&a+b+n>ans[0]+ans[1]+ans[2])
	if(abs(c)<1e-4)
	{
		ans[0] = n;
		ans[1] = a;
		ans[2] = b;
	}

	if(c>0.0) return true;
	return false;
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

    while(cin>>p[0].x)
    {
    	cin>>p[0].y;
    	for (int i = 1; i < 3; ++i)
    	{
    		/* code */
    		cin>>p[i].x>>p[i].y;
    	}
    	v.clear();
    	ans.clear();
    	

    	for (int i = 0; i < 3; ++i)
    	{
    		/* code */
    		v.pb(getdist(p[i], p[(i+1)%3]));
    		ans.pb(0.0);
    	}
//    	sort(all(v));
    	double down = 0.0, up = v[0], mid;
    	for (int i = 0; i < 120; ++i)
    	{
    		/* code */
    		mid = (up+down)/2.0;
    		if(check(mid))
    			down = mid;
    		else up = mid;
    	}
    	cout<<setprecision(6)<<fixed<<ans[0]<<"\n";
    	cout<<setprecision(6)<<fixed<<ans[1]<<"\n";
    	cout<<setprecision(6)<<fixed<<ans[2]<<"\n";
	}


//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}












