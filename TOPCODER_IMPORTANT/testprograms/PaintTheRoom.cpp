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


class PaintTheRoom {
public:
	string canPaintEvenly(int R, int C, int K) {
		if(R%2==1&&C%2==1) return (K == 1)?"Paint":"Cannot paint";
		return "Paint";
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
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, bool hasAnswer, string p3) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2;
	cout << "]" << endl;
	PaintTheRoom *obj;
	string answer;
	obj = new PaintTheRoom();
	clock_t startTime = clock();
	answer = obj->canPaintEvenly(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p3 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p3;
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

	int p0;
	int p1;
	int p2;
	string p3;

	// ----- test 0 -----
	disabled = false;
	p0 = 1;
	p1 = 1;
	p2 = 1;
	p3 = "Paint";
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 1 -----
	disabled = false;
	p0 = 1;
	p1 = 1;
	p2 = 2;
	p3 = "Cannot paint";
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 2 -----
	disabled = false;
	p0 = 1;
	p1 = 2;
	p2 = 2;
	p3 = "Paint";
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 3 -----
	disabled = false;
	p0 = 2;
	p1 = 2;
	p2 = 3;
	p3 = "Paint";
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, p2, true, p3) ) && all_right;
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
// Little Liz stepped in a bucket of green paint. Now she leaves green footprints wherever she walks. Fortunately, her school just built a new room which is supposed to have a green floor. Making the best of the situation, her teacher told her to paint the room by walking on its floor.
//
//
// The floor is a grid of cells with R rows and C columns. Little Liz occupies a position in this grid. She can move up, down, left, or right. (She cannot move diagonally.) To ensure that each cell gets the appropriate amount of paint, Liz should visit each cell exactly K times. Liz visits a cell whenever she moves into it. Liz also visits a cell if she begins her walk on it. Liz can begin and end on any cell.
//
//
// If it is possible to paint the room in the required way, return "Paint". Otherwise, return "Cannot paint". (All quotes are for clarity only.)
//
// DEFINITION
// Class:PaintTheRoom
// Method:canPaintEvenly
// Parameters:int, int, int
// Returns:string
// Method signature:string canPaintEvenly(int R, int C, int K)
//
//
// CONSTRAINTS
// -R will be between 1 and 50, inclusive.
// -C will be between 1 and 50, inclusive.
// -K will be between 1 and 50, inclusive.
//
//
// EXAMPLES
//
// 0)
// 1
// 1
// 1
//
// Returns: "Paint"
//
// There is only one cell in this grid. By starting on the cell, Little Liz visits it once.
//
// 1)
// 1
// 1
// 2
//
// Returns: "Cannot paint"
//
// This is the same case as Example 0, but now the cell must be visited twice. This is impossible.
//
// 2)
// 1
// 2
// 2
//
// Returns: "Paint"
//
// There are two cells, and they are in the same row. One possible solution is to start on the left cell, then move right, then left, then right. This visits each cell twice, as required.
//
// 3)
// 2
// 2
// 3
//
// Returns: "Paint"
//
//
//
// END KAWIGIEDIT TESTING