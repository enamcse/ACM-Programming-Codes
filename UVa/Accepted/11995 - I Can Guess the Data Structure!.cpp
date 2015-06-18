/* 
* @Author: Enamul Hassan
* @Date:   2015-04-04 01:15:21
* @Last Modified by:   Enamul
* @Last Modified time: 2015-04-04 01:43:12
* @Verdict: Solved
* @File Path: H:\Dropbox\Code\UVa\Accepted\11995 - I Can Guess the Data Structure!.cpp
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
using namespace std;


struct data{
	int x;
	data(){}
	data(int _x)
	{
		x = _x;
	}
	bool operator < (const data &p) const
    {
        return x < p.x;
    }
};

int main(){
	#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int  n, x,y;
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    bool s, q, pq;

    while(~scanf("%d", &n))
    {
    	s = q = pq = true;
    	queue<int>qq;
		stack<int>st;
		priority_queue<data>pqq;

    	for (int i = 0; i < n; ++i)
    	{
    		scanf("%d %d", &x, &y);
    		if(x==1)
    		{
    			qq.push(y);
    			st.push(y);
    			pqq.push(y);
    		}
    		else
    		{
    			if(qq.empty())
    			{
    				s = q = pq = false;
    				continue;
    			}


    			if(st.top()!=y) s = false;
    			if(qq.front()!=y) q = false;
    			if(pqq.top().x!=y) pq = false;


    			st.pop();qq.pop();pqq.pop();
    		}
    	}

    	x = 0;
    	if(s) x++;
    	if(q) x++;
    	if(pq) x++;

    	if(x>1) printf("not sure\n");
    	else if(x==1)
    	{
    		if(s) printf("stack\n");
    		else if(q) printf("queue\n");
    		else if(pq) printf("priority queue\n");
    	}
    	else printf("impossible\n");
    }
	


//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}












