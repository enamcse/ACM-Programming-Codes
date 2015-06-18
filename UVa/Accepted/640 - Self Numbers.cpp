/* 
* @Author: Enamul Hassan
* @Date:   2015-05-03 20:08:39
* @Last Modified by:   Enamul
* @Last Modified time: 2015-05-03 20:16:04
* @Verdict: Solved
* @File Path: H:\Dropbox\Code\UVa\640 - Self Numbers.cpp
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
using namespace std;

set<int>s;

int main(){
	#ifdef ENAM
//    	fread;
	fwrite;
#endif // ENAM
    int m, n;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    for (int i = 1; i < 1000001; ++i)
    {
    	if(s.find(i)==s.end()) cout<<i<<"\n";
    	m = i;
    	n = i;
    	while(m)
    	{
    		n+=m%10;
    		m/=10;
    	}
    	s.insert(n);
    }
	


//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}












