#include <bits/stdc++.h>

#define all(a)           a.begin(),a.end()
#define chng(a,b)       a^=b^=a^=b;
#define clr(y,z)        memset(y,z,sizeof(y))
#define cntbit(mask)     __builtin_popcount(mask)
#define CROSS(a,b,c,d) ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))
#define fr(i,a,b)       for(i=a;i<=b;i++)
#define inf             (1e9)
#define mod             1000000007
#define ll              long long
#define oo              (1<<30)
#define pb              push_back
#define PI              3.141592653589793
#define pi              (2*acos(0))
#define pp              pop_back
#define rev(a)          reverse(all(a));
#define SIZE(s)         ((int)s.size())
#define saja(a)         sort(all(a))
#define sqr(a)          ((a)*(a))
#define SZ              50005
#define V(a)            vector<(a)>

using namespace std;


class BichromePainting {
public:

	string isThatPossible(vector <string> board, int k) {
		int n = board.size(), ager=0;
		bool col[n+2][n+2];
		clr(col,false);
		// int total = n*n;
		// cout<<"------------------------------"<<endl;
		// for (int i = 0; i < n; ++i)
		// {
		// 	cout<<board[i]<<endl;
		// }
		// cout<<"------------------------------"<<endl;
		while(1)
		{
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{	
					// if(col[i][j]) continue;
					bool flag = true;
					char pre = '#';
					for (int l = 0; l < k; ++l)
					{
						for (int m = 0; m < k; ++m)
						{
							if(l+i>=n || m+j>=n||(pre!='#'&&pre!=board[l+i][m+j] && !col[l+i][m+j]))
							{
								flag = false;
								break;
							}
							if(!col[l+i][m+j]) pre = board[l+i][m+j];
						}
						if(!flag) break;
					}
					if(flag)
					{
						for (int l = 0; l < k; ++l)
						{
							for (int m = 0; m < k; ++m)
							{
								col[l+i][m+j]=true;
							}
							if(!flag) break;
						}
					}
				}
			}
			int now = 0;
			char thik ='#';
			bool hoise=true;
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					if(col[i][j]) now++;
					else if(thik=='#') thik = board[i][j];
					else if(thik!=board[i][j]) hoise = false;
				}
			}
			if(hoise) return "Possible";
			// cout<<"KK: "<<now<<" "<<ager<<" "<<total<<endl;

			// cout<<"------------------------------"<<endl;
			// for (int i = 0; i < n; ++i)
			// {
			// 	for (int j = 0; j < n; ++j)
			// 	{
			// 		if(col[i][j]) cout<<"?";
			// 		else cout<<board[i][j];
			// 	}
			// 	cout<<endl;
			// }
			// cout<<"------------------------------"<<endl;

			if(now<=ager) break;
			
			ager = now;
		}	
		return "Impossible";
	}
	
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit-pf 2.3.0
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, int p1, bool hasAnswer, string p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << p1;
	cout << "]" << endl;
	BichromePainting *obj;
	string answer;
	obj = new BichromePainting();
	clock_t startTime = clock();
	answer = obj->isThatPossible(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p2 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p2;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	bool disabled;
	bool tests_disabled;
	all_right = true;
	tests_disabled = false;
	
	vector <string> p0;
	int p1;
	string p2;
	
	// ----- test 0 -----
	disabled = false;
	p0 = {"BBBW","BWWW","BWWW","WWWW"};
	p1 = 3;
	p2 = "Possible";
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = {"BW","WB"};
	p1 = 2;
	p2 = "Impossible";
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {"BWBWBB","WBWBBB","BWBWBB","WBWBBB","BBBBBB","BBBBBB"};
	p1 = 2;
	p2 = "Possible";
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {"BWBWBB","WBWBWB","BWBWBB","WBWBWB","BWBWBB","BBBBBB"};
	p1 = 2;
	p2 = "Impossible";
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = {"BWBWBB","WBWBWB","BWBWBB","WBWBWB","BWBWBB","BBBBBB"};
	p1 = 1;
	p2 = "Possible";
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 5 -----
	disabled = false;
	p0 = {"BB","BB"};
	p1 = 2;
	p2 = "Possible";
	all_right = (disabled || KawigiEdit_RunTest(5, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	// ----- test 6 -----
	disabled = false;
	p0 = {"WBWBBBWBBWWBBBBWB", "BWWWBBWBWBWWBWBWB", "BBBBBBWBWBBWBBBBW", "WBBWBWBWWWBBBWBBB", "BWWBBBBBWBBWBBWWB", "BBBWBBBBBWBBWBBWW", "BWBWBBWBWBWBWBBWB", "BBWBWBWBBWBBWWBWW", "BBBWWWWWBWBWWBWBB", "WBBBWBBBBWBBWBWBB", "WBBWBBBWBBBWBWWWB", "BWBBBBWBBBWBBWWWW", "WWBWWWWWBBWWWBBBW", "BWWBWBBWBWBBWWWBB", "BBWWBBBWWWWBWBWWW", "BWBBBBBBWWWBWBWWB", "BBWWWBWBBBWWWWBWB"};
	p1 = 2;
	p2 = "Possible";
	all_right = (disabled || KawigiEdit_RunTest(6, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	if (all_right) {
		if (tests_disabled) {
			cout << "You're a stud (but some test cases were disabled)!" << endl;
		} else {
			cout << "You're a stud (at least on given cases)!" << endl;
		}
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// PROBLEM STATEMENT
// We have a square board divided into a grid of unit square cells.
// Initially each cell is white.
// You are given a vector <string> board that describes the desired final state.
// In the final state each cell is either white ('W') or black ('B').
// 
// 
// You are also given an int k.
// The only change you can make to the board looks as follows:
// You may select any square of k by k cells and repaint all of them using the same color: either black or white.
// Later changes to the board may overlap previous ones.
// 
// 
// Return "Possible" if we can obtain the desired final state.
// Otherwise, return "Impossible".
// 
// DEFINITION
// Class:BichromePainting
// Method:isThatPossible
// Parameters:vector <string>, int
// Returns:string
// Method signature:string isThatPossible(vector <string> board, int k)
// 
// 
// CONSTRAINTS
// -n will be between 1 and 20, inclusive.
// -k will be between 1 and n, inclusive.
// -board will contain exactly n elements.
// -Each element in board will contain exactly n characters.
// -Each character in board will be 'W' or 'B'.
// 
// 
// EXAMPLES
// 
// 0)
// {"BBBW",
//  "BWWW",
//  "BWWW",
//  "WWWW"}
// 3
// 
// Returns: "Possible"
// 
// We can reach the desired state by doing two changes.
// First we paint the 3x3 square in the top left corner black:
// 
// BBBW
// BBBW
// BBBW
// WWWW
// 
// Then we paint the 3x3 square in the bottom right corner white.
// 
// 1)
// {"BW",
//  "WB"}
// 
// 2
// 
// Returns: "Impossible"
// 
// We can get only an all-white board and an all-black board.
// 
// 2)
// {"BWBWBB",
//  "WBWBBB",
//  "BWBWBB",
//  "WBWBBB",
//  "BBBBBB",
//  "BBBBBB"}
// 
// 2
// 
// Returns: "Possible"
// 
// 
// 
// 3)
// {"BWBWBB",
//  "WBWBWB",
//  "BWBWBB",
//  "WBWBWB",
//  "BWBWBB",
//  "BBBBBB"}
// 
// 2
// 
// Returns: "Impossible"
// 
// 
// 
// 4)
// {"BWBWBB",
//  "WBWBWB",
//  "BWBWBB",
//  "WBWBWB",
//  "BWBWBB",
//  "BBBBBB"}
// 
// 1
// 
// Returns: "Possible"
// 
// 
// 
// 5)
// {"BB",
//  "BB"}
// 2
// 
// Returns: "Possible"
// 
// 
// 
// END KAWIGIEDIT TESTING
