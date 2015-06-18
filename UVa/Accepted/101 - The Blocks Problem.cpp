/*
* @Author: Enamul Hassan
* @Date:   2015-04-17 09:29:04
* @Last Modified by:   Enamul
* @Last Modified time: 2015-04-18 11:56:31
* @Verdict: Solved
* @File Path: H:\Dropbox\Code\UVa\101 - The Blocks Problem.cpp
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 200005
#define pb(a) push_back(a)
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)

using namespace std;

vector<int> v[sz], work;
int arr[sz];

int get_pos(int x, int y)
{
	for (int i = 0; i < v[ y ].size(); ++i)
		if (v[ y ][i] == x) return i;
}

void erase_rest(int i, int y)
{
	int m, len = v[ y ].size()-i;
	while (len--)
	{
		m = v[y][i];
		v[y].erase(v[y].begin()+i);
		v[m].pb(m);
		arr[m]=m;
	}
}

void move_rest(int i, int y,int q)
{
	int m, len = v[ y ].size()-i;
	while (len--)
	{
		m = v[y][i];
		v[y].erase(v[y].begin()+i);
		v[q].pb(m);
		arr[m]=q;
	}
}

void move_onto(int x, int p)
{
	int y = arr[x]; 
	int i = get_pos(x,y);
	// cerr<<" i = "<<i<<endl;
	erase_rest(i+1,y);
	int q = arr[p];
	int j = get_pos(p,q);
	erase_rest(j+1,q);
	y = arr[x]; 
	i = get_pos(x,y);
	v[q].pb(x);
	v[y].erase(v[y].begin()+i);
	arr[ x ] = q;
}

void move_over(int x, int p)
{
	int y = arr[x]; 
	int i = get_pos(x,y);
	erase_rest(i+1,y);
	int q = arr[p];
	v[q].pb(x);
	v[y].erase(v[y].begin()+i);
	arr[ x ] = q;
}

void pile_onto(int x, int p)
{
	int q = arr[p];
	int j = get_pos(p,q);
	erase_rest(j+1,q);

	int y = arr[x]; 
	int i = get_pos(x,y);
	move_rest(i,y,q);
}

void pile_over(int x, int p)
{
	int y = arr[x]; 
	int i = get_pos(x,y);
	int q = arr[p];
	move_rest(i,y,q);
}

int main() {
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
	int n, a, b;
	string s, ss;
	_
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

	// cin>>n;
	while (cin >> n)
	{
		for (int i = 0; i < n; ++i)
		{
			arr[i] = i;
			v[i].clear();
			v[i].pb(i);
		}

		while (cin >> s)
		{
			// cerr<<"s = "<<s;
			if (s == "quit") break;
			cin >> a >> ss >> b;
			// cerr<<", a = "<<a<<", b = "<<b<<", ss = "<<ss<<endl;
			if (arr[a]==arr[b]) continue;
			if (s == "move")
			{
				if (ss == "onto") move_onto(a,b);
				else move_over(a,b);
			}
			else
			{
				if (ss == "onto") pile_onto(a,b);
				else pile_over(a,b);
			}
		}


		for (int i = 0; i < n; ++i)
		{
			cout<<i<<":";
			for (int j = 0; j < v[i].size(); ++j)
			{
				cout<<" "<<v[i][j];
			}
			cout<<"\n";
		}
	}

	


//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

	return 0;
}












